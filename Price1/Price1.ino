//We always have to include the library
#include "LedControl.h"
LedControl lc=LedControl(8,7,6,1);

void setup() {
  Serial.begin(9600);
lc.shutdown(0,false); /*The MAX72XX is in power-saving mode on startup,we have to do a wakeup call*/
lc.setIntensity(0,8);/* Set the brightness to a medium values */
lc.clearDisplay(0);/* and clear the display */
for (int i = 0; i < 3; i++) {
        lc.setDigit(0, i, i + 1, false);
    }
}

void printNumber1(int v) {
    int ones;
    int tens;
    int hundreds;
    boolean negative;  

    if(v < -999 || v > 999) 
       return;
    if(v<0) {
        negative=true;
        v=v*-1;
    }
    ones=v%10;
    v=v/10;
    tens=v%10;
    v=v/10;
    hundreds=v;     
    //Now print the number digit by digit
    lc.setDigit(0,0,(byte)hundreds,true);
    lc.setDigit(0,1,(byte)tens,false);
    lc.setDigit(0,2,(byte)ones,false);
}

void loop() { 
    printNumber1(877); 
}
