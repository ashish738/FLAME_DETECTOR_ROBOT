 #include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);      //LCD DISPLAY

#define flamePin 8                  //Sensor
#define buzzerPin 9                 //Buzzeer
#define LM1 A0                      //Leftmotor1
#define LM2 A1                      //Leftmotor2
#define RM1 A2                      //Rightmotor1
#define RM2 A3                      //Rightmotor2
#define ENA 10                     //ENA PIN
#define ENB 11                      //ENB PIN


void setup() {
 Serial.begin(9600);
 lcd.begin(16, 2); 

 pinMode(buzzerPin,OUTPUT);         //DEFINING INPUT & OUTPUT PINS
 pinMode(flamePin,INPUT);
 pinMode(LM1, OUTPUT);
 pinMode(LM2, OUTPUT);
 pinMode(RM1, OUTPUT);
 pinMode(RM2, OUTPUT);
 pinMode(ENA, OUTPUT);
 pinMode(ENB, OUTPUT);
 
  lcd.setCursor(0, 0);                  //SETTING CURSOR ON LCD DISPLAY
  lcd.print("Calibrating");
    for(int i = 0; i <5; i++){
      if (i==4)
      {
         lcd.setCursor(0, 1);
         lcd.print(".");
        }
       else  lcd.print(".");
      delay(500);
      }
    lcd.setCursor(11, 1);
    lcd.print("Done");
    delay(1000);
    lcd.clear(); 
    lcd.setCursor(1, 0);
    lcd.print("ALL SENSOR &");
    lcd.setCursor(0, 1);
    lcd.print("DEVICES ARE OK");
    delay(2000);
    lcd.clear(); 

}

void loop() {
  
int Flame = digitalRead(flamePin);

  if (Flame == LOW)                      // IF FLAME IS DETECTED THEN PERFORM THIS OPERATION
  {
     digitalWrite(buzzerPin,HIGH);
     lcd.setCursor(0, 0);
     lcd.print("Flame: ");
     lcd.print("Detected");
     lcd.setCursor(0, 1);
     lcd.print("WARNING!! :(");
     Serial.print(Flame);
     Serial.print("\t");
     Serial.print("Flame is Detected");   
     Serial.print("WARNING!!");  
     digitalWrite(LM1,LOW);
     digitalWrite(LM2,LOW);
     analogWrite(ENA, 0);
     digitalWrite(RM1,LOW);
     digitalWrite(RM2,LOW);
     analogWrite(ENB, 0);
  }
  else if (Flame == HIGH)               // IF FLAME IS NOT DETECTED THEN PERFORM THIS OPERATION
  {
     digitalWrite(buzzerPin,LOW);
     lcd.setCursor(0, 0);
     lcd.print("Flame: ");
     lcd.print("No Flame");
     lcd.setCursor(0, 1);
     lcd.print("We are SAFE :)");
     Serial.print(Flame);
     Serial.print("\t");
     Serial.println("No Flame");
     Serial.println("We are SAFE");
     digitalWrite(LM1,LOW);
     digitalWrite(LM2,HIGH);
     analogWrite(ENA, 95);
     digitalWrite(RM1,HIGH);
     digitalWrite(RM2,LOW);
     analogWrite(ENB, 75);   
  }
  
  delay(300);
  lcd.clear();
}
