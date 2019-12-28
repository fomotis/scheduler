#include <string>
#include <ctime>


class Scheduler {
  
  //attributes
  int work_time; //the time period for the system to stay on in hours or minutes
  char action; // action to take options could be; sleep, logoff, restart, shutdown
  char time_format; //format in which work_time was given. Must be in hour or minutes.

public:
  // Scheduler constructor here:
  Scheduler(int new_work_time, char new_action, char time_format);
  
  // Add a destructor here:
  ~Scheduler();
  
  // method declarations here
  void action_taken(int wtime_secs, char action);
  time_t time_in_secs();
  int work_time_secs(int work_time, char time_format);
  
};