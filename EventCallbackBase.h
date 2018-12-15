
/**
 * @file
 * Abstract Timeout class.
 */
 
class EventCallbackBase: AbstractCallbackBase {

  public:
    Event *event;
  
    /**
     * Main execute callback.
     */
    void execute() {
       this->callback();
    }

    /**
     * Remove this timeout.
     */
    void remove() {
       delete this;
    }
    
    /**
     * 
     */
    void setEvent(Event *_event) {
      this->event = _event;
    }
    
};
