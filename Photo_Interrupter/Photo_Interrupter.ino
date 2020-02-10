
int led = 8;
int photoPin = 3;
volatile byte state = LOW;
int trigger = 0;

void setup() {

  pinMode(led, OUTPUT);
  pinMode(photoPin, INPUT_PULLUP);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(photoPin), on, CHANGE);//attaches an interrupt to the 3 pin that runs the on function when activated by a change in the photo interrupter input
  
}

void loop() {
digitalWrite(led, state);//turns the LED on or off


}

void on(){
	state = !state;//changes the state from on to off or vice versa
	trigger++;//the number of times the photo interrupter has been triggered
	Serial.println(trigger);//prints the number of times the photo interrupter has been triggered
}
