#include <iostream>
#include "scheduler.hpp"

int main() {
	
	//ask user for the input time;
	int wtime;
	std::cout <<  "Please enter the hours you'd like to stay active: ";
	std::cin >> wtime;
	
	//ask for the time format supplied;
	std::cout <<  "time format, please?\n (h = hours) \n (m = minutes): \n";
	char wtime_format;
	std::cin >> wtime_format;
	
	//ask for the action to be taken;
	std::cout << "what action would you like? \n (l = logoff) \n (s = shutdown) \n (r = restart) \n (c = choose later): \n";
	char action_tobe_taken;
	std::cin >> action_tobe_taken;
	
	//main body starts here
	Scheduler test(wtime, action_tobe_taken, wtime_format);
	//get work time in seconds
	int tt = test.work_time_secs(wtime, wtime_format);
	
	//perform desired action
	test.action_taken(tt, action_tobe_taken);
	std::cout << "Goodbye!";
	//std::cout << "The action will happen in " << tt2 << "\n";
	//std::cout << "Time now in seconds" << test.time_in_secs() << "\n";
}