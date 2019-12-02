#include <string>


class Scheduler {
  
  //attributes
  std::string work_time; //check for date time type
  std::string action; // action to take options could be; sleep, logout, restart, shutdown

public:
  // Scheduler constructor here:
  Scheduler(std::string new_work_time, std::string new_action);
  
  // Add a destructor here:
  ~Scheduler();
  
  // method declarations here
  
  
};