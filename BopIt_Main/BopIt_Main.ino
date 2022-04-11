// Defining constants for pins
// Input Pins
int LightSensor = A5; // Light Sensor input
int StartButton = 2; // Button to start a new game
//int ResetButton = 3; // Button to reset the game
int PushButton = 12; // Button used for the Psuh It action

// Output Pins
int GreenLED = 1; // LED for when the player gets an action correct
int RedLED = 0; // LED for when the player gets on action incorrect
int bcdTensA = 4; // Output for the BCD A input Tens
int bcdTensB = 5; // Output for the BCD B input Tens
int bcdTensC = 6; // Output for the BCD C input Tens
int bcdTensD = 7; // Output for the BCD D input Tens
int bcdOnesA = 8; // Output for the BCD A input Ones
int bcdOnesB = 9; // Output for the BCD B input Ones 
int bcdOnesC = 10; // Output for the BCD C input Ones
int bcdOnesD = 11; // Output for the BCD D input Ones
int Speaker = A0; // Output to the speaker


//int APWM1 = 9;
//int APWM2 = 10;

// Variable Declarations
// Enumeration for States of the FSM 
enum State_Type {resetState, startState, actionSelection, actionProcessing, completion}; // 
State_Type FSMState = resetState; // Current state of the FSM :: initialized to the reset state

// Enumeration for possible actions 
enum Action_Type {push, cover, toss};
Action_Type currAction; // Current action that needs to be performed
Action_Type possibleAction[3] = {push, cover, toss}; // Possible actions that can be chosen :: Used to determine the next action 
int nextActionIndex; // random number to index the possibleAction array to choose the next action
Action_Type nextAction; // next action that is to be performed by the player
bool actionCompletedFlag = false; // Flag to mark when an action has been completed
Action_Type actionCompleted; // action that the player completed
bool actionCorrect = false; // Flag to mark if the action the player completed was correct or incorrect :: Correct = true, Incorrect = false

// Misc Variables
float timeLimit = 0; // Time limit for each action :: initialized to specified value
short score = 0; // Score for the player 
short scoreTens = 0; // Stores the tens digit value of the score
short scoreOnes = 0; // Store the ones digit value of the score
int tensInputs[4] = {bcdTensD, bcdTensC, bcdTensB, bcdTensA}; // holds the possible input pins for the Tens BCD
int onesInputs[4] = {bcdOnesD, bcdOnesC, bcdOnesB, bcdOnesA}; // holds the possible input pins for the Ones BCD
byte BCD[10][4] = {{0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1},{1,0,0,0},{1,0,0,1}}; // Used to convert the score into a BCD value

void setup() {
  // Input Pins
  pinMode(LightSensor, INPUT);
  pinMode(StartButton, INPUT_PULLUP); // setting to a pull up input :: ON when LOW, OFF when HIGH
  //pinMode(ResetButton, INPUT);
  pinMode(PushButton, INPUT_PULLUP); // setting to a pull up input :: ON when LOW, OFF when HIGH
  // Output Pins
  pinMode(GreenLED, OUTPUT);
  pinMode(RedLED, OUTPUT);
  pinMode(bcdTensA, OUTPUT);
  pinMode(bcdTensB, OUTPUT);
  pinMode(bcdTensC, OUTPUT);
  pinMode(bcdTensD, OUTPUT);
  pinMode(bcdOnesA, OUTPUT);
  pinMode(bcdOnesB, OUTPUT);
  pinMode(bcdOnesC, OUTPUT);
  pinMode(bcdOnesD, OUTPUT);
  // setup for random number generation
  randomSeed(analogRead(11));
  // FOR DEBUGGING
  Serial.begin(9600);
}

void loop() {
  //********************** FSM Implementation ***************************************
  
  // switch case to determine the actions of each state
  switch (FSMState) {
    // FOR DEBUGGING
    Serial.println(FSMState);
    
    // Reset State
    case resetState :
      // Setting outputs to low values
      digitalWrite(GreenLED, LOW);
      digitalWrite(RedLED, LOW);
      for (int i = 0; i < 4; i++) {
        digitalWrite(tensInputs[i], BCD[0][i]);
        digitalWrite(onesInputs[i], BCD[0][i]);
      }
      // Transition to Start State if startButton is pressed
      if (digitalRead(StartButton) == LOW) {
        FSMState = startState;
      }
      // Stay in Reset State if startButton is not pressed
      else {
        FSMState = resetState;
      }
    break;
    // Start State
    case startState :
      // FOR DEBUGGING
      Serial.println(FSMState);
      
      // Add TTS to countdown from 3 for the start of the game
      // Looping for three seconds to give player a countdown
      for (int i = 3; i > 0; i--) {
        // FOR DEBUGGING
        Serial.println(i);

        // TTS Code
        
        // waiting for 1 second 
        delay(1000); 
      }
      // Transitioning to Action Selection State
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
      // FOR DEBUGGING
      Serial.println(FSMState);
      
      // announce new action 
      
      // wait for input from sensors
      while (!actionCompletedFlag) {
        if (digitalRead(PushButton) == LOW) { // If the push action was completed
          actionCompletedFlag  = true;
          actionCompleted = push;
        }
        else if (true) { // If the toss action was completed
          
        }
        else if (true) { // if the cover action was completed
          
        }
      }
      // determine correctness of input
      if (actionCompleted == currAction) {
        actionCorrect = true;
      }
      else {
        actionCorrect = false;
      }
      // If correct :: transition to action selection state, display Green LED, increment score, and decrement time limit
      if (actionCorrect && score < 100) {
        FSMState = actionSelection;
        digitalWrite(GreenLED, HIGH);
        delay(500);
        digitalWrite(RedLED, LOW);
        score++;
      }
      // If wrong, time limit reached, or score = 99 :: transition to completion state and display Red LED
      else {
        FSMState = completion;
        digitalWrite(RedLED, HIGH);
        delay(500);
        digitalWrite(RedLED, LOW);
      }
      // Write score to seven seg display
      scoreOnes = score%10;
      scoreTens = score/10;
      for (int i = 0; i < 4; i++) {
        digitalWrite(tensInputs[i], BCD[scoreTens][i]);
        digitalWrite(onesInputs[i], BCD[scoreOnes][i]);
      }
      // Resetting action flags
      actionCompletedFlag = false; 
      actionCorrect = false; 
    break;
    // Completion State
    case completion :
      // FOR DEBUGGING
      Serial.println(FSMState);
    
    break; 
  }
  //*********************************************************************************  
}
