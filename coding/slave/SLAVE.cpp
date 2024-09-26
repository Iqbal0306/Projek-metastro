//SLAVE
#include<SoftwareSerial.h>
#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

SoftwareSerial terima(2,3);

int enPin = 4;
int lebar = 128;
int tinggi = 64;
Adafruit_SSD1306 oled(lebar,tinggi, &Wire, -1);

void setup() {
    Kirim.begin(9600);
    oled.begin(SSD1306_SWITCHAPVCC, 0x3C);
    pinMode(enPin, OUTPUT);
    delay(10);
    digitalWrite(enPin, LOW);
}
void loop (){
    if(terima.available)(){
        int button = terima.read();
        if (button == 0){
            tampilOLED("AKSES", "DIBUKA");
        }else{
            tampilOLED("AKSES", "DITUTUP")
        }
    }
}
void tampilOLED(string p, string q){
    oled.cleanDisplay();
    oled.setTextSize(2);
    oled.setTextColor(WHITE);
    oled.setCursor(25,15);
    oled.println(p);
    oled.setCursor(25,33);
    oled.println(q);
    oled.Display();
    
}