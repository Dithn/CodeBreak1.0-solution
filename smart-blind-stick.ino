const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
int buzz =3;
int ir = 5;

void setup() {
  pinMode(A0,INPUT);
  pinMode(buzz,OUTPUT);
  pinMode(ir,INPUT);
  Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();

   if(cm>20)  // gadha detecttion
   {
     digitalWrite(buzz,1);
     delay(100);
     digitalWrite(buzz,0);
     delay(100);
     digitalWrite(buzz,1);
     delay(100);
     digitalWrite(buzz,0);
     delay(1000);
   }

   int a=analogRead(A0); // Water Detection
   if(a>100)
   {
     digitalWrite(buzz,1);
     delay(100);
     digitalWrite(buzz,0);
     delay(1000);
   }

   int b=digitalRead(ir); //Obstacle Detection
   
   if(cm>20)
   {
     digitalWrite(buzz,1);
     delay(100);
     digitalWrite(buzz,0);
     delay(100);
     digitalWrite(buzz,1);
     delay(100);
     digitalWrite(buzz,0);
      delay(100);
     digitalWrite(buzz,1);
     delay(100);
     digitalWrite(buzz,0);
     delay(1000);
   }
   
    delay(100);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

