
/**
 * @file
 */

class TimeoutManager {

  protected:
    bool _free[MAX_SIZE_OF_TIMEOUT_QUEUE];
    /**
     * Queue.
     */
    Timeout * queue[MAX_SIZE_OF_TIMEOUT_QUEUE];

  private:
    /**
     * Hidden constructor.
     */
    TimeoutManager() {
      for (int i = 0; i < MAX_SIZE_OF_TIMEOUT_QUEUE; i++) {
         this->_free[i] = true;
      }
    }
    
    /**
     * Hidden destructor.
     */
    ~TimeoutManager() {}
    
    /**
     * Find free plase in array.
     */
    int getFreeQueueIndex() {
      for (int unsigned index = 0; index < MAX_SIZE_OF_TIMEOUT_QUEUE; index++) {
        if (this->_free[index] == true) {
          return index;  
        }
      }
      
      return NO_FREE_INDEX;
    }
        
  public:

    /**
     * Instance of OSystem.
     */
    static TimeoutManager & get() {
      static TimeoutManager instance;

      return instance;
    }
    
    /**
     * Add new timeout to queue.
     */
    int setTimeout(Timeout * timeout, int unsigned time) {
      int index = this->getFreeQueueIndex();      
      if (index != NO_FREE_INDEX) {
        timeout->expireTime = micros() + time;  
        this->queue[index] = timeout;
        this->_free[index] = false;
      }

      return index;
    }

    /**
     * Clear timeout by index.
     */
    void clearTimeout(int index) {
      if (this->queue[index] != NULL) {
        delete &(this->queue[index]);
        this->_free[index] = true;
      }
    }

    /**
     * Check all queue.
     */
    void triggerQueue() {
      int unsigned time = micros();

      for (int unsigned index = 0; index < MAX_SIZE_OF_TIMEOUT_QUEUE; index++) {      
        if (this->_free[index] == false && this->queue[index]->expireTime <= time) {
          this->queue[index]->execute();
          delete &(this->queue[index]);
          this->_free[index] = true;
        }
      }
    }

};
