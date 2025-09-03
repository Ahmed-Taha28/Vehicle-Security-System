
#include <SPI.h> 
#include <MFRC522.h> 
#define SS_PIN 53 
#define RST_PIN 5 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display 
int DriverB = 31; // driver 
int DoorB2 = 32; // DoorB2 
int DoorB3 = 33;  
int DoorB4 = 34;  
int button5 = 35; //gas 
int button6 = 30;//lock 
int led1 =40 ; //driver 
int led2 =41 ;  // door 2 
int led3 =42 ; // 3 
int led4 =43 ;//4 
int led5 =44 ;//saolon 
int led6 =45 ;//green 
int led7 =46 ;//red 
int led8=39;//lock 
int buzzer= 49; 
bool carON = false; 
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.   
char Incoming_value = 0;  

void setup() 
{ 
pinMode(DriverB, INPUT); 
pinMode(DoorB2, INPUT); 
pinMode(DoorB3, INPUT); 
pinMode(DoorB4, INPUT); 
pinMode(button5, INPUT); 
pinMode(button6, INPUT); 
pinMode(led1, OUTPUT); 
pinMode(led2, OUTPUT); 
pinMode(led3, OUTPUT); 
pinMode(led4, OUTPUT); 
pinMode(led5, OUTPUT); 
pinMode(led6, OUTPUT); 
pinMode(led7, OUTPUT); 
pinMode(led8, OUTPUT); 
Serial.begin(9600);   // Initiate a serial communication 
  SPI.begin();      // Initiate  SPI bus 
  mfrc522.PCD_Init();   // Initiate MFRC522 
  //Serial.println("Approximate your card to the reader..."); 
  //Serial.println();  
  lcd.init();// initialize the lcd 
  lcd.backlight(); 
   
   
  lcd.clear(); 
  lcd.setCursor(1,0); 
  lcd.print("Please Scan"); 
  lcd.setCursor(5,1); 
   lcd.print("Card"); 
} 
 
void turnCarOFF(){ 
  digitalWrite(led1, LOW); 
  digitalWrite(led2, LOW); 
  digitalWrite(led3, LOW); 
  digitalWrite(led4, LOW); 
  digitalWrite(led5, LOW); 
  digitalWrite(led6, LOW); 
  digitalWrite(led7, LOW); 
  digitalWrite(led8, LOW); 
  lcd.clear(); 
  lcd.setCursor(1,0); 
  lcd.print("Please Scan"); 
  lcd.setCursor(5,1); 
   lcd.print("Card"); 
} 
 
void RFID(){ 
 
      
   
   // Look for new cards 
  if ( ! mfrc522.PICC_IsNewCardPresent())  
  { 
    return; 
  } 
  // Select one of the cards 
  if ( ! mfrc522.PICC_ReadCardSerial())  
  { 
    return; 
  } 
   //Show UID on serial monitor 
  //Serial.print("UID tag :"); 
  String content= ""; 
  byte letter; 
  for (byte i = 0; i < mfrc522.uid.size; i++)  
  { 
     //Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "); 
     //Serial.print(mfrc522.uid.uidByte[i], HEX); 
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ")); 
     content.concat(String(mfrc522.uid.uidByte[i], HEX)); 
  } 
  //Serial.println(); 
  //Serial.print("Message : "); 
  content.toUpperCase(); 
  if (content.substring(1) == "40 D1 9E 1A") //change here the UID of the card/cards that you want to give access 
  { 
    Serial.println("1"); 
    //Serial.println(); 
    carON = !carON; 
    turnCarOFF(); 
    //delay(3000); 
    digitalWrite(45,1);    
    delay(200); 
    digitalWrite(45,0); 
    delay(200); 
  } 
   else  
  { 
    Serial.println("Invalid"); 
    //Serial.println(); 
    carON = false; 
    turnCarOFF(); 
    //delay(3000); 
    digitalWrite(46,1); 
    delay(200); 
    digitalWrite(46,0); 
    delay(200); 
   
} 
} 
void bluetoothCheck(){ 
   
  if(Serial.available() > 0)   
  { 
     
    Incoming_value = Serial.read();       
    //Serial.print(Incoming_value);         
    //Serial.print("\n");         
    if(Incoming_value == '1') {     
      carON = true;         
      digitalWrite(45, HIGH); 
       
      delay(750); 
      digitalWrite(45, LOW); 
     }else if(Incoming_value == '0'){      
      carON = false; 
      digitalWrite(46, HIGH); 
        
      delay(750); 
      digitalWrite(46, LOW); 
      turnCarOFF(); 
     } 
} 
} 
void loop() 
{ 
   RFID(); 
   bluetoothCheck(); 
  if(!carON){ 
    lcd.setCursor(1,0); 
    lcd.print("Please Scan"); 
    lcd.setCursor(5,1); 
    lcd.print("Card"); 
 
    return; 
  } 
   
  int  BUTTONVALUE1= digitalRead(DriverB);  
  int  BUTTONVALUE2= digitalRead(DoorB2); 
  int  BUTTONVALUE3= digitalRead(DoorB3); 
 
int  BUTTONVALUE4= digitalRead(DoorB4); 
  int  BUTTONVALUE5= digitalRead(button5); 
  int  BUTTONVALUE6= digitalRead(button6);  
   
  String message = "Button1:"; 
  message.concat(BUTTONVALUE1); 
  message.concat(", Button2:"); 
  message.concat(BUTTONVALUE2); 
  message.concat(", Button3:"); 
  message.concat(BUTTONVALUE3); 
  message.concat(", Button4:"); 
  message.concat(BUTTONVALUE4); 
  message.concat(", Button5:"); 
  message.concat(BUTTONVALUE5); 
  message.concat(", Button6:"); 
  message.concat(BUTTONVALUE6); 
  //Serial.println(message); 
 
  if(BUTTONVALUE6 == 1){ 
    digitalWrite(led8,HIGH); 
    BUTTONVALUE1  =1; 
    BUTTONVALUE2  =1; 
    BUTTONVALUE3  =1; 
    BUTTONVALUE4  =1; 
  }else{ 
    digitalWrite(led8,LOW); 
  } 
   
  if (BUTTONVALUE5 == 1){ 
    if (BUTTONVALUE1  ==0 || BUTTONVALUE2  ==0 || BUTTONVALUE3  ==0 || BUTTONVALUE4  ==0){ 
        tone(buzzer,500);  
    }else{ 
        noTone(buzzer); 
    } 
  }else{ 
    noTone(buzzer); 
  } 
   
  if(BUTTONVALUE6  ==1){ 
     
   digitalWrite(led8, HIGH); 
    
 
  } 
  else{ 
  digitalWrite(led8, LOW); 
  }  
 
   
  if (BUTTONVALUE1  ==0 || BUTTONVALUE2  ==0 || BUTTONVALUE3  ==0 || BUTTONVALUE4  ==0){ 
    digitalWrite(led5, HIGH); 
     
  } 
  else { 
    digitalWrite(led5, LOW); 
  } 
  if (BUTTONVALUE1 == 1 && BUTTONVALUE2 == 1 && BUTTONVALUE3 == 1 && BUTTONVALUE4 == 1){ 
  lcd.clear(); 
  lcd.setCursor(0,0); 
  lcd.print("-System Working-"); 
  lcd.setCursor(5,1); 
   lcd.print("....."); 
  } 
  else{ 
  lcd.clear(); 
   lcd.setCursor(0,0); 
   lcd.print("DOOR"); 
   lcd.setCursor(0,1); 
   lcd.print("IS OPENED"); 
  } 
    
  if(BUTTONVALUE1  ==0 && BUTTONVALUE6 == 0){ 
     
   lcd.setCursor(5,0); 
   lcd.print("1"); 
    digitalWrite(led1, HIGH); 
  } 
  else { 
digitalWrite(led1, LOW); 
  } 
 BUTTONVALUE2= digitalRead(DoorB2);  
   
  if(BUTTONVALUE2  ==0&& BUTTONVALUE6 == 0){ 
     
  
    lcd.setCursor(7,0); 
   lcd.print("2"); 
    digitalWrite(led2, HIGH); 
  } 
  else { 
digitalWrite(led2, LOW); 
 
 } 
 BUTTONVALUE3= digitalRead(DoorB3);  
   
  if(BUTTONVALUE3 ==0&& BUTTONVALUE6 == 0){ 
     lcd.setCursor(9,0); 
   lcd.print("3"); 
    digitalWrite(led3, HIGH); 
  } 
  else { 
digitalWrite(led3, LOW); 
  } 
  
 BUTTONVALUE4= digitalRead(DoorB4);  
   
  if(BUTTONVALUE4  ==0&& BUTTONVALUE6 == 0){ 
     lcd.setCursor(11,0); 
     lcd.print("4"); 
     digitalWrite(led4, HIGH); 
  } 
  else { 
    digitalWrite(led4, LOW); 
    } 
} 
