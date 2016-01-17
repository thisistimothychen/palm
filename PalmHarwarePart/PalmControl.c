int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;
int LED6 = 7;



void setup()
{
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  Serial.println("              Welcome!");
  Serial.println("          a = Slide forward");
  Serial.println("          s = Slide backward");
  Serial.println("          d = Zoom in/out");
  Serial.println("          f = Exit");
  Serial.println("          g = Power off");
  Serial.println("          c = Laser on/off");
}

void loop()
{
  
  int x=0, z=0;
  while(x==0)
  {
    int a = Serial.read();
      
    //Slide Forward
    if(a==97)
    {
     Serial.println("   Transitioning forward one slide");
     digitalWrite(LED1, HIGH);
     delay(200);
     digitalWrite(LED1, LOW);
     x=1;
    }
      
    //Slide Backward
    if(a==115)
    {
     Serial.println("   Transitioning backward one slide");
     digitalWrite(LED2, HIGH);
     delay(200);
     digitalWrite(LED2, LOW);
     x=1;
    }
      
    //Zoom Control
    if(a==100)
    {
     Serial.println("   Zoom in");
     digitalWrite(LED3, HIGH);
     while(z==0)
     {
        int b = Serial.read();
        if(b==100)
        {
          digitalWrite(LED3, LOW);
          Serial.println("  Zoom out");
          z=1;
        }
     }
     x=1;
    }
      
    //Exit Control
    if(a==102)
    {
     Serial.println("   Exit Slideshow");
     digitalWrite(LED4, HIGH);
     delay(200);
     digitalWrite(LED4, LOW);
     x=1;
    }
      
    //Power Control
    if(a==103)
    {
     Serial.println("   Power off");
     digitalWrite(LED5, HIGH);
     delay(200);
     digitalWrite(LED5, LOW);
     x=1;
    }
      
    //Laser Control
    if(a==99)
    {
     Serial.println("   Laser on");
     digitalWrite(LED6, HIGH);
     while(z==0)
     {
        int b = Serial.read();
        if(b==99)
        {
          digitalWrite(LED6, LOW);
          Serial.println("  Laser off");
          z=1;
        }
     }
     x=1;
    }
  }
}

