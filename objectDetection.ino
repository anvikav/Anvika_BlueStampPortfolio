  const int pingTrigPin = 3; //Trigger connected to PIN 3
  const int pingEchoPin = 2; //Echo connected to PIN 2
  const int buz = 4; //Buzzer connected to PIN 4
  
  void setup() 
  {
    Serial.begin(9600);
    pinMode(buz, OUTPUT);
    pinMode(pingTrigPin, OUTPUT);
    pinMode(pingEchoPin, INPUT);
  }
  
  void loop()
  {
    long duration, cm; //Variables for wave duration and wave distance   
    digitalWrite(pingTrigPin, LOW); //Confirming that the trigPin is clear   
    delayMicroseconds(2);
    digitalWrite(pingTrigPin, HIGH); //Generating a wave by setting trigPin to HIGH for 5 minroseconds and then back to low
    delayMicroseconds(5);
    digitalWrite(pingTrigPin, LOW);
    duration = pulseIn(pingEchoPin, HIGH); //Storing the travel time is variable duration
    cm = microsecondsToCentimeters(duration); //Converting to distance   
    if(cm<=70 && cm>0) //Makes the light blink faster when the distance is smaller --> starts blinking at 70cm
    {
      int d= map(cm, 1, 100, 20, 2000); //d stores a variable that reformats a range
      digitalWrite(buz, HIGH); //Turning light on for .1 second  
      delay(100);
      digitalWrite(buz, LOW); //Turning light off 
      delay(d); //Waiting for a time that corresponds to the variable cm
    }
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    delay(100);
  }
  
  long microsecondsToCentimeters(long microseconds)
  {
    return microseconds / 29 / 2;
  }
