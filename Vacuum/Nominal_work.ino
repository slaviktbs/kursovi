// This program checks whether the Arduino board is working correctly. This is necessary in order to compare the board's performance before and after the experiment. 

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("I survived the vacuum chamber outgassing test!");
  delay(1000);
}
