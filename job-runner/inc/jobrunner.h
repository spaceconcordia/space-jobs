
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*
* AUTHORS : Space Concordia 2014, Shawn 
*
* TITLE : jobrunner.h 
*
* DESCRIPTION : Repetitively execute a provided script or binary for a given
*           period and duration
*
* <frequency (nano seconds)> <duration (mili seconds)> <script> [<args>...]
*----------------------------------------------------------------------------*/

/**
 * Validate the input frequency, ensuring it is:
 *  - above zero
 **/
int validateFrequency (long frequency);

/**
 * Validate the input duration, ensuring it is:
 *  - above zero
 **/
int validateDuration (long duration);

/**
 * Using waitpid check if the child process is still running before 
 * Watches the remaining time from the input duration
 * 
 **/
void fork_and_manage_child (const char * path, char ** args, long duration);

