
/**
 * @file
 * 
 */

const int unsigned MAX_SIZE_OF_EVENT_LISTENERS = 10;

class EventManager {
  protected:
    bool _free[MAX_SIZE_OF_EVENT_LISTENERS] = { false };
    
    EventStructure _listeners[MAX_SIZE_OF_EVENT_LISTENERS];

    int getFreeIndex() {
      for (int unsigned index = 0; index < MAX_SIZE_OF_EVENT_LISTENERS; index++) {
        if (this->_free[index] == false) {
          return index;  
        }
      }
      
      return NO_FREE_INDEX;
    }
    
  public:
    
    /**
     * 
     */
    void on(String event_name, EventCallbackBase *callback) {
      int index = this->getFreeIndex();
      
      if (index != NO_FREE_INDEX) {
        this->_listeners[index] = { event_name, callback };
        this->_free[index] = true;
      }
      else {
       set_error("Event API: NO free value in index. (" + event_name + ")"); 
      }
    }
    
    /**
     * 
     */
    void off(String event_name = "all") {
      for (int unsigned index = 0; index < MAX_SIZE_OF_EVENT_LISTENERS; index++) {
        if (this->_free[index] && (event_name == "all" || event_name == this->_listeners[index].eventName)) {
          this->_listeners[index].callback->remove();
          this->_free[index] = false;
        } 
      }
    }
    
    /**
     * 
     */
    void fire(String event_name, Event *event) {
      for (int unsigned index = 0; index < MAX_SIZE_OF_EVENT_LISTENERS; index++) {
        if (this->_free[index] && event_name == this->_listeners[index].eventName) {
          this->_listeners[index].callback->setEvent(event);
          this->_listeners[index].callback->execute();
          this->_free[index] = false;
        }
      }
    }
    
};
