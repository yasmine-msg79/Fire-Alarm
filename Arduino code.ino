float temp;
float vout;
float vout1;
int redLED = 7;
int greenLED =3;
int gasSensor;
int IRsensor;
int piezo =4;

void setup()
{
pinMode (A0, INPUT);
pinMode (A1, INPUT);
pinMode (A2, INPUT);
pinMode (redLED, OUTPUT);
pinMode (greenLED, OUTPUT);
pinMode (piezo, OUTPUT);
Serial.begin(9600);
}

void loop()


{
vout=analogRead(A1);

vout1= (vout/1023)*5000;

temp (vout1-500)/10;

gasSensor=analogRead (A0); 

IRsensor = analogRead (A2);
	
	
if (gasSensor>=200 || IRsensor>=100|| temp>90)
{
digitalWrite (piezo, HIGH); 
digitalWrite (redLED, HIGH); 
digitalWrite (greenLED, LOW);
delay(1000);
}
else
{
digitalWrite (piezo, LOW);
digitalWrite (greenLED, HIGH);
digitalWrite (redLED, LOW);
Serial.print("safe");
Serial.println();
delay(1000);
}
if (gasSensor>=200)
{
Serial.print("smoke detected");
Serial.print (" ");
Serial.print (" ");
Serial.print ("Gas sensor = "); 
Serial.print(" ");
Serial.print (gasSensor);
Serial.println();
}
if (temp>=90)
{
Serial.print("FIRE DETECTED");
Serial.print (" ");
Serial.print (" ");
Serial.print ("TEMP in cel = ");
Serial.print(" "); 
Serial.print (temp);
Serial.println();
}
if (IRsensor>=100)
{
Serial.print ("Flame Detected");
Serial.print (" ");
Serial.print (" ");
Serial.print ("IR= ");
Serial.print(" "); 
Serial.print (IRsensor);
Serial.println();
}
}
	
