
/**
 * @file
 * Index controller.
 */
 
const unsigned int FPS = 10;

/**
 * + Прогрессивная функция
 * + Менеджер событий
 * + Менеджер событий с кнопками
 */

#include "LogsAPI.h"
#include "TimeoutAPI.h"
#include "OnceAPI.h" 
#include "AnimateAPI.h"


void setup() {
  init_log_settings();

  animate([](float p){
    log("LINE: " + String(p));
  }, api_animate_line, 10000, 1000);

  animate([](float p){
    log("SQ: " + String(p));
  }, api_animate_sq, 10000, 1000);
}

void loop() {
  time_manager_trigger();
  
  delay(FPS);
}
