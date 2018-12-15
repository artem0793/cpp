
/**
 * @file
 * Provide animate functionality.
 */

const unsigned int API_ANIMATE_LINE = 1;

typedef float (*AnimateTimingCallback)(float);
typedef void (*AnimateDrawCallback)(float);
typedef void (*AnimateDoneCallback)();

#include "AnimateProcessCallback.h"

void api_animate_default_done_callback() {
  
}

float api_animate_line(float time_fraction) {
  return time_fraction;
}

float api_animate_sq(float time_fraction) {
  return sq(time_fraction);
}

void animate(
  AnimateDrawCallback draw,
  AnimateTimingCallback timing = api_animate_line,
  unsigned int duration = 300,
  unsigned int step_time = 50,
  AnimateDoneCallback finish_callback = api_animate_default_done_callback
) {
  (new AnimateProcessCallback(
    millis(),
    draw,
    timing,
    duration,
    step_time,
    finish_callback
  ))->execute();
}
