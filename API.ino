
/**
 * @file
 * Index controller.
 */
 
const unsigned int FPS = 10;

#include "LogsAPI.h"
#include "TimeoutAPI.h"
#include "OnceAPI.h" 
#include "AnimateAPI.h"
#include "EventAPI.h"

void setup() {
  init_log_settings();
}

void loop() {
  time_manager_trigger();
  
  delay(FPS);
}
