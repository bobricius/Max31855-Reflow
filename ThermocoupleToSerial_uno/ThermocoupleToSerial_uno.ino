/*******************************************************************************
* Thermocouple to serial for MAX31855 example 
* Version: 1.00
* Date: 26-12-2011
* Company: Rocket Scream Electronics
* Website: www.rocketscream.com
*
* This is an example of using the MAX31855 library for Arduino to read 
* temperature from a thermocouple and send the reading to serial interfacec. 
* Please check our wiki (www.rocketscream.com/wiki) for more information on 
* using this piece of library.
*
* This example code is licensed under Creative Commons Attribution-ShareAlike 
* 3.0 Unported License.
*
* Revision  Description
* ========  ===========
* 1.00      Initial public release.
*
*******************************************************************************/
// ***** INCLUDES *****
#include  <MAX31855.h>

// ***** PIN DEFINITIONS *****
const  unsigned  char thermocoupleSO = 12;
const  unsigned  char thermocoupleCS = 11;
const  unsigned  char thermocoupleCLK = 13;
int led = 3;
MAX31855  MAX31855(thermocoupleSO, thermocoupleCS, thermocoupleCLK);

void  setup()
{
  Serial.begin(57600);
    pinMode(led, OUTPUT);  
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(500);
}

void  loop()
{
  double  temperature;
  
  // Retrieve thermocouple temperature in Degree Celsius
  temperature = MAX31855.readThermocouple(CELSIUS);
  Serial.print("Thermocouple temperature: ");
  Serial.print(temperature);
  Serial.print(" Degree Celsius");
  
  // Retrieve cold junction temperature in Degree Celsius
  temperature = MAX31855.readJunction(CELSIUS);
  Serial.print("Junction temperature: ");
  Serial.print(temperature);
  Serial.println(" Degree Celsius");
  
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(500); 
}
