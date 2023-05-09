#include <EEPROM.h>

#define ARRAY_SIZE 100

// Define custom variable structure
struct CustomVariable {
  int16_t var1 : 12;   // 12-bit variable
  uint32_t var2 : 20;   // 20-bit variable
};

CustomVariable myArray[ARRAY_SIZE];   // Array of custom variables

void setup() {
  Serial.begin(9600);

  // Initialize EEPROM
  EEPROM.begin(sizeof(myArray));

  for (int j = 0; j < ARRAY_SIZE; j++) {
    myArray[j].var1 = j*100;
    myArray[j].var2 = j*10000;
  }

  // Write array to EEPROM
  for (int i = 0; i < ARRAY_SIZE; i++) {
    EEPROM.put(i * sizeof(CustomVariable), myArray[i]);
  }

  // Read array from EEPROM
  for (int i = 0; i < ARRAY_SIZE; i++) {
    EEPROM.get(i * sizeof(CustomVariable), myArray[i]);
  }

  // Convert array back into custom variables and print to serial monitor
  for (int i = 0; i < ARRAY_SIZE; i++) {
    Serial.print("Variable ");
    Serial.print(i);
    Serial.print(": var1 = ");
    Serial.print(myArray[i].var1);
    Serial.print(", var2 = ");
    Serial.println(myArray[i].var2);
  }
}

void loop() {
  // Do nothing
}
