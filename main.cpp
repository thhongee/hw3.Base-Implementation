#include <iostream>
#include <string>
using namespace std;

#include "esc.h"

// Wall Clock Time Measurement
#include <sys/time.h>

#include "System.h"

// TIMEVAL STRUCT IS Defined ctime
// use start_time and end_time variables to capture
// start of simulation and end of simulation
struct timeval start_time, end_time;

System *sys = NULL;

extern void esc_elaborate()
{
	sys = new System("sys", esc_argv(1), esc_argv(2));
}
extern void esc_cleanup()
{
	delete sys;
}

// int main(int argc, char *argv[])
int sc_main(int argc, char **argv)
{
	if ((argc < 3) || (argc > 4))
	{
		cout << "No arguments for the executable : " << argv[0] << endl;
		cout << "Usage : >" << argv[0] << " in_image_file_name out_image_file_name"
			 << endl;
		return 0;
	}

	esc_initialize(argc, argv);

	esc_elaborate();

	sc_start();

	esc_cleanup();

	std::cout << "Simulated time == " << sc_core::sc_time_stamp() << std::endl;

	return 0;
}
