/* BiPed_2
Status:OK
Written by Deepak Nair
*/ 
#include <Servo.h> 

Servo myservoA;  // create servo object to control a servo 
Servo myservoB;  // twelve servo objects can be created on arduino uno
Servo myservoC;
Servo myservoD;
 
int posA;   // Target servoA position (Left Ankle)
int posB;   // Target servoB position (Left Hip)
int posC;   // Target servoC position (Right Ankle)
int posD;   // Target servoD position (Right Hip)

int posa; // Current servoA position
int posb; // Current servoB position
int posc; // Current servoC position
int posd; // Current servoD position

int count;

void setup() 
{ 
  pinMode(7, OUTPUT);// pin 7 used to power the servos
  digitalWrite(7,LOW);// servo power off
  
 myservoA.attach(A1);// LA
 myservoB.attach(A2);// LH
 myservoC.attach(A3);// RA
 myservoD.attach(A4);// RH
 
    posA = 93; //RA
    posB = 78; //RH
    posC = 95; //LA
    posD = 70; //LH
 
 count = 0;
} 
 
void loop() 
{ 
  digitalWrite(7,HIGH);// Servo Power On.
  count = (count + 1);
  if (count <= 500) // Stand Erect
  {
    posA = 93; //RA 
    posB = 78; //RH reduce to move forward
    posC = 95; //LA
    posD = 70; //LH increase to move forward
  }
  else if ((count >500) && (count <= 550)) // Tilt Right
  {
    posA = 138; //RA 
    posB = 78;  //RH
    posC = 140; //LA
    posD = 70;  //LH
  }
  else if ((count >550) && (count <= 600)) //Right Hip forward
  {
    posA = 138; //RA 
    posB = 52;  //RH
    posC = 140; //LA
    posD = 50;//48;//46;//44;  //LH
  }
  else if ((count >600) && (count <= 650)) // Level off
  {
    posA = 93; //RA 
    posB = 52; //RH
    posC = 95; //LA
    posD = 50;//48;//46;//44; //LH
  }
  else if ((count >650) && (count <= 700)) // Tilt Left
  {
    posA = 48; //RA 
    posB = 52; //RH
    posC = 50; //LA
    posD = 50;//48;//46;//44; //LH
  }
  else if ((count >700) && (count <= 750)) // Left Hip Forward
  {
    posA = 48;  // RA
    posB = 102;//104; //RH
    posC = 50;  //LA
    posD = 90;//92;//94;//96; //LH
  }
    
    else if ((count > 750) && (count <=800)) // Level Off
    { 
    posA = 93;  // RA 
    posB = 102;//; //RH
    posC = 95;  //LA
    posD = 90;//92;//94;//96; //LH
    }
    else if (count > 800)
    { count = 500; // repeat entire sequence
    }
  
    if (posa < posA)
  {
    posa = (posa + 1);     // in steps of 1 degree
  }
  
  else if (posa > posA)
  
  { 
    posa = (posa - 1);
  }
  
  else
  {
  posa = posA;
  }
  
  myservoA.write(posa);
  delay(4);
  
  if (posb < posB)

  {
    posb = (posb + 1);     // in steps of 1 degree  
  }
  
  else if (posb > posB)
  
  { 
    posb = (posb - 1);
  }
  
  else
  {
    posb = posB;
  }
  myservoB.write(posb);
  delay(4);
  
  if (posc < posC)

  {
    posc = (posc + 1);     // in steps of 1 degree  
  }
  
  else if (posc > posC)
  
  { 
    posc = (posc - 1);
  }
  
  else
  {
    posc = posC;
  }
  myservoC.write(posc);
  delay(4);
  
  if (posd < posD)

  {
    posd = (posd + 1);// in steps of 1 degree  
  }
  
  else if (posd > posD)
  
  { 
    posd = (posd - 1);
  }
  
  else
  {
    posd = posD;
  }
  myservoD.write(posd);
  delay(4);
}
  
 
  

  
     
 
