#include <iostream>
#include "scheduler.hpp"

int main() {
	
	Scheduler test(60, "logoff", "hours");
	int tt = test.work_time_secs();
	std::cout << "The time in seconds is " << tt << "\n";
}