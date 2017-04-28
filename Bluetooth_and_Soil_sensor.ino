#include <SoftwareSerial.h>                            // import the serial library

SoftwareSerial Soft(12, 10); // RX, TX

                                                   // Declarations 
/**************************************************************************************************************************************/
int sensorPin = 9;                              // select the input pin for the potentiometer
int ledpin = 13;                                 // select the pin for the LED
int sensorValue = 0;                           // variable to store the value coming from the sensor

int thrshold = 400;

                                         
int ledState = LOW;                  // ledState used to set the LED

/**************************************************************************************************************************************/


/**************************************************************************************************************************************/
void setup()
{
  
  // put your setup code here, to run once:
  Soft.begin(9600);
  Soft.println("Bluetooth On please wait....");

// declare the ledPin as an OUTPUT:
   Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  digitalWrite(ledpin, HIGH); 
  
}

/**************************************************************************************************************************************/


/**************************************************************************************************************************************/
void loop() {

  
 // put your main code here, to run repeatedly:
// read the value from the sensor:


  sensorValue = analogRead(sensorPin);    
  delay(1000);          
  Serial.print("sensor = " );                       
  Serial.println(sensorValue); 

  
      if(sensorValue > thrshold) 
        {
                                                                             // Compare the current value to that of the thresh hold value    
      
             Soft.println("1" );  
    
                     if (ledState == LOW)                               // if the LED is off turn it on and vice-versa:
                        ledState = HIGH;
                    
    
     digitalWrite(ledpin, ledState);                           // set the LED with the ledState of the variable:
  }

  else 
                                                       // Compare the current value to that of the thresh hold value
    
      
      Soft.println("0" );  
    
     ledState = LOW;

    
      digitalWrite(ledpin, ledState); // set the LED with the ledState of the variable:
}

/**************************************************************************************************************************************/
