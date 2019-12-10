#include "scheduler.hpp"
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 

// Scheduler definition here:
Scheduler::Scheduler(int new_work_time, std::string new_action, std::string new_time_format)
  : work_time(new_work_time), action(new_action), time_format(new_time_format) {}
  
// add the Scheduler destructor here:
Scheduler::~Scheduler(){
 
}

// Scheduler method definitions here

//time_in_secs method: return current system time in sceond
time_t time_in_secs() {
	time_t time_all = time(0);
	//extract local time from current_time_all
	tm *ltm = localtime(&time_all);
	//extract the hour
	time_t hrs = 1 + ltm -> tm_hour;
	//extract the minutes
	time_t mins = 1 + ltm -> tm_min;
	//extract the seconds
	time_t secs = 1 + ltm -> tm_sec;
	//current time in seconds
	time_t time_secs = (hrs*3600) + (mins*60) + secs;
	return time_secs;
}

// convert work time to seconds
int work_time_secs(int work_time, std::string time_format){
	if(time_format == "hours") {
		
		int work_time_in_secs = work_time*3600;
		
	} else { 
	
		int work_time_in_secs = work_time*60;
		
	}
	return work_time_in_secs;
}

//action method: shutsdown or log-off the system
void action_taken() {
	
	//get work time in seconds
	int wtime_secs = work_time_secs();
	//get the current time in seconds
	time_t current_time_secs = time_in_secs();
	
	//compute turn_off_time in seconds
	time_t turn_off_time = current_time_secs + wtime_secs;
	
	//continue to run a loop while current time is lesser than turn_off_time
	while(true) {
		
		time_t time_now = time_in_secs();
		if(time_now < turn_off_time) {
			continue;
		} else if(time_now == turn_off_time && action == "logoff") {
			//logoff
			system("c:\\windows\\system32\\shutdown /l");
			break;
		} else if(time_now == turn_off_time && action == "shutdown") {
			//shutdown
			system("c:\\windows\\system32\\shutdown /s");
			break;
		} else if(time_now == turn_off_time && action == "restart") {
			//restart
			system("c:\\windows\\system32\\shutdown /r");
			break;
		}
		
	}
	
}




































