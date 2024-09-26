//MASTER
#include<SoftwareSerial.h>

SoftwareSerial kirim(4,3);
int bt = A0;
int enPin = 2;

void setup(){
    kirim.begin(9600);
    pinMode(enPin, OUTPUT);
    pinMode(bt, INPUT_PULLUP);
    delay(10);
    digitalWrite(enPin, HIGH);
}
void loop(){
    kirim.write(digitalRead(bt));
    delay(100);
}