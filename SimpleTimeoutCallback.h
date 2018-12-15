/**
 * @file
 * 
 * Simple callback without any context.
 */

typedef void (*SimpleCallback)();

class SimpleTimeoutCallback: public TimeoutCallbackBase {
  
  private:
    SimpleCallback _callback = [](){};
  
  public:
    void setCallback(SimpleCallback callback) {
      this->_callback = callback;
    }

    void callback() {
      this->_callback();
    }
    
};
