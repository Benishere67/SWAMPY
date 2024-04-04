#define POTENTIOMETER_PIN A7
#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A2 // Arduino pin connected to VRY pin

const int buttonPin = A6;

int xValue = 0; // To store value of the X axis
int yValue = 0; // To store value of the Y axis
int buttonState = 0;
int POTvalue = 0;

void setup() 
{
  Serial.begin(9600);

  pinMode(buttonPin, INPUT);
}

void loop() {

  buttonState = digitalRead(buttonPin);
  POTvalue = analogRead(POTENTIOMETER_PIN);
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);
  
  
  //Serial.println(buttonState,POTvalue, xValue, yValue);
  //Serial.println(POTvalue);
  Serial.println(buttonState);
  Serial.print("  ");
  Serial.print(xValue);
  Serial.print("  ");
  Serial.print(yValue);
  
  delay(100);
}
