#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>

// spaceconcordia
#include <timer.h>


// This function forks a new subprocess, in which it runs the program `path`
// with arguments `args` (both according to the format expected by `execvp`.
//
// The function then sleeps for `duration` nanoseconds.
//
// After waking up from sleep, the function checks the status of the subprocess.
// If it has not exited or been killed, this function kills it.
//
// The function then returns.
void fork_and_manage_child(const char * path, char ** args, long duration){

   pid_t pid;

   if(! (pid = fork())){
      execvp(path, args);
   }else{

      struct timespec requested;
      struct timespec remainder;

      requested.tv_sec  = duration / 1000000000L;
      requested.tv_nsec = duration % 1000000000L;

      while(nanosleep(&requested, &remainder)){
         requested.tv_sec  = remainder.tv_sec;
         requested.tv_nsec = remainder.tv_nsec;
      }

      int status;
      pid_t val;

      val = waitpid(pid, &status, WNOHANG);
         
      if( ! ( val > 0 && (WIFEXITED(status) || WIFSIGNALED(status)) )   ){

         if(val == -1){
            fprintf(stderr, "Error while waitpid'ing: %s.\n", strerror(errno));
            // TODO - shakespeare log that shit
         }
         
         if(kill(pid, SIGKILL)){
            fprintf(stderr, "Error while killing: %s.\n", strerror(errno));
            // TODO - shakespeare log that shit
         }

         // TODO - test this.
         val = wait(pid, &status, WNOHANG); // the point of this is to ensure that we don't create zombies
                                            // when killing misbehaving child processes
         if( ! ( val > 0 && (WIFEXITED(status) || WIFSIGNALED(status)) )   ){
            fprintf(stderr, "Child doesn't seem to have been killed... maybe we didn't wait long enough?\n");
         }
      }
   }
}

int main(int argc, const char *argv[])
{
   
   if(argc < 4){
      fprintf(stderr, "Usage: %s <period (ns)> <duration (ms)> <script> [<args>...]\n", argv[0]);
      return -1;
   }

   long period         = atol(argv[1]);
   // TODO - validate ??
   
   long duration       = atol(argv[2]);
   // TODO - validate ??

   // ////////////////////////////////////////////////////////////////////////
   // Set up arguments for exec:
   //
   // The path is always the 3th argument
   const char * path = argv[3];
   // All of the rest of the arguments are arguments for the job. The path of
   // the job should also be passed to the job as argument zero.
   char ** args = (char **) malloc(sizeof(char*) * (argc-2));
   
   // Copy the remaining args into an array of strings. Doing it this way because
   // they're const and need to be non-const. Maybe there's a better way though...
   for(int i = 0; i < (argc-3); ++i){
      args[i] = strcpy(
         (char*)malloc(sizeof(char) * (strlen(argv[i + 3]) + 1)),
         argv[i + 3]);
   }
   // arg list must be null-terminated for execvp
   args[argc-3] = NULL;

   //
   // ////////////////////////////////////////////////////////////////////////


   // Start a timer to track the total duration, as it's the most accurate way to do so I think
   timer_t timer = timer_get();
   timer_start(&timer, duration/1000, duration%1000);

   // just keep forkin
   while(!timer_complete(&timer)){
      fork_and_manage_child(path, args, period);
   }
   
   
   return 0;
}
