int vMotor = 4;

char* letters[] = {
".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A-I
".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R 
"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." // S-Z
};

char* numbers[] = { "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

int dotDelay = 200;

void setup() 
{
  pinMode(vMotor, OUTPUT);
  Serial.begin(9600);
  Serial.print("--------------------------------------");
  Serial.println();
  Serial.print("Enter text:");
}

void loop() 
{
  char ch;
  if (Serial.available())
  {
    ch = Serial.read(); // read a single letter if (ch >= 'a' && ch <= 'z')
    Serial.print(ch);
    if (ch >= 'a' && ch <= 'z')
    {
      flashSequence(letters[ch - 'a']);
    }
    else if (ch >= 'A' && ch <= 'Z') 
    {
      flashSequence(letters[ch - 'A']); 
    }
    else if (ch >= '0' && ch <= '9') 
    {
      flashSequence(numbers[ch - '0']); 
    }
    else if (ch == ' ') 
    {
      delay(dotDelay * 4);
    }
  }
  //Serial.println();
  //Serial.print("Enter text:");
  //Serial.println();
}

void flashSequence(char* sequence) 
{
  int i = 0;
  while (sequence[i] != NULL) 
  {
    flashDotOrDash(sequence[i]);
    i++; 
   }
  delay(dotDelay * 3);
}

void flashDotOrDash(char dotOrDash) 
{
  digitalWrite(vMotor, HIGH); 
  if (dotOrDash == '.')
  {
    delay(dotDelay);
  }
  else // must be a - 
  {
    delay(dotDelay * 3); 
  }
  digitalWrite(vMotor, LOW); delay(dotDelay);
}
