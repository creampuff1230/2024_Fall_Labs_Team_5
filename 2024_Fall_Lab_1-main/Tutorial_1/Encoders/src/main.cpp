#include <Arduino.h>
#include <Encoder.h>

const unsigned int M1_ENC_A = 39;
const unsigned int M1_ENC_B = 38;
const unsigned int M2_ENC_A = 37;
const unsigned int M2_ENC_B = 36;


void setup() {
  // Stop the right motor by setting pin 14 low
  // this pin floats high or is pulled
  // high during the bootloader phase for some reason
  pinMode(14, OUTPUT);
  digitalWrite(14, LOW);
  delay(100);


  Serial.begin(115200);
}

void loop() {

  Encoder enc1(M1_ENC_A, M1_ENC_B);
  Encoder enc2(M2_ENC_A, M2_ENC_B);

  while(true) {
    long enc1_value = enc1.read();
    Serial.print("left: ");
    Serial.print(enc1_value);
    delay(500);
  
    long enc2_value = enc2.read();
    Serial.print("\t\t right: ");
    Serial.print(enc2_value);
    Serial.print("\n");
    delay(500);

  }
}
