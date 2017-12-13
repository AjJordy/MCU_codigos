#include <MCP3008.h>
 
//define pin connections
#define CS_PIN    9
#define CLOCK_PIN 14
#define MOSI_PIN  13
#define MISO_PIN  10
 
MCP3008 adc(CLOCK_PIN, MOSI_PIN, MISO_PIN, CS_PIN);
 
void setup() 
{
 // open serial port
 Serial.begin(9600); 
}
 
void loop() 
{
 
 int val = adc.readADC(1); // read Channel 0 from MCP3008 ADC (pin 1)
 Serial.println(val);
 float tensao = map(val,0,1024,0,9000);
 tensao = tensao/1000; 
 Serial.println(tensao);
 delay(1000); 
}
