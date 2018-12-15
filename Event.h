
/**
 * @file
 */

class Event {
  
  protected:
    String _name;
    
  public:
    Event(String name) {
      this->_name = name;
    }

    String getName() {
      return this->_name;
    }

};
