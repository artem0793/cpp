/**
 * @file
 * Abstract class.
 */
 
class AbstractCallbackBase {
  
  protected:
  
    /**
     * Abstract callback.
     */
    virtual void callback();
  
  public:
  
    /**
     * Abstract executer of this callback.
     */
    virtual void execute();
    
};
