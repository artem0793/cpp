
/**
 * @file
 * Index controller.
 */

/**
 * @TODO
 * * Стоп для анимейт
 * * Переименовать класс с таймаутом
 * * переименовать кнопку
 */

//#include "LogsAPI.h"
//#include "TimeoutAPI.h"
//#include "OnceAPI.h" 
//#include "AnimateAPI.h"
//#include "EventAPI.h"

#include "EventTarget.cpp"

template<typename TargetType>
class Event {
  
  public:
    
    String name;
    
    Event(String name) {
      this->name = name;
      
    }
    
    TargetType * target;

};

class EventManager {

  public:
  
    EventManager() {
      Serial.println("EventManager");
    }
  
    template<typename TYPE>
    void fire(TYPE * event) {
       Serial.println("fire");
       Serial.println(event->target->name);
       Serial.println(event->name);
    }

};


class Button: public EventManager {

  public:
    
    String name = "ButtonName";
    
    Button() {
      Serial.println("Button");
    }

};

// EventTarget менеджер событий
// initEvent
// addEventListener
// removeEventListener
// dispatchEvent(event)

void setup() {
  Serial.begin(9600);
  Serial.println("Старт");

  Button * btn = new Button;
  Event<Button> * event = new Event<Button>("change");
  event->target = btn;
  btn->fire(event);
  
}

void loop() {  
  delay(10000);
  Serial.println("10 сек");
}
