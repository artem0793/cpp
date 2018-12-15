/**
 * @file
 * Timeout manager service.
 */

const unsigned int MAX_SIZE_OF_TIMEOUT_QUEUE = 4;

const int NO_FREE_INDEX = -1;

class TimeoutManager {
  
  protected:

    bool _free[MAX_SIZE_OF_TIMEOUT_QUEUE] = { false };
    
    TimeoutCallbackBase *_queue[MAX_SIZE_OF_TIMEOUT_QUEUE];

    int getFreeIndex() {
      for (int unsigned index = 0; index < MAX_SIZE_OF_TIMEOUT_QUEUE; index++) {
        if (this->_free[index] == false) {
          return index;  
        }
      }
      
      return NO_FREE_INDEX;
    }
  
  private:
    // Hidden.
    TimeoutManager(TimeoutManager const&);
    // Hidden.
    TimeoutManager& operator= (TimeoutManager const&);
    // Hidden.
    TimeoutManager()  {
      
    }
    // Hidden.
    ~TimeoutManager() {
      
    }

  public:
    /**  
     * Instance of this service.
     */
    static TimeoutManager& getInstance() {
      static TimeoutManager instance;
        
      return instance;
    }
    
    /**
     * Add new callback object.
     */
    int unsigned add(TimeoutCallbackBase *timeout) {
      int index = this->getFreeIndex();
      
      if (index != NO_FREE_INDEX) {
        this->_queue[index] = timeout;
        this->_free[index] = true;
        
        return index;
      }
      
      set_error("Timeout API: NO free value in index.");
      
      return NO_FREE_INDEX;
    }

    /**
     * Remove callback object by index.
     */
    void removeAt(int unsigned index) {
      if (this->_free[index]) {
        this->_queue[index]->remove();
        this->_free[index] = false;
      }
    }

    /**
     * Trigger all queue.
     */
    void trigger(int unsigned time = 0) {
      for (int unsigned index; index < MAX_SIZE_OF_TIMEOUT_QUEUE; index++) {
        if (this->_free[index] == true && this->_queue[index]->isExpired(time)) {
          this->_free[index] = false;
          this->_queue[index]->execute();
        }
      }
    }
    
};
