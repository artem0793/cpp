
/**
 * @file
 */

class Event {
  
  protected:
    String _name;
    TargetData *_data;

  public:
    Event(String name) {
      this->_name = name;
    }

    String getName() {
      return this->_name;
    }

    void setTarget(TargetData *data) {
      this->_data = data;
    }

    TargetData* getTarget() {
      return this->_data;
    }

};
