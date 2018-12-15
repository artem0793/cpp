
/**
 * @file
 * Abstract Timeout class.
 */
 
class TimeoutCallbackBase: AbstractCallbackBase {
  
  protected:
    int unsigned _time = 0;
  
  public:
    /**
     * Main execute callback.
     */
    void execute() {
       this->callback();
       
       this->remove();
    }
    /**
     * Set expired time.
     * 
     * @param timer
     *   Timeout time.
     */
    void setTime(int unsigned timer) {
      this->_time = timer + millis();
    }
    
    /**
     * Check to expire this callback.
     * 
     * @param time
     *   current time for compare.
     */
    bool isExpired(int unsigned time) {
      return this->_time <= time;
    }

    /**
     * Remove this timeout.
     */
    void remove() {
       delete this;
    }
    
};
