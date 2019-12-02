#include "scheduler.hpp"
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 

// Scheduler definition here:
Scheduler::Scheduler(std::string new_work_time, std::string new_action)
  : work_time(new_work_time), action(new_action) {}
  
// add the Scheduler destructor here:
Scheduler::Scheduler(){
  std::cout << "Goodbye " + "Drama!\n";
}

// Scheduler method definitions here