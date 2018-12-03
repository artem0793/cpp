
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
#include "OnceAPI.h" 
#include "TimeoutAPI.h"
#include "AnimateAPI.h"

void setup() {
  initLogSettings();
}

void test2(float progress) {
   log("-" + String(progress));
}

void test () {

  animate(test2);
  
  log("ЖОПА");
}

void loop() {
  toggleTimeManager();
  once(test, "qwe");
}
