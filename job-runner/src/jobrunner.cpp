#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>

#include "shakespeare.h"
#include <SpaceDecl.h>

// spaceconcordia
#include <timer.h>

#define processName "Job-Runner"
#define ERRORBUFFERSIZE 190
#define LOGPATH "/tmp/job-runner"

// This function forks a new subprocess, in which it runs the program `path`
// with arguments `args` (both according to the format expected by `execvp`.
//
// The function then sleeps for `duration` nanoseconds.
//
// After waking up from sleep, the function checks the status of the subprocess.
// If it has not exited or been killed, this function kills it.
//
// The function then returns.

int validateFrequency (long frequency)
{
    if (frequency <= 0) {
        return 1;
    }
    return 0;
}

int validateDuration (long duration) 
{
    if (duration <= 0) {
        return 1;
    }
    return 0;
}

void fork_and_manage_child (const char * path, char ** args, long duration)
{
   pid_t pid;
   pid = fork();
   if ( pid != 0 ) 
   {
      execvp(path, args);
   } 
   else 
   {
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
         
      // WIFEXITED(status) -> true if child terminated normally
      // WIFSIGNALED(status) -> true if child process was terminated by a signal
      if( !( val > 0 && (WIFEXITED(status) || WIFSIGNALED(status)) ) )
      {  
         if (val == -1) 
         {  
            char errormsg[ERRORBUFFERSIZE] = {0}; // TODO test bounds
            snprintf(errormsg, ERRORBUFFERSIZE, "%s: waitpid(val)=>%d waitpid returned an error: %s.", path, val, strerror(errno));
            Shakespeare::log(Shakespeare::ERROR,processName,errormsg);
         }
         
         // try to kill the process
         if ( kill(pid, SIGKILL) ) {
            char killerrormsg[ERRORBUFFERSIZE] = {0};
            snprintf(killerrormsg, ERRORBUFFERSIZE, "%s: Error while killing: %s.", path, strerror(errno));
            Shakespeare::log(Shakespeare::ERROR,processName,killerrormsg);
         }

         // TODO - test this.
         // the point of this is to ensure that we don't create zombie
         // when killing misbehaving child processess
         val = waitpid(pid, &status, WNOHANG); 

         if ( !( val > 0 && (WIFEXITED(status) || WIFSIGNALED(status)) ) ) {
            char childstatuserr[ERRORBUFFERSIZE] = {0};
            snprintf(childstatuserr, ERRORBUFFERSIZE, "%s: Child still alive...wait longer", path);
            Shakespeare::log(Shakespeare::ERROR,processName,childstatuserr);
         }
      }
   }
}

int main(int argc, const char *argv[])
{
   if(argc < 4){
      fprintf(stderr, "Usage: %s <frequency (ns)> <duration (ms)> <script> [<args>...]\n", argv[0]);
      return -1;
   }

   long frequency = atol(argv[1]);
   if (validateFrequency(frequency) > 0) {
     Shakespeare::log(Shakespeare::ERROR,processName,"Invalid frequency, must be greater than zero");
   } // TODO - more validation
   
   long duration = atol(argv[2]);
   if (validateDuration (duration) > 0) {
     Shakespeare::log(Shakespeare::ERROR,processName,"Invalid duration, must be greater than zero");
   } // TODO - more validation

   // Set up arguments for exec: the path is always the 3th argument
   const char * path = argv[3];

   // All of the rest of the arguments are arguments for the job. The path of
   // the job should also be passed to the job as argument zero.
   // TODO replace with new
   char ** args = (char **) malloc(sizeof(char*) * (argc-2));
   
   // Copy the remaining args into an array of strings. Doing it this way because
   // they're const and need to be non-const. Maybe there's a better way though...
   // TODO do this without malloc
   for(int i = 0; i < (argc-3); ++i){
      args[i] = strcpy(
         (char*) malloc( sizeof(char) * (strlen (argv[i + 3]) + 1) ),
         argv[i + 3]);
   }

   // arg list must be null-terminated for execvp
   args[argc-3] = NULL;

   // Start a timer to track the total duration, as it's the most accurate way to do so I think
   timer_t timer = timer_get();
   timer_start(&timer, duration/1000, duration%1000);

   // just keep forkin
   while(!timer_complete(&timer)){
      fork_and_manage_child(path, args, frequency);
   }
   
   for(int i = 0; i < (argc-3); ++i) {
     free (args[i]);
   }
   free (args);

   return CS1_SUCCESS;
}
