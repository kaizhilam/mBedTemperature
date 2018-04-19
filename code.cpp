#include "mbed.h"
#include "LM75B.h"
#include "C12832.h" //this includes the mBed shield

C12832 lcd(p5, p7, p6, p8, p11);

LM75B sensor(p28,p27);
Serial pc(USBTX,USBRX);

int main ()
{
    if (sensor.open()) {
        printf("Temperature device detected!\n");
        while (1) {
            lcd.cls();
            lcd.locate(0,3);
            lcd.printf("Temp = %.3f C\n", (float)sensor);
            //lcd.print((char)22);
            wait(1.0);
        }
    } else {
        error("Device not detected!\n");
    }
}
