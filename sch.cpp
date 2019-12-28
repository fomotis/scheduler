#include "scheduler.hpp"
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 

// Scheduler definition here:
Scheduler::Scheduler(int new_work_time, char new_action, char new_time_format)
  : work_time(new_work_time), action(new_action), time_format(new_time_format) {}
  
// add the Scheduler destructor here:
Scheduler::~Scheduler(){
 
}

// Scheduler method definitions here

//time_in_secs method: return current system time in seconds
time_t Scheduler::time_in_secs() {
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
int Scheduler::work_time_secs(int work_time, char time_format) {
	
	int work_time_in_secs;
	if(time_format == 'h') {
		
		work_time_in_secs = work_time*3600;
		
	} else { 
	
		work_time_in_secs = work_time*60;
		
	}
	return work_time_in_secs;
}

//action method: shutsdown or log-off the system
void Scheduler::action_taken(int wtime_secs, char action) {
	
	//get the current time in seconds
	time_t current_time_secs = time_in_secs();
	
	//compute turn_off_time in seconds
	time_t turn_off_time = current_time_secs + wtime_secs;
	
	//continue to run a loop while current time is lesser than turn_off_time
	while(time_in_secs() < turn_off_time) {
		
		//time_t time_now = ;
		//if(time_now < turn_off_time) {
			if( (turn_off_time - time_in_secs()) % 10 == 0 ) {
				std::cout << "Your system will perform action in " << turn_off_time - time_in_secs() << " seconds" << "\n";
			}
			//continue;
		//} else {
			
		//	break;
		//} 
		
	}
	
	//perform action
	if(action == 'l') {
		
		//logoff
		system("c:\\windows\\system32\\shutdown /l");
		
	} else if(action == 's') {
		
		//shutdown
		system("c:\\windows\\system32\\shutdown /s");
		
	} else if(action == 'r') {
		
		//restart
		system("c:\\windows\\system32\\shutdown /r");
		
	} else {
		
		system("c:\\windows\\system32\\shutdown /i");
		
	}
	
}




































