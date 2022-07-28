#include<Servo.h>
Servo base;
Servo elbow;
Servo arm;
Servo grip;
char vale;
#define en1 3
#define in1 7
#define in2 8
#define in3 2
#define in4 4
#define en2 5
void setup() {
  // put your setup code here, to run once:
  base.attach(6);
  elbow.attach(9);
  arm.attach(10);
  grip.attach(11);
  base.writeMicroseconds(1500);
  elbow.writeMicroseconds(1500);
  arm.writeMicroseconds(1500);
  grip.writeMicroseconds(1500);
  Serial.begin(9600);
    pinMode(en1,OUTPUT);
    pinMode(in1,OUTPUT);
    pinMode(in2,OUTPUT);
  //  digitalWrite(en1,LOW);
    pinMode(in3,OUTPUT);
    pinMode(in4,OUTPUT);
    pinMode(en2,OUTPUT);
  //  digitalWrite(en2,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int armangle;
int baseangle;
int elbowangle;
int gripangle;
  if(Serial.available()>0)
  {
    vale = Serial.read();
    Serial.println(vale);
  }
//  else
//  {
//    digitalWrite(en2,LOW);
//    digitalWrite(en1,LOW);
//  }
    if(vale=='F')
    {
      analogWrite(en1,100);
      analogWrite(en2,100);
     
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
    }
    else if (vale=='B')
    {
      analogWrite(en1,100);
      analogWrite(en2,100);
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
    }
    else if (vale=='L')
    {
      analogWrite(en1,100);
      analogWrite(en2,100);
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW); 
    }
    else if (vale=='R')
    {
      analogWrite(en1,100);
      analogWrite(en2,100);
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH); 
    }
    else if (vale=='S')
    {
      digitalWrite(en2,LOW);
      digitalWrite(en1,LOW);
    }
    else if(vale=='W')
  {
    armangle = armangle+1;
    delay(20);
    arm.write(armangle);
    if(armangle>200)
    {
      arm.write(200);
      armangle = 200;
    }
  }
  else if(vale=='X')
  {
    armangle = armangle-1;
    delay(20);
    arm.write(armangle);
    if(armangle<0)
    {
      arm.write(0);
      armangle = 0;
    }
  }
   else if(vale=='G')
    {
      elbowangle = elbowangle+1;
      delay(20);
      elbow.write(elbowangle);
      if(elbowangle>180)
      {
        elbow.write(180);
        elbowangle = 180;
      }
    }
    else if(vale=='I')
    {
      elbowangle = elbowangle-1;
      delay(20);
      elbow.write(elbowangle);
      if(elbowangle<10)
      {
        elbow.write(10);
        elbowangle = 10;
      }
    }
    else if(vale=='H')
    {
      gripangle = gripangle+1;
      delay(20);
      grip.write(gripangle);
      if(gripangle>170)
      {
        grip.write(170);
        gripangle = 170;
      }
    }
    else if(vale=='J')
    {
      gripangle = gripangle-1;
      delay(20);
      elbow.write(gripangle);
      if(gripangle<0)
      {
        grip.write(80);
        gripangle = 80;
      }
    }
   else if(vale=='Y')
    {
      baseangle = baseangle-1;
      delay(15);
      base.write(baseangle);
      if(baseangle<0)
      {
        base.write(0);
        baseangle = 0;
      }
    }
    else if(vale=='Q')
    {
      baseangle = baseangle+1;
      delay(15);
      base.write(baseangle);
      if(baseangle>170)
      {
        base.write(170);
        baseangle = 170;
      }
    }
  Serial.println(armangle);
}
