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
   const char * path = argv[3];
   char ** args = (char **) malloc(sizeof(char*) * (argc-2));
   
   for(int i = 0; i < (argc-3); ++i){
      args[i] = strcpy(
         (char*)malloc(sizeof(char) * (strlen(argv[i + 3]) + 1)),
         argv[i + 3]);
   }
   args[argc-3] = NULL;
   //
   // ////////////////////////////////////////////////////////////////////////
   static timer_t timer = timer_get();
   timer_start(&timer, duration/1000, duration%1000);

   while(!timer_complete(&timer)){
      fork_and_manage_child(path, args, period);
   }
   
   
   return 0;
}
