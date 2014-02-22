#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <signal.h>
#include <time.h>

// Create a new interval timer
// Returns the ID of the new timer
//
// We can choose to use a signal handler when the timer expires in the future
// We would register to the signal handler by passing a function pointer to this function
timer_t timer_get();

// Arms or disarms the timer specified by timerid
// The timer will expire at the given timeout value
// Entering a timeout of 0 will disarm the timer
// The function resets the time when it is called to the timeout value
void timer_start(timer_t * timerid, time_t timeout_s, time_t timeout_ms);

// Returns true if the timer has expired
bool timer_complete(timer_t * timer);
