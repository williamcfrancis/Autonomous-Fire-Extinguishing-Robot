int d1 = 2;
int d2 = 3;
int d3 = 4;
int led = 10;
int motora1 = 5;
int motora2 = 6;
int motorb1 = 7;
int motorb2 = 8;
int cam_motor1 = 11; /* use same in case of valve */
int cam_motor2 = 12;
int enable = 9; /* enable for cam motor driver */
void setup(){
pinMode(led,OUTPUT);
pinMode(d1,INPUT);
pinMode(d2,INPUT);
pinMode(d3,INPUT);
pinMode(motora1,OUTPUT);
pinMode(motora2,OUTPUT);
pinMode(motorb1,OUTPUT);
pinMode(motorb2,OUTPUT);
pinMode(cam_motor1,OUTPUT);
pinMode(cam_motor2,OUTPUT);
}
void brake()
{ digitalWrite(motora1,HIGH);
digitalWrite(motora2,HIGH);
digitalWrite(motorb1,HIGH);
digitalWrite(motorb2,HIGH);
}
void rotate()
{
digitalWrite(motora1,HIGH);
digitalWrite(motora2,LOW);
digitalWrite(motorb2,HIGH);
digitalWrite(motorb1,LOW);
}
void left()

{
digitalWrite(motora2,HIGH);
digitalWrite(motora1,LOW);
digitalWrite(motorb1,HIGH);
digitalWrite(motorb2,LOW);
}
void forward()
{
digitalWrite(motora1,HIGH);
digitalWrite(motora2,LOW);
digitalWrite(motorb1,HIGH);
digitalWrite(motorb2,LOW);
}
void backward()
{
digitalWrite(motora2,HIGH);
digitalWrite(motora1,LOW);
digitalWrite(motorb2,HIGH);
digitalWrite(motorb1,LOW);
}
void start()
{ digitalWrite(cam_motor1,HIGH);
digitalWrite(cam_motor2,LOW);
}
void spray_stop()
{
digitalWrite(cam_motor1,LOW);
digitalWrite(cam_motor2,HIGH);
}
void normal()
{
digitalWrite(cam_motor1,LOW);
digitalWrite(cam_motor2,LOW);
}

void loop(){
rotate();
while(digitalRead(d1)==HIGH&&digitalRead(d3)==HIGH&&
digitalRead(d2)==LOW)

{
digitalWrite(led,HIGH);
forward();
}
while(digitalRead(d2)==HIGH)
{
digitalWrite(led,HIGH);
digitalWrite(enable,HIGH);
start();
brake();
delay(5000);
normal();
backward();
delay(700);
forward();
delay(1000);
}
spray_stop();
digitalWrite(led,LOW);
delay(500);
normal();
digitalWrite(enable,LOW);
}
