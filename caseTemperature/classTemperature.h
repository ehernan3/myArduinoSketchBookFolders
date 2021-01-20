class Temperature {
  #include "classMovingAverage.h"
  // Members
  private:
  const uint8_t pin;
  float VCC_mV;// Actual voltage supplied to the TMP36 from the Arduino(measured with multimeter), mV
  // Generally, you should use "unsigned long" for variables that hold time
  // The value will quickly become too large for an int to store
  unsigned long previousMillis; // will store last time LED was updated
  int long interval;   // interval at which to update the sensor reading(milliseconds)
  MovingAverage filter; // Declaring a variable, filter, as an instance of the class
  
  public:
  int reading;
  float vPin;
  float tempC_current;
  float tempC_filtered;
    
  // Constructor
  public:
  Temperature(byte attachTo):
    // The colon syntax allows you to initialise things inside your class that themselves have constructors
    // which we will be doing later.
    pin(attachTo),
    filter(0.0) // Initialize the filter with zeros
    {
  }
  
  // Methods
  void setup(){
    VCC_mV = 4900;
    previousMillis = 0;
    interval = 1000;
  }
  void loop(){
    // Build a timer that determines when to update the sensor reading
  /// without blocking the rest of the program with a delay().

  unsigned long currentMillis = millis(); // variable local to loop
  
  // If the following conditional is not met, nothing happens here, BUT
  // the rest of the loop will finish.
  if (currentMillis - previousMillis >= interval) {
    // If the conditions is met, perform these actions

    // save the last time you updated the sensor reading
    previousMillis = currentMillis;
    
    // Read the pin value from the temperature sensor
    reading = analogRead(pin);
    vPin = (reading) * (VCC_mV/1024);
    // Subtract the offset(mV) and divide by the slope(mV) to convert into degC
    tempC_current = (vPin - 500) / 10.0;
    
    // Update the filtered value
    //tempC_filtered = filter.Update((vPin - 500) / 10.0);
    } // end of the If statement
    } // end of the loop
};
