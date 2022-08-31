#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
///////////////////////////////
#define sensor A0
#define sensor1 A1



int blinkPin = A2;
int out1 = 6;
int out2 = 7;

int buttonState = 0; 

void setup()
{
 mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
    
  pinMode(out1,OUTPUT);
  digitalWrite (out1, LOW);
  pinMode(out2,OUTPUT);
  digitalWrite (out2, LOW);
  lcd.begin(16, 2);
 lcd.clear();
}

 

void loop()

{
  /*---------Temperature-------*/

  delay(10);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("SOLDIER SAFETY");
lcd.setCursor(0,1);
lcd.print("SYSTEM   ");
delay(3000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("            ");
lcd.setCursor(0,1);
lcd.print("         ");
delay(3000);
lcd.clear();
float reading=analogRead(sensor);
float reading1=analogRead(sensor1);//
float reading2=analogRead(sensor2);

delay(10);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("SOLDIER Temp:");
lcd.setCursor(4,1);
lcd.print(temperature);
//lcd.write(1);
lcd.print(" C");
delay(3000);
lcd.clear();
delay(1000);

if(temperature>32)
               {
                       lcd.clear();
                       lcd.setCursor(0,0);
                       lcd.print("SOLDIER FEVER");
                       lcd.setCursor(0,1);
                       digitalWrite (out1,HIGH);
                        delay(3000);
                       digitalWrite (out2,HIGH);
                       delay(3000);
                       digitalWrite (out2,LOW);
                       delay(3000);
                                 
               }
             else
             {
               delay(3000);
               lcd.clear();
               lcd.setCursor(0,0);
              lcd.print("SOLDIER TempNORM");
              lcd.setCursor(1,1);
              lcd.print("Safe ");
              digitalWrite (out1,LOW);
              lcd.clear();
               }

 

 lcd.clear();             
lcd.setCursor(0,0);
lcd.print("HEART BEAT");
lcd.setCursor(4,1);
lcd.print(temperature1);
lcd.write(1);
lcd.print("   ");
delay(3000);
lcd.clear();
delay(3000);
lcd.clear();
lcd.setCursor(0,0);

lcd.print("SMOKE/POISONOUS ");
 lcd.setCursor(1,1);
 lcd.print("GAS CHEK ");
lcd.setCursor(0,1);
delay(3000);
//}


 buttonState = digitalRead(blinkPin);
   if (buttonState == HIGH) {
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("NO SMOKE/ ");
 
  lcd.setCursor(0,1);
    lcd.print("POISONOUS GAS");
 // lcd.print(voltage);
  delay(3000);
  } else {
     lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("SMOKE/ ");
  
  
  lcd.setCursor(0,1);
  lcd.print("POISON GAS DETECTED");
//  lcd.print(voltage);
  delay(3000);
 
  }


}


void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+918073190374\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("location details");// The SMS text you want to send
  delay(100);
  mySerial.println(tempfar1a);// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}

void SendMessage1()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+918073190374\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("location details");// The SMS text you want to send
  delay(100);
  mySerial.println(tempfar1a);// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
