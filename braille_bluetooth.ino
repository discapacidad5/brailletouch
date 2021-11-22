/*
este es el primer codigo de partida para desarrollar 
*/


#include <ESP32Servo.h>

//Braille binario
int binary[63][8]={{0,0,0,0,0,0,0,0},{0,0,0,1,1,0,1,1},{0,0,0,0,0,1,0,0},{0,0,0,1,0,1,1,1},{0,0,01,1,1,0,0,1},{0,0,01,1,0,0,0,1},{0,0,01,1,1,0,1,1},{0,0,01,0,1,1,1,1},{0,0,0,1,1,1,1,1},{0,0,01,0,0,0,0,1},{0,0,0,1,0,0,1,1} ,{0,0,0,0,0,0,0,1} ,{0,0,0,0,0,0,1,1},{0,0,0,1,0,0,0,1},{0,0,0,1,0,0,1,0},
        {0,0,0,0,0,1,1,1},{0,0,0,0,1,0,0,0},{0,0,0,0,1,0,1,0},{0,0,0,0,1,1,0,0},{0,0,0,0,1,1,0,1},{0,0,0,0,1,0,0,1},{0,0,0,0,1,1,1,0},{0,0,0,0,1,1,1,1},{0,0,0,0,1,0,1,1},{0,0,0,0,0,1,1,0},{0,0,01,0,0,1,0,1},{0,0,0,0,0,1,0,1},{0,0,01,0,1,0,0,1},{0,0,01,1,1,1,1,1},{0,0,0,1,0,1,1,0},{0,0,01,1,0,1,0,1},
        {0,0,0,1,0,0,0,0},{0,0,01,0,0,0,0,0},{0,0,01,0,1,0,0,0},{0,0,01,1,0,0,0,0},{0,0,01,1,0,1,0,0},{0,0,01,0,0,1,0,0},{0,0,01,1,1,0,0,0},{0,0,01,1,1,1,0,0},{0,0,01,0,1,1,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,1,0,0},{0,0,01,0,0,0,1,0},{0,0,01,0,1,0,1,0},{0,0,01,1,0,0,1,0},{0,0,01,1,0,1,1,0},{0,0,01,0,0,1,1,0},{0,0,01,1,1,0,1,0},{0,0,01,1,1,1,1,0},{0,0,01,0,1,1,1,0},{0,0,0,1,1,0,1,0},{0,0,0,1,1,1,1,0},{0,0,01,0,0,0,1,1},{0,0,01,0,1,0,1,1},{0,0,0,1,1,1,0,1},{0,0,01,1,0,0,1,1},{0,0,01,1,0,1,1,1},{0,0,01,0,0,1,1,1},
        {0,0,0,1,1,0,0,1},{0,0,01,0,1,1,0,1},{0,0,01,1,1,1,0,1},{0,0,0,1,0,1,0,0},{0,0,0,1,0,1,0,1}};

//Ascii codigo
char ascii[63]={' ', '!', '"', '#', '$', '%', '&', '(', ')', '*', '+', ',', '-', '.', '/', 
        '0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?',
        '@','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
         '[','\\',']','^','_'};

// Servo servo1, servo2, servo3, servo4, servo5, servo6;

int Received;
char data[16] ="brailletouch 01";  
char input;
int* output;
int temp =0;
int velocidad = 500;

// posicioens de los servos esto controla los puntos a salir por cada servo por el momento no esta  configurado

int right1 = 0;
int right2 = 0;
int left1 = 45;
int left2 = 45; 

Servo dot1;
Servo dot2;
Servo dot3;
Servo dot4;
Servo dot5;
Servo dot6;
Servo dot7;
Servo dot8;

 int minUs = 500;
 int maxUs = 2400;
int dot1Pin = 15; // Un servo en el pin 15
int dot2Pin = 16; // Otro servo en el pin 16
int dot3Pin = 14; // Un servo en el pin 14
int dot4Pin = 32; // Otro servo en el pin 32
int dot5Pin = 4; // Un servo en el pin 4
int dot6Pin = 33; // Otro servo en el pin 33
int dot7Pin = 19; // Otro servo en el pin 19
int dot8Pin = 21; // Otro servo en el pin 21


char val;
String grados;
int angulo;
ESP32PWM pwm;

void setup() 
{  
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  Serial.begin(115200);
  dot1.setPeriodHertz(50);      // Standard 50hz servo
  dot2.setPeriodHertz(50);      // Standard 50hz servo
  dot3.setPeriodHertz(50);      // Standard 50hz servo
  dot4.setPeriodHertz(50);      // Standard 50hz servo
  dot5.setPeriodHertz(50);      // Standard 50hz servo
  dot6.setPeriodHertz(50);      // Standard 50hz servo 
  dot7.setPeriodHertz(50);      // Standard 50hz servo      
  dot8.setPeriodHertz(50);      // Standard 50hz servo      
        
 /*   pinMode(2, OUTPUT);  
    pinMode(3, OUTPUT);  
    pinMode(4, OUTPUT);  
    pinMode(5, OUTPUT);  
    pinMode(6, OUTPUT);  
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);   
    Serial.begin(9600); 
    
    servo1.attach(3);
    servo2.attach(5);
    servo3.attach(6);
    servo4.attach(9);
    servo5.attach(10);
    servo6.attach(11);*/
}  

void servo_disp(int* output)
{
   if( output[0] == 1 )
   {
    dot1.write(0);
//    digitalWrite(k+2, HIGH);
     Serial.print("punto 1...\n");
   }
   else
   {
    dot1.write(45);
//    digitalWrite(k+2, LOW);
   }
    if( output[1] == 1 )
   {
    dot2.write(0);
     Serial.print("punto 2...\n");
//    digitalWrite(k+2, HIGH);
   }
   else
   {
    dot2.write(45);
//    digitalWrite(k+2, LOW);
   }
    if( output[2] == 1 )
   {
    dot3.write(0);
     Serial.print("punto 3...\n");    
//    digitalWrite(k+2, HIGH);
   }
   else
   {
    dot3.write(45);
//    digitalWrite(k+2, LOW);
   }
    if( output[3] == 1 )
   {
    dot4.write(0);
     Serial.print("punto 4...\n");    
//    digitalWrite(k+2, HIGH);
   }
   else
   {
    dot4.write(45);
//    digitalWrite(k+2, LOW);
   }
    if( output[4] == 1 )
   {
    dot5.write(0);
     Serial.print("punto 5...\n");    
//    digitalWrite(k+2, HIGH);
   }
   else
   {
    dot5.write(45);
//    digitalWrite(k+2, LOW);
   }
    if( output[5] == 1 )
   {
    dot6.write(0);
     Serial.print("punto 6...\n");    
//    digitalWrite(k+2, HIGH);
   }
   else
   {
    dot6.write(45);
//    digitalWrite(k+2, LOW);
   }
   if( output[6] == 1 )
   {
    dot7.write(0);
     Serial.print("punto 7...\n");    
//    digitalWrite(k+2, HIGH);
   }
   else
   {
    dot7.write(45);
//    digitalWrite(k+2, LOW);
   }if( output[7] == 1 )
   {
    dot8.write(0);
     Serial.print("punto 3...\n");    
//    digitalWrite(k+2, HIGH);
   }
   else
   {
    dot8.write(45);
//    digitalWrite(k+2, LOW);
   }

}

void loop()
{ 
      
  if (Serial.available() > 0)
  {
  dot1.attach(dot1Pin, minUs, maxUs);
  dot2.attach(dot2Pin, minUs, maxUs);
  pwm.attachPin(27, 10000);//10khz
  dot3.attach(dot3Pin, minUs, maxUs);
  dot4.attach(dot4Pin, minUs, maxUs);
  dot5.attach(dot5Pin, minUs, maxUs);  
  dot6.attach(dot6Pin, minUs, maxUs);
  dot7.attach(dot6Pin, minUs, maxUs);
  dot8.attach(dot6Pin, minUs, maxUs);

    
    while(Serial.available() > 0)
    {




      
      Serial.print("I am reading...\n");
      Received = Serial.read();
      Serial.print(Received);
      Serial.print(": ");
      Serial.print((char)Received);
      Serial.print("\n");
      input= (char)Received;
  
              if( input >=65 and input<91 )
          {
            //capital letters
            temp = 1;
             input += 'a' -'A' ;
          }
      
      for (int j=0 ; j<sizeof(ascii); j++)
      {
     
        if(input == ascii[j])
      {
        output=binary[j];
        if( temp == 1 )
        {
          //capital letters
          dot1.write(45);
          dot2.write(45);
          dot3.write(45);
          dot4.write(45);
          dot5.write(45);
          dot6.write(45);
          dot7.write(0);
          dot8.write(45); 
           Serial.print("punto 7...\n");            
          delay(50);
//          servo6.write(1);
          temp = 0;
        }
        else if(input>= '1' && input<='9')
        {
          //digits
          dot1.write(0);
          dot2.write(0);
          dot3.write(0);
          dot4.write(0);
          dot5.write(0);
          dot6.write(45);
          dot7.write(0);
          dot8.write(0);
          Serial.print("punto 6...\n");
          delay(50);
//          servo2.write(1);
//          servo4.write(1);
//          servo5.write(1);
//          servo6.write(1);

        }
         servo_disp(output);
         delay(velocidad);         //   controla la velocidad  con que sale el carater
         
         break;
        }
      }     
    }

      grados = "";

    
  }
  else
  {
    Serial.print(Serial.available());
    int zero[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    servo_disp(zero);
    delay(2000);
    dot1.detach();
    dot2.detach();
    dot3.detach();
    dot4.detach();
    dot5.detach();
    dot6.detach();
    dot7.detach();
    dot8.detach();
    pwm.detachPin(27);

  }
}


