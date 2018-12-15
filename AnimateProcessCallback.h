
/**
 * @file
 * Animate process.
 */

class AnimateProcessCallback: public TimeoutCallbackBase {
  private:
    int unsigned _startTime;              // Time of begining of animation.
    AnimateDrawCallback _draw;            // Main draw callback.
    AnimateTimingCallback _timing;        // Type of animation.
    int unsigned _duration;               // Time of animation.
    int unsigned _stepTime;               // Min time of step.
    AnimateDoneCallback _finishCallback;  // Done callback.
      
  public:
    AnimateProcessCallback(
      int unsigned start_time,            // Time of begining of animation.
      AnimateDrawCallback draw,           // Main draw callback.
      AnimateTimingCallback timing,       // Type of animation.
      int unsigned duration,              // Time of animation.
      int unsigned step_time,             // Min time of step.
      AnimateDoneCallback finish_callback // Done callback.
    ) {
      this->_startTime = start_time;
      this->_draw = draw;
      this->_timing = timing;
      this->_duration = duration;
      this->_stepTime = step_time;
      this->_finishCallback = finish_callback;
    }
  protected:  
    void callback() {
      float diff = millis() - this->_startTime;
      float time_fraction = diff / this->_duration;
      
      if (time_fraction > 1) {
        time_fraction = 1;
      }
      
      float progress = this->_timing(time_fraction);
      
      this->_draw(progress);
      
      if (time_fraction < 1) {
        AnimateProcessCallback* callback = new AnimateProcessCallback(
          this->_startTime,
          this->_draw,
          this->_timing,
          this->_duration,
          this->_stepTime,
          this->_finishCallback
        );

        set_timeout_callback(callback, this->_stepTime);
      }
      
      if (time_fraction == 1) {
        this->_finishCallback();
      }
    }
};
