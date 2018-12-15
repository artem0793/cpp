
/**
 * @file
 * Index controller.
 */
 

/**
 * + Прогрессивная функция
 * + Менеджер событий
 * + Менеджер событий с кнопками
 */

#include "LogsAPI.h"
#include "TimeoutAPI.h"

//#include "OnceAPI.h" 
//#include "TimeoutAPI.h"
//#include "AnimateAPI.h"


void setup() {
  init_log_settings();


  SimpleCallback a = [](){
    log("XXX");  
  };
  
  set_timeout(a, 5000);
}

void loop() {
//  toggleTimeManager();
//  once(test, "qwe");

  time_manager_trigger();
  delay(50);
}
