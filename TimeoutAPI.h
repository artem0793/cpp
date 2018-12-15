
/**
 * @file
 * API - Provides setTimeout functionality.
 */

#include "AbstractCallbackBase.h"
#include "TimeoutCallbackBase.h"
#include "SimpleTimeoutCallback.h"
#include "TimeoutManager.h"

/**
 * Add new callback object to queue.
 */
int unsigned set_timeout_callback(TimeoutCallbackBase *callback, int unsigned timer = 0) {
  callback->setTime(timer);
  
  return TimeoutManager::getInstance().add(callback);
}

/**
 * Add new callback to queue.
 */
int unsigned set_timeout(SimpleCallback fn, int unsigned timer = 0) {
  SimpleTimeoutCallback* callback = new SimpleTimeoutCallback;

  callback->setCallback(fn);
  callback->setTime(timer);
    
  return TimeoutManager::getInstance().add(callback);
}

/**
 * Clear callback from queue.
 */
void clear_timeout(int unsigned index) {
  TimeoutManager::getInstance().removeAt(index);
}

/**
 * Trigger timeouts queue.
 */
void time_manager_trigger() {
  TimeoutManager::getInstance().trigger(millis());
}
