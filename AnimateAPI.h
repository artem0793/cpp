
/**
 * @file
 * Provide animate functionality.
 */

/**
 * @TODO Сделать остальные 2 функции.
 */

const unsigned int API_ANIMATE_LINE = 1;

typedef float (*AnimateTimingCallback)(float);
typedef void (*AnimateDrawCallback)(float);
typedef void (*AnimateDoneCallback)();

void api_animate_default_done_callback() {
  
}

float api_animate_line(float time_fraction) {
  return time_fraction;
}

void api_animation_frame(
  unsigned int start,           // Time of begining of animation.
  AnimateDrawCallback draw,     // Main draw callback.
  AnimateTimingCallback timing, // Type of animation.
  unsigned int duration,        // Time of animation.
  unsigned int step_time,       // Min time of step.
  AnimateDoneCallback finish_callback // Done callback.
) {
  float diff = millis() - start;
  float time_fraction = diff / duration;

  if (time_fraction > 1) {
    time_fraction = 1;
  }
  
  float progress = timing(time_fraction);
  
  draw(progress);

  if (time_fraction < 1) { 
//    void A() { 
//        Serial.println("I am function A\n"); 
//    };
      
    // callback function 
//    void B(void (*ptr)()) { 
//        (*ptr) (); // callback to A 
//    }; 
//    
//    void (*ptr)() = &A; 
      
    // calling function B and passing 
    // address of the function A as argument 
//    B(ptr); 
    
//    TimeoutCallback a = [&start]() -> void {
//      Serial.println(String(start));
//    };
//
//    a();
    
//    set_timeout([&start](){
//      
//      Serial.println(String(start));
//
//    }, step_time);
  }

  if (time_fraction == 1) {
    finish_callback();
  }
}

void animate(
  AnimateDrawCallback draw, // Main draw callback.
  AnimateTimingCallback timing = api_animate_line, // Type of animation.
  unsigned int duration = 300, // Time of animation.
  unsigned int step_time = 50, // Min time of step.
  AnimateDoneCallback finish_callback = api_animate_default_done_callback // Done callback.
) {
    int unsigned start = millis();
  api_animation_frame(millis(), draw, timing, duration, step_time, finish_callback);
}
