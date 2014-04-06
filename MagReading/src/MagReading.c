#include <vector>
#include <signal.h>
#include <sys/wait.h>

int main()
{
char system_command[300];
double x=0,y=0,z=0,range=0,scale=0;


	x = sprintf(system_command,cat /sys/bus/i2c/devices/1-001e/iio\:device2/in_magn_x_raw)
	y = sprintf(system_command,cat /sys/bus/i2c/devices/1-001e/iio\:device2/in_magn_y_raw)
	z = sprintf(system_command,cat /sys/bus/i2c/devices/1-001e/iio\:device2/in_magn_z_raw)
	range = sprintf(system_command,cat /sys/bus/i2c/devices/1-001e/iio\:device2/in_magn_range)
	scale = sprintf(system_command,cat /sys/bus/i2c/devices/1-001e/iio\:device2/in_magn_scale)


}
