
const char PIN_RS = 7;
const char PIN_E = 6;
const char PIN_D4 = 5;
const char PIN_D5 = 4;
const char PIN_D6 = 3;
const char PIN_D7 = 2;
const int LCD_DELAY_MS = 5;

unsigned long int tm1 = 0;


void lcdSend(bool isCommand, char data) {
    digitalWrite(PIN_RS, isCommand ? LOW : HIGH);
    delay(LCD_DELAY_MS);
    
    digitalWrite(PIN_D7, (data >> 7) & 1);
    digitalWrite(PIN_D6, (data >> 6) & 1);
    digitalWrite(PIN_D5, (data >> 5) & 1);
    digitalWrite(PIN_D4, (data >> 4) & 1);

    digitalWrite(PIN_E, HIGH);
    delay(LCD_DELAY_MS);
    digitalWrite(PIN_E, LOW);

    digitalWrite(PIN_D7, (data >> 3) & 1);
    digitalWrite(PIN_D6, (data >> 2) & 1);
    digitalWrite(PIN_D5, (data >> 1) & 1);
    digitalWrite(PIN_D4, (data >> 0) & 1);

    digitalWrite(PIN_E, HIGH);
    delay(LCD_DELAY_MS);
    digitalWrite(PIN_E, LOW);
}

void lcdCommand(char cmd) {
    lcdSend(true, cmd);
}

void lcdChar(const char chr) {
    lcdSend(false, (char)chr);
}

void lcdString(const char* str) {
    while(*str != '\0') {
        lcdChar(*str);
        str++;
    }
}

void setup() {
    pinMode(PIN_RS, OUTPUT);
    pinMode(PIN_E, OUTPUT);
    pinMode(PIN_D4, OUTPUT);
    pinMode(PIN_D5, OUTPUT);
    pinMode(PIN_D6, OUTPUT);
    pinMode(PIN_D7, OUTPUT);

    // 4-bit , 2 lines, 5x8 format
   lcdCommand(0b00001010); //functionSet
     
     // clear display
    lcdCommand(0b00000001); //clearDisplay
    
    // display
    lcdCommand(0b00000010);//returnHome
    
    // display on, cursor on, blink on
    lcdCommand(0b00001111);

    lcdCommand(0b10000000); // set address to 0x00
    lcdString("Hello World!!!");
    
    lcdCommand(0b11000000); // set address to 0x40
    lcdString("19-R!");
}

void loop() {
  if (millis() - tm1 > 5){
  tm1 = millis();}
}
