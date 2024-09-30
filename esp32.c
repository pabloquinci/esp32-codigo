// constants won't change
const int buttonPin = 7; // ESP32connected to button's pin
const int LEDPin    = 5; // ESP32 pin connected to LED's pin
const int LEDPin2    = 6; // ESP32 pin connected to LED's pin
const int LEDPin3    = 8;
// variables will change:
int ledState = HIGH;     // the current state of LED
int ledStateAmarillo = LOW;     // the current state of LED
int ledStateVerde = LOW;     // the current state of LED
int lastButtonState;    // the previous state of button
int currentButtonState; // the current state of button
void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(buttonPin, INPUT_PULLUP); // set ESP32 pin to input pull-up mode
  pinMode(LEDPin, OUTPUT);          // set ESP32 pin to output mode
  pinMode(LEDPin2, OUTPUT);          // set ESP32 pin to output mode
  pinMode(LEDPin3, OUTPUT);
  currentButtonState = digitalRead(buttonPin);
}
void loop() {
  lastButtonState    = currentButtonState;      // save the last state
  currentButtonState = digitalRead(buttonPin); // read new state
  digitalWrite(LEDPin, ledState); 
    digitalWrite(LEDPin2, ledStateAmarillo); 
    digitalWrite(LEDPin3, ledStateVerde); 
  if(lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println("The button is pressed");
    // toggle state of LED
    ledState = !ledState;
    // control LED arccoding to the toggled state
    

    delay(1000);
    ledState = !ledState;
    ledStateAmarillo = !ledStateAmarillo;
    // control LED arccoding to the toggled state
    digitalWrite(LEDPin, ledState); 
    digitalWrite(LEDPin2, ledStateAmarillo);

    delay(1000);
    ledStateAmarillo = !ledStateAmarillo;
    ledStateVerde=!ledStateVerde;
    ledState=LOW;
    // control LED arccoding to the toggled state
    digitalWrite(LEDPin2, ledStateAmarillo); 
    digitalWrite(LEDPin3, ledStateVerde);
    digitalWrite(LEDPin, ledState); 

    delay(3000);

    ledStateVerde=!ledStateVerde;
    // control LED arccoding to the toggled state
    digitalWrite(LEDPin3, ledStateVerde);
    delay(1000);
 
  }
      ledState=HIGH;
      digitalWrite(LEDPin, ledState);

  delay(100);
}