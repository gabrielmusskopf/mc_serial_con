/**
 * Server
 * It is intended to run on the Arduino platform, therefore it relies on specific library functions
 */

#define CLIENT_1_IN 	8		// Client 1 button
#define CLIENT_2_IN 	9		// Client 2 button
#define CLIENT_3_IN 	10		// Client 3 button
#define SERIAL_OUT		11		// Serial output
#define CS_1			13		// Client 1 Chip Select
#define TOGGLE_LED_CMD	"T"		// Serial Command

class Client {
  
  private:
  	int csPin;
  	int inputPin;
    int wasPressed;
  
  void logToggled() {
  	Serial.print("Client pin ");
    Serial.print(csPin);
    Serial.println(" toggled"); 
  }
  
  void initialize() {
    pinMode(inputPin, INPUT);
    pinMode(csPin, OUTPUT);
  }
  
  public:
  Client(int cs, int input) {
  	csPin = cs;
    inputPin = input;
    wasPressed = 0;
    
    initialize();
  }
  
  void execute() {
    int in;
  
    while(digitalRead(CLIENT_1_IN) && wasPressed) {}
  
    in = digitalRead(CLIENT_1_IN);
    wasPressed = 0;

    if (in) {
      wasPressed = 1;
      logToggled();
      //Serial.println(TOGGLE_LED_CMD);
    }
  }
};

#define CLIENTS_LEN 1
Client clients[] = {Client(CLIENT_1_IN, CS_1)};

void setup() {
  // Client pins are defined at construction
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < CLIENTS_LEN; i++) {
    clients[i].execute();
  }
}

