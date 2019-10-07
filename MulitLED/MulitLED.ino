/* 
  Objective: Standard program that will illuminate a multi-LED display setup
             In the below example we have an LED in sockets 13 through 9.  The 
             program will initialize each socket and then perform the set patterns.
  Written by: Joseph Anger
  Created Date: 10/5/2109
*/

int myPins[] = { 13, 12, 11, 10, 9 };
int lastPin = 0;

int LEDCOUNT = sizeof(myPins)/ sizeof(int);
int DELAYSPEED = 500;

void setup() {
  
  //Initialize each socket in the array
  for(int i = 0; i < LEDCOUNT; i++){
    pinMode(myPins[i], OUTPUT);
  }
  
}

void loop() {
  
  //run our patterns
  SingleBulbs();
  FlowPattern();
  AllOn();
  
}

/* Function that lights up one LED at a time */
void SingleBulbs(){
  
  AllOff();
  
  for(int i = 0; i < LEDCOUNT; i++){

    if(lastPin > 0)
      digitalWrite(lastPin, LOW);

    lastPin = myPins[i];
    digitalWrite(myPins[i], HIGH);  
    delay(DELAYSPEED);
  }
}

/* Function that lights up the LEDs on at a time with a faster shut off pattern */
void FlowPattern(){
  
  AllOff();
  
  for(int i = 0; i < LEDCOUNT; i++){
    digitalWrite(myPins[i], HIGH);
    delay(DELAYSPEED);
  }

  for(int i = 0; i < LEDCOUNT; i++){
    digitalWrite(myPins[i], LOW);
    delay(DELAYSPEED / 2);
  }
}

/* Function that turns all the LEDs on */
void AllOn(){
  
  AllOff();
  
  for(int i = 0; i < LEDCOUNT; i++){
    digitalWrite(myPins[i], HIGH);
  }

  delay(DELAYSPEED * LEDCOUNT);
}

/* Function that turns all the LEDs off */
void AllOff(){
  for(int i = 0; i < LEDCOUNT; i++){
    digitalWrite(myPins[i], LOW);
  }
}
