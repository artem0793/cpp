/**
 * @file
 * Log functionality.
 * 
 * Add initLogSettings() to setup callback;
 * and use set_error() to throw exceptions;
 */

const boolean API_LOG_ENABLE_SERIAL = true;

const unsigned int API_LOG_SERIAL_SPEED = 9600;

boolean api_log_init = false;

void initLogSettings() {
  if (API_LOG_ENABLE_SERIAL) {
    Serial.begin(API_LOG_SERIAL_SPEED);  
    api_log_init = true;
  }
}

void log_close() {
  if (api_log_init && API_LOG_ENABLE_SERIAL) {
    Serial.end();
  }
}

void log(String message)  {
  if (api_log_init && API_LOG_ENABLE_SERIAL) {
    Serial.println(message);  
  }
}

void set_error(String message) {
  log(message);
  
  while(true);
}