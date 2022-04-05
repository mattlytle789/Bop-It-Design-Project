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
// FSM Variables
enum State_Type {resetState, startState, actionSelection, actionProcessing, completion}; // Enumeration for States of the FSM 
State_Type FSMState = resetState; // Current state of the FSM :: initialized to the reset state

// Action Variables
enum Action_Type {push, cover, toss}; // Enumeration for possible actions 
Action_Type currAction; // Current action that needs to be performed
Action_Type possibleAction[3] = {push, cover, toss}; // Possible actions that can be chosen :: Used to determine the next action 
int nextActionIndex; // Random number that will be used to index the possibleAction array for a new action
Action_Type nextAction; // Next action to be performed by the user

void setup() {
  // Input Pins
  pinMode(LightSensor, INPUT);
  pinMode(StartButton, INPUT);
  pinMode(ResetButton, INPUT);
  // Output Pins
  pinMode(GreenLED, OUTPUT);
  pinMode(RedLED, OUTPUT);
  // Setting up random number generator
  randomSeed(analogRead(0));
  // FOR DEBUGGING
  Serial.begin(9600);
}

void loop() {
  //********************** FSM Implementation ***************************************
  
  // switch case to determine the actions of each state
  switch (FSMState) {
    // Reset State
    case resetState :
      // FOR DEBUGGING
      Serial.println(FSMState);
      
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
      // FOR DEBUGGIN
      Serial.println(FSMState);
      
      // Add TTS to countdown from 3 for the start of the game
      delay(3000);
      // transition to Action Selection State
      FSMState = actionSelection; 
    break;
    // Action Selection State
    case actionSelection :
      // FOR DEBUGGING
      Serial.println(FSMState);
      
      // generate a random number from 0 to 2 to index possibleAction array
      nextActionIndex = random(0,2);
      nextAction = possibleAction[nextActionIndex];

      // assign the new action to the currAction variable
      currAction = nextAction;
      // transition to Action Processing State
      FSMState = actionProcessing;
    break;
    // Action Processing State
    case actionProcessing :
      // announce new action 

      // wait for input from sensors

      // determine correctness of input

      // If wrong :: transition to completion state and display Red LED

      // If correct :: transition to action selection state and display Green LED
    break;
    // Completion State
    case completion :
    
    break; 
  }
  //*********************************************************************************  
}
