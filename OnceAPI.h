
/**
 * @file
 * Provide possible run code once.
 */

typedef void (*OnceCallback)();

const unsigned int API_MAX_COUNT_ONCE_CALLBACKS = 4;

struct OnceCallbackStruct {
  String id;
  OnceCallback callback;
};

OnceCallbackStruct api_once_history[API_MAX_COUNT_ONCE_CALLBACKS];

unsigned int current_size = 0;

void once(OnceCallback callback, String id = "") {
  boolean allow = true;
  
  for (int i = 0; i < API_MAX_COUNT_ONCE_CALLBACKS; i++) {
    if (api_once_history[i].id == id && api_once_history[i].callback == callback) {
      allow = false;
    }
  }

  if (allow) {
    if (API_MAX_COUNT_ONCE_CALLBACKS > current_size) {
      callback();
      api_once_history[current_size].id = id;
      api_once_history[current_size].callback = callback;
      current_size++;  
    }
    else {
      set_error("E:MAX_ONCE_CALL");
    }
  }
}
