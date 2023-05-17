#include <LiquidCrystal.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
String welcomeMessage = "Welcome To";
String welcomeMessage1 = "Engineers Home";

//Motor A connections 
int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 5;

//Sensor 
int irSensor = 6;
int gasSensorPin = 7; 

int buzzerPin = 8;
int fanMotorPin1 = 9;

//RGB 
int r = 11; 
int g = 12; 
int b = 13; 



void setup() {

  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(irSensor, INPUT);


  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);



 pinMode(buzzerPin, OUTPUT);

 pinMode(fanMotorPin1, OUTPUT);

  pinMode(gasSensorPin, INPUT);

  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  analogWrite(r,255);
  analogWrite(g,255);
  analogWrite(b,255);

    lcd.setCursor(3, 0);
    lcd.print(welcomeMessage);
    lcd.setCursor(1, 1);
    lcd.print(welcomeMessage1);
}

void loop() {

    static unsigned long previousGasReadTime = 0;
    unsigned long currentMillis = millis();

  char data = Serial.read();
  if(data =='H')  
  {
    analogWrite(r, 0);
    analogWrite(g, 0);
    analogWrite(b, 0);
  }
  else if (data == 'L'){
      analogWrite(r, 255);
      analogWrite(g, 255);
      analogWrite(b, 255);
  }

 else if (data == 'R'){
     analogWrite(r, 0);
     analogWrite(g, 255);
     analogWrite(b, 255);
  }
  else if (data == 'G'){
    analogWrite(r, 255);
    analogWrite(g, 0);
    analogWrite(b, 255);
  }
  else if (data == 'B'){
     analogWrite(r, 255);
     analogWrite(g, 255);
     analogWrite(b, 0);
  }
else if (data == 'Y'){
     analogWrite(r, 0);
     analogWrite(g, 0);
     analogWrite(b, 255);
   }
  else if (data == 'C'){
    analogWrite(r, 255);
     analogWrite(g, 0);
      analogWrite(b, 0);
  }

  else if (data == 'P'){
   analogWrite(r, 0);
    analogWrite(g, 255);
     analogWrite(b, 0);
 }

else if (data == 'T'){
    Temperatuer();
    delay(100);
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print(welcomeMessage);
    lcd.setCursor(1, 1);
    lcd.print(welcomeMessage1);
   }

else if (data == 'Q'){
   
  directionControlVoiceOpen();

   }
   else if (data == 'Z'){
   
  directionControlVoiceClose();

   }


    if(data == '1') 
    { analogWrite(r, 0);
     analogWrite(g, 0);
     analogWrite(b, 0); } 
     else if(data == '0') 
     {
      analogWrite(r, 255);
      analogWrite(g, 255);
      analogWrite(b, 255);
    } 

  if (currentMillis - previousGasReadTime >= 500) {
    previousGasReadTime = currentMillis;

    int gasValue = digitalRead(gasSensorPin);

    if (gasValue == LOW) {
      AlarmOn();
    } else {
      AlarmOff();
    }
  }

   // IR Sensor
  int irValue = digitalRead(irSensor);
  if (irValue == LOW) {
    directionControl();
  }

}

void AlarmOn()
{
    digitalWrite(buzzerPin, LOW); 
     digitalWrite(fanMotorPin1,HIGH);
     analogWrite(r, 0); 
     analogWrite(g, 255);
     analogWrite(b, 255);
     delay(500); 
     analogWrite(r, 255); 
     delay(500); 
}

void AlarmOff()
{
     digitalWrite(buzzerPin, HIGH); 
     digitalWrite(fanMotorPin1,LOW);
}

void Temperatuer ()
{

  int sensorValue = analogRead(A0);
   float voltage = sensorValue * (5.0 / 1023.0);
   float temperature = voltage * 100;
     lcd.clear();
     lcd.print("Temperature:");
     lcd.setCursor(0, 1);
     lcd.print(temperature);
     lcd.print((char)223);
     lcd.print("C");
     delay(5000); 
}
//Motor
void directionControl(){

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(3000);


   digitalWrite(in1, LOW);
   digitalWrite(in2, LOW);
   digitalWrite(in3, LOW);
   digitalWrite(in4, LOW);
   delay(4000);
   

   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
   digitalWrite(in3, HIGH);
   digitalWrite(in4, LOW);
   delay(2000);
   

   digitalWrite(in1, LOW);
   digitalWrite(in2, LOW);
   digitalWrite(in3, LOW);
   digitalWrite(in4, LOW);
   delay(3000);
}

void directionControlVoiceOpen(){
   digitalWrite(in1, LOW);
   digitalWrite(in2, HIGH);
   digitalWrite(in3, LOW);
   digitalWrite(in4, HIGH);
   delay(3000);
   

   digitalWrite(in1, LOW);
   digitalWrite(in2, LOW);
   digitalWrite(in3, LOW);
   digitalWrite(in4, LOW);
   delay(3000);
}

void directionControlVoiceClose(){
   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
   digitalWrite(in3, HIGH);
   digitalWrite(in4, LOW);
   delay(2000);
   

   digitalWrite(in1, LOW);
   digitalWrite(in2, LOW);
   digitalWrite(in3, LOW);
   digitalWrite(in4, LOW);
   delay(3000);
}
