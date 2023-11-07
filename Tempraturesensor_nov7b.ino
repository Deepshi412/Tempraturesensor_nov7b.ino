// The TMP36's Vout pin is connected to A0 of Arduino 
#define analogPin A0 

// Connect ARef to 3.3V 
#define aref_voltage 3.3 

void setup() { 
// Begin serial communication at 9600 baud rate 
Serial.begin(9600); 

// Set the aref to something other than 5v 
analogReference(EXTERNAL); 
} 

void loop() { 
// The voltage output reading from the TMP36 sensor 
int sensorRead = analogRead(analogPin); 

// Convert that sensor reading into voltage 
float voltageOut = sensorRead * (aref_voltage / 1024.0); 

// The voltage is then converted to temperature in Celsius 
float tempInC = (voltageOut - 0.5) * 100; 

// Print the temperature in Celsius in serial monitor 
Serial.print("Temperature: "); 
Serial.print(tempInC); 
Serial.print("\xB0"); // prints the degree symbol 
Serial.print("C"); 
Serial.print("\n"); 

delay(2000); // time in milliseconds to wait for the next reading 
}
