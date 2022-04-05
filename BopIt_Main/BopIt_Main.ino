// Defining constants for pins
// Input Pins
int LightSensor = A5; // Light Sensor input
int StartButton = 2; // Button to start a new game
int ResetButton = 4; // Button to reset the game

// Output Pins
int GreenLED = 1; // LED for when the player gets an action correct
int RedLED = 0; // LED for when the player gets on action incorrect
//int bcdA = // Output for the BCD A input
//int bcdB = // Output for the BCD B input
//int bcdC = // Output for the BCD C input
//int bcdD = // Output for the BCD D input
//int Speaker = // Output to the speaker


int APWM1 = 9;
int APWM2 = 10;

// Variable Declarations
// Enumeration for States of the FSM 
enum State_Type {resetState, startState, actionSelection, actionProcessing, completion}; // 
State_Type FSMState = resetState; // Current state of the FSM :: initialized to the reset state

void setup() {
  // Input Pins
  pinMode(LightSensor, INPUT);
  pinMode(StartButton, INPUT);
  pinMode(ResetButton, INPUT);
  // Output Pins
  pinMode(GreenLED, OUTPUT);
  pinMode(RedLED, OUTPUT);
}

void loop() {
  //********************** FSM Implementation ***************************************
  
  // switch case to determine the actions of each state
  switch (FSMState) {
    // Reset State
    case resetState :
      // Transition to Start State if startButton is pressed
      if (digitalRead(StartButton) == HIGH) {
        FSMState = startState;
      }
      // Stay in Reset State if startButton is not pressed
      else {
        FSMState = resetState;
      }
    break;
    // Start State
    case startState :

    break;
    // Action Selection State
    case actionSelection :

    break;
    // Action Processing State
    case actionProcessing :

    break;
    // Completion State
    case completion :
    
    break; 
  }
  //*********************************************************************************  
}
