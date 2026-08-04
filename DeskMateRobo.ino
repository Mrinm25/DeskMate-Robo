#include <LiquidCrystal.h>
#include<Servo.h>

Servo S1;

// LCD Pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int Trig = 9;
int Echo = 10;
int Time;
int Distance;
int person_present = 0;
int x = 35;       //x is the threshold distance. for detecting a person

void setup()
{
  Serial.begin(9600);

  S1.attach(6);
  S1.write(60);

  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);

  lcd.begin(16, 2);      // Initialize a 16x2 LCD

}

int sense(){
  digitalWrite(Trig,0);
  delayMicroseconds(2);
  digitalWrite(Trig,1);
  delayMicroseconds(10);
  digitalWrite(Trig, 0);

  Time = pulseIn(Echo,1,30000);
  Distance = (0.0343 * Time)/2;
  return Distance;
}

void loop()
{ 
  int lightValue;
  lightValue = analogRead(A0);
  

  if (lightValue < 250){                      //if Dark
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("Good Night");
    delay(3500);
    lcd.clear();

    while(lightValue < 250){
      for(int i = 1; i <= 3; i++) {

          lcd.setCursor(6,1);

          if(i == 1)
              lcd.print("Z");

          else if(i == 2)
              lcd.print("Zz");

          else
              lcd.print("Zzz");

          delay(500);
      }
      lightValue = analogRead(A0);
    }
    
      delay(1000);
      lcd.clear();
  }else{
        lcd.clear();
        lcd.setCursor(3, 0);            //DeskMate Searching
        lcd.print("DeskMate");
        lcd.setCursor(4, 1);
        lcd.print("Searching");
        lcd.blink();

        for(int i = 60; i<=120; i++){          //searching until someone comes
          S1.write(i);
          delay(15);
          
          if (i % 5 == 0){
            Distance = sense();
            Serial.println(Distance);
          }
          
          
          if(Distance < x){

            person_present = 1;      // Person detected

            S1.write(i);             // Stop servo at current position

            lcd.clear();
            lcd.setCursor(2,0);
            lcd.print("Hii Buddy");
            delay(2000);
            lcd.clear();

            // Stay here until the person leaves
            while(person_present == 1){
                S1.write(i);  

                lcd.setCursor(2,1);
                lcd.print("How are u?");
                delay(3000);
                lcd.clear();

                Distance = sense();
                Serial.println(Distance);

                if(Distance > x){       // Person left
                    person_present = 0;
                }

                delay(100);
            }

            lcd.clear();
            break;
        }
        }

        if(person_present == 0){

          for(int i = 120; i>=60; i--){

              S1.write(i);
              delay(15);

              if(i % 5 == 0){
                  Distance = sense();
                  Serial.println(Distance);
              }

              if(Distance < x){

                  person_present = 1;

                  S1.write(i);

                  lcd.clear();
                  lcd.setCursor(2,0);
                  lcd.print("Hii Buddy");
                  delay(2000);
                  lcd.clear();

                  while(person_present == 1){

                      Distance = sense();
                      Serial.println(Distance);

                      lcd.setCursor(2,1);
                      lcd.print("How are u?");
                      delay(3000);
                      lcd.clear();

                      if(Distance > x){
                          person_present = 0;
                      }

                      delay(100);
                  }

                  lcd.clear();
                  break;
              }
          }

      }

  }

}
