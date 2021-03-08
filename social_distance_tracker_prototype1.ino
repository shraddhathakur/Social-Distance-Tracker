#include <LiquidCrystal.h>

#include <Servo.h>


#define ServoM    7        //Connected to the servo motor.
#define Exit      9         //Pin connected to the EXIT sensor.
#define In        8         //Pin connected to the IN sensor.
#define Pwr  6              //Extra power pin for sensors(Don't connect servo's power to this!)
#define Gnd  10             //Extra groung pin for sensors(Don't connect servo's power to this!)
#define OUT    90      
#define IN     177       
#define CAPACITY  10         //Capacity of the store

LiquidCrystal lcd(13,12,5,4,3,2);
Servo myservo;  




void setup(){
  myservo.attach(ServoM);         
  lcd.begin(16,2);
  lcd.print("Entry available for");
  pinMode(Gnd, OUTPUT);
  pinMode(Pwr, OUTPUT);
  pinMode(Exit, INPUT);           
  pinMode(In, INPUT);            
  digitalWrite(Gnd, LOW);
  digitalWrite(Pwr, HIGH);
  myservo.write(OUT);         
//  delay(1000);
}

int  Available= 10;                   

void loop(){
if (Available == 1){
  lcd.clear();
lcd.setCursor(1,0);
lcd.print("Entry available for");
lcd.setCursor(0,1);  
lcd.print(Available);
lcd.print(" person");
}else{
if (Available >= 1){
lcd.clear();
lcd.setCursor(1,0);
lcd.print("Entry available for");
lcd.setCursor(0,1);  
lcd.print(Available);
lcd.print(" people");
}else{
  lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Sorry!");
    lcd.setCursor(0,1);
    lcd.print("Store full. Please wait!");
}
}


if(digitalRead(In)==1)
{
  if(Available != 0){
    Available--;
    myservo.write(IN);
    delay(3000);
    myservo.write(OUT);
    }
  }
if(digitalRead(Exit)==1)
{
  if(Available != CAPACITY){
    Available++;
    myservo.write(IN);
    delay(3000);
    myservo.write(OUT);
    }
}
  delay(20);
}


