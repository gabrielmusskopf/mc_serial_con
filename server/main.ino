/**
 * Server
 * It is intended to run on the Arduino platform, therefore it relies on specific library functions
 */


#define CLIENT_1_IN 	8		// Client 1 button
#define CLIENT_2_IN 	9		// Client 2 button
#define CLIENT_3_IN 	10		// Client 3 button
#define CS_1			2		// Client 1 Chip Select
#define CS_2			3		// Client 2 Chip Select
#define CS_3			4		// Client 3 Chip Select
#define TOGGLE_LED_CMD	"T"		// Serial Command

class Client {
  
  private:
  	int csPin;
  	int inputPin;
    int cs = 0;
    int wasPressed = 0;
  
  void logToggled() {
  	Serial.print("Client pin ");
    Serial.print(csPin);
    Serial.println(" toggled. Wrinting to serial"); 
  }
  
  void initialize() {
    pinMode(inputPin, INPUT);
    pinMode(csPin, OUTPUT);
  }
  
  public:
  Client(int input, int cs) {
  	csPin = cs;
    inputPin = input;
    
    initialize();
  }
  
  void execute() {
    int in;
  
    while(digitalRead(inputPin) && wasPressed) {}
  
    in = digitalRead(inputPin);
    wasPressed = 0;

    if (in) {
      wasPressed = 1;
      cs = !cs;
      logToggled();
      digitalWrite(csPin, cs);
      Serial.println(TOGGLE_LED_CMD);
    }
  }
};

#define CLIENTS_LEN 3
Client clients[] = { 
  Client(CLIENT_1_IN, CS_1), 
  Client(CLIENT_2_IN, CS_2), 
  Client(CLIENT_3_IN, CS_3) 
};

void setup() {
  // Client pins are defined at construction
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < CLIENTS_LEN; i++) {
    clients[i].execute();
  }
}

