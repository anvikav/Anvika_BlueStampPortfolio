  const int LpingTrig = 7;
  const int LpingEcho = 6;
  const int Lbuz = 3;
  const int Lvib = 10;

  const int RpingTrig = 5;
  const int RpingEcho = 4;
  const int Rbuz = 2;
  const int Rvib = 8;

  void setup() 
  {
    Serial.begin(9600);
    pinMode(LpingTrig, OUTPUT);
    pinMode(LpingEcho, INPUT);
    pinMode(Lbuz, OUTPUT);
    pinMode(Lvib, OUTPUT);

    pinMode(RpingTrig, OUTPUT);
    pinMode(RpingEcho, INPUT);
    pinMode(Rbuz, OUTPUT);
    pinMode(Rvib, OUTPUT);
  }
  
  void loop()
  {
    long Lduration, Lcm, Rduration, Rcm; //Variables for wave duration and wave distance   
    digitalWrite(LpingTrig, LOW); //Confirming that the trigPin is clear   
    digitalWrite(RpingTrig, LOW);   
    delayMicroseconds(2);
    digitalWrite(LpingTrig, HIGH); //Generating a wave by setting trigPin to HIGH for 5 minroseconds and then back to low
    digitalWrite(RpingTrig, HIGH);
    delayMicroseconds(5);
    digitalWrite(LpingTrig, LOW);
    digitalWrite(RpingTrig, LOW);
    Lduration = pulseIn(LpingEcho, HIGH); //Storing the travel time is variable duration
    Rduration = pulseIn(RpingEcho, HIGH); 
    Lcm = microsecondsToCentimeters(Lduration); //Converting to distance   
    Rcm = microsecondsToCentimeters(Rduration); 
    if((Lcm<=100 && Lcm>0) && (Rcm<=100 && Rcm>0)) //Makes the light blink faster when the distance is smaller --> starts blinking at 70cm
    {
      int Ld= map(Lcm, 1, 100, 20, 2000); //d stores a variable that reformats a range
      int Rd= map(Rcm, 1, 100, 20, 2000); //d stores a variable that reformats a range
      digitalWrite(Lbuz, HIGH); //Turning light on for .1 second  
      digitalWrite(Rbuz, HIGH); //Turning light on for .1 second  
      digitalWrite(Lvib, HIGH); //Turning light on for .1 second  
      digitalWrite(Rvib, HIGH); //Turning light on for .1 second  
      delay(100);
      digitalWrite(Lbuz, LOW); //Turning light on for .1 second  
      digitalWrite(Rbuz, LOW); //Turning light on for .1 second  
      digitalWrite(Lvib, LOW); //Turning light on for .1 second  
      digitalWrite(Rvib, LOW); //Turning light on for .1 second 
      delay(((Ld+Rd)/2)); //Waiting for a time that corresponds to the variable cm
    }
    else if((Lcm<=100 && Lcm>0) && !(Rcm<=70 && Rcm>0)) //Makes the light blink faster when the distance is smaller --> starts blinking at 70cm
    {
      int Ld= map(Lcm, 1, 100, 20, 2000); //d stores a variable that reformats a range
      digitalWrite(Lbuz, HIGH); //Turning light on for .1 second  
      digitalWrite(Lvib, HIGH); //Turning light on for .1 second  
      delay(100);
      digitalWrite(Lbuz, LOW); //Turning light on for .1 second  
      digitalWrite(Lvib, LOW); //Turning light on for .1 second  
      delay(Ld); //Waiting for a time that corresponds to the variable cm
    }
    else if(!(Lcm<=70 && Lcm>0) && (Rcm<=100 && Rcm>0)) //Makes the light blink faster when the distance is smaller --> starts blinking at 70cm
    {
      int Rd= map(Rcm, 1, 100, 20, 2000); //d stores a variable that reformats a range
      digitalWrite(Rbuz, HIGH); //Turning light on for .1 second  
      digitalWrite(Rvib, HIGH); //Turning light on for .1 second  
      delay(100);
      digitalWrite(Rbuz, LOW); //Turning light on for .1 second  
      digitalWrite(Rvib, LOW); //Turning light on for .1 second  
      delay(Rd); //Waiting for a time that corresponds to the variable cm
    }
    Serial.print(Lcm);
    Serial.print("cm   ");
    Serial.print(Lcm);
    Serial.print("cm   ");
    Serial.println();
    delay(100);
  }
  
  long microsecondsToCentimeters(long microseconds)
  {
    return microseconds / 29 / 2;
  }
