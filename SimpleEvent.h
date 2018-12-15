
/**
 * @file
 * 
 */

typedef void (*SimpleEventCallback)(Event *event);

class SimpleEvent: public EventCallbackBase {
  
  private:
    SimpleEventCallback _callback;
  
  public:
    void setCallback(SimpleEventCallback callback) {
      this->_callback = callback;
    }

    void callback() {
      this->_callback(this->event);
    }
    
};
