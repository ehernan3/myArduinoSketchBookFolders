void writeDisplay(){
  // Write to display
  display.clearDisplay();

  display.setTextSize(textSize);
  display.setTextColor(WHITE);
  
  display.setCursor(0, 0);
  display.print("reading = ");display.print(reading);
  display.print(",");display.print(readingMin);
  display.print(",");display.print(readingMax);
  
  display.setCursor(0, 8);
  display.print("vPin = ");display.print(vPin);
  display.print(",");display.print(vPinMin);
  display.print(",");display.print(vPinMax);
  
  display.setCursor(0, 16);
  display.print("tempC          = ");display.print(tempC,1);
  //display.print("tempC_filtered = ");display.print(tempC_filtered,1);
  //display.print(",");display.print(tempC_min);
  //display.print(",");display.print(tempC_max);
  
  display.setCursor(0, 24);
  display.print("tempC_filtered = ");display.print(tempC_filtered,1);
  //display.print("tempF_filtered = ");display.print(tempF_filtered,1);

  display.display();
}
