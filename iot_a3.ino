#include <dht.h>
#define DHT11_PIN 7

dht DHT; //set dht11 - pin 7 as input

void setup () {
Serial.begin(9600);
pinMode(8, OUTPUT); //Set buzzer - pin 9 as an output 
pinMode(6,OUTPUT); //set switch 1 - pin 6 as output 
}

void loop () {
int chk = DHT.read11(DHT11_PIN);
while (Serial.available()>0) {//check if data is present in serial monitor 
String ch=Serial.readString();

//Serial.print(ch); 
if (ch=="blink") {

digitalWrite(13, HIGH); 
delay(1000); 
digitalWrite(13, LOW); 
delay(1000);

}

else if(ch=="buzz"){
tone(8, 1000); // Send
delay(3000); 
noTone(8); 
delay(1000);
}

else if(ch=="switch_on"){
digitalWrite(6,HIGH); //close the relay circuit
delay(1000); //wait for 3sec 
}

else if(ch=="switch_off"){
digitalWrite(6,LOW); //open the relay circuit 
delay(1000);
}

else if(ch=="temphumid"){
float h = DHT.humidity;
float t = DHT.temperature; //by default celsius
// Check if any reads failed and exit early (to try again). 
if (isnan(h) || isnan(t)) {
Serial.println("Failed to read from DHT sensor!");
}
else{
Serial.print("Humidity:");
Serial.print(h); 
Serial.print(" %\t"); 
Serial.print("Temperature: "); 
Serial.print(t); 
Serial.println(" *C ");

} } } }
