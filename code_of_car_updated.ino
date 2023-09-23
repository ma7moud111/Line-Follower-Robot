/********************************************/
/* Project Name: Line Follower Robot 
/* Author:       Mahmoud Sayed
/********************************************/

#define OUT1 2
#define OUT2 5
#define OUT3 3
#define OUT4 4
#define L_S 13      // LEFT SENSOR 
#define R_S 12      // RIGHT SENSOR
#define enA 6       // RIGHT MOTOR CONTROL (PWM)
#define enB 9       // LEFT MOTOR CONTROL (PWM)


void setup() {
  // put your setup
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  pinMode(OUT3, OUTPUT);
  pinMode(OUT4, OUTPUT);
  pinMode(L_S, INPUT);
  pinMode(R_S, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  analogWrite(enA, 65);     // this is the motor to be edited 
  analogWrite(enB, 50);
}

void loop() {

  // put your main code here, to run repeatedly:
  int s1 = digitalRead(L_S);        // READING THE SIGNAL THAT COMES FROM THE LEFT SENSOR 
  int s2 = digitalRead(R_S);        // READING THE SIGNAL THAT COMES FROM THE RIGHT SENSOR 
  
  if (s1 == LOW && s2 == LOW) 
  {
    /* CASE OF MOVING FORWARD */
    forward();
  } 
  else if (s1 == HIGH && s2 == LOW) 
  {
    /* CASE OF TURNING LEFT */
    left();
    
  } 
  else if (s1 == LOW && s2 == HIGH) 
  {
    /* CASE OF TURNING RIGHT */
    right();
  } 
  else 
  {
    /* CASE OF STOP */
    stop();
  }
}

void forward()
{
    digitalWrite(OUT1, HIGH);
    digitalWrite(OUT2, LOW);
    digitalWrite(OUT3, LOW);
    digitalWrite(OUT4, HIGH);
} 

void left()
{
    digitalWrite(OUT1, LOW);
    digitalWrite(OUT2, HIGH);
    digitalWrite(OUT3, LOW);
    digitalWrite(OUT4, HIGH);
}

void right()
{
    digitalWrite(OUT1, HIGH);
    digitalWrite(OUT2, LOW);
    digitalWrite(OUT3, HIGH);
    digitalWrite(OUT4, LOW);
}

void stop()
{
    digitalWrite(OUT1, LOW);
    digitalWrite(OUT2, LOW);
    digitalWrite(OUT3, LOW);
    digitalWrite(OUT4, LOW);
}

