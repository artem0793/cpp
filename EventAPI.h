
/**
 * @file
 * 
 */
 
#include "Event.h"
#include "EventCallbackBase.h"
#include "SimpleEvent.h"
#include "EventStructure.h"
#include "EventManager.h"

SimpleEvent* simple_event_callback(SimpleEventCallback fn) {
  SimpleEvent *callback = new SimpleEvent();
  
  callback->setCallback(fn);
  
  return callback;
}
