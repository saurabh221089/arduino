const int pwmpin1 = 11;
const int pwmpin2 = 10;
const int pwmpin3 = 9;
const int ledpin = 13;
const int pwmmain = 3;

void setup()
{
 pinMode(pwmpin1, OUTPUT);
 pinMode(pwmpin2, OUTPUT);
 pinMode(pwmpin3, OUTPUT);
 pinMode(ledpin, OUTPUT);
 pinMode(pwmmain, OUTPUT);
 analogWrite(pwmmain, 10);
}

void loop()
{
 digitalWrite(ledpin, LOW);
 first:
 for(int i=255; i>1; i--)
 {
 analogWrite(pwmpin1, i);
 delay(10);
 if (i=3){goto second;}
 }
 second:
 for(int j=255; j>1; j--)
 {
 analogWrite(pwmpin2, j);
 delay(10);
 if (j=2){goto third;}
 }
 third:
 for(int k=255; k>1; k--)
 {
 analogWrite(pwmpin3, k);
 delay(10);
//if (k=1000){goto first;}
 }
}
