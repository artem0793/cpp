
/**
 * @file
 * API - Provides setTimeout functionality.
 * 
 * How to use:
 * Need to add `toggleTimeManager();` to main loop.
 * 
 * And you can use:
 * int id = set_timeout(callback, 1000);
 * clear_timeout(id);
 */

const unsigned int MAX_SET_TIMEOUT_LIMIT = 4;

typedef void (*TimeoutCallback)();

class Timeout {
  
  private:
    
    TimeoutCallback _callback;
    
    int _expire;
    
  public:
    Timeout() {
      this->expired();
    }
    
    void create(TimeoutCallback callback, unsigned int timer) {
      this->_callback = callback;
      this->_expire = timer + millis();  
    }

    boolean isEmpty() {
      return this->_expire < 0;
    }

    boolean check(unsigned int timestump) {
      if (this->_expire <= timestump) {
        this->_expire = -1;
        this->_callback();
      }
    }

    void expired() {
       this->_expire = -1;
    }
};

class TimeoutManager {
  
  private:
    TimeoutManager()  {}
    
    int findEmpty() {
      for (unsigned int i = 0; i < MAX_SET_TIMEOUT_LIMIT; i++) {
        if (this->_queue[i].isEmpty()) {
          return i;
        }
      }
      
      return -1;
    }
    
    ~TimeoutManager() {}
    
    TimeoutManager(TimeoutManager const&);
    
    TimeoutManager& operator= (TimeoutManager const&);
    
    Timeout _queue[MAX_SET_TIMEOUT_LIMIT];
    
  public:
    static TimeoutManager& Instance() {
        static TimeoutManager instance;
        
        return instance;
    }

    void loop(unsigned int timestamp) {
      for (unsigned int i = 0; i < MAX_SET_TIMEOUT_LIMIT; i++) {
        if (!this->_queue[i].isEmpty()) {
          this->_queue[i].check(timestamp);
        }
      }
    }

    unsigned int add(TimeoutCallback callback, int timer) {
       int index = this->findEmpty();
       
       if (index >= 0) {
         this->_queue[index].create(callback, timer);
       }
       else {
         set_error("E:TIMEOUT_LIMIT");
       }

       return index;
    }

    void expiredAt(unsigned int index) {
      if (MAX_SET_TIMEOUT_LIMIT > index) {
        this->_queue[index].expired();
      }
      else {
         set_error("E:WRONG_EXP_KEY");
      }
    }

};

unsigned int set_timeout(TimeoutCallback callback, unsigned int timer) {
  return TimeoutManager::Instance().add(callback, timer);
}

void clear_timeout(unsigned int index) {
  return TimeoutManager::Instance().expiredAt(index);
}

void toggleTimeManager() {
  TimeoutManager::Instance().loop(millis());
}
