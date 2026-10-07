#ifndef Garra_h
#define Garra_h

#include <Servo.h>

class Garra {
  private:
    Servo Sabre;
    Servo Sdesce;
    int pos = 0;
  public:
    Garra() {
      pinMode(9, OUTPUT);
      pinMode(10, OUTPUT);
    }
    void garraC() {
      Sdesce.attach(9);  // attaches the servo on pin 9 to the servo object
      Sabre.attach(10);
      fecha();
      sobe();
    }
    void desce() {
      //  9
      for (pos = Sdesce.read(); pos <= 175; pos += 1) { // goes from 180 degrees to 0 degrees
        Sdesce.write(pos);              // tell servo to go to position in variable 'pos'
        delay(9);
      }
      //delay(1000);
    }
    void sobe() {
      for (pos = Sdesce.read(); pos >= 10; pos -= 1) {
        Sdesce.write(pos);
        delay(9);

      }
     // delay(1000);
    }
    void fecha() {
      for (pos = Sabre.read(); pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        Sabre.write(pos);              // tell servo to go to position in variable 'pos'
        delay(9);                       // waits 15ms for the servo to reach the position
      }
//delay(1000);
    }
    void abre() {
      for (pos = Sabre.read(); pos >= 80; pos -= 1) { // goes from 180 degrees to 0 degrees
        Sabre.write(pos);              // tell servo to go to position in variable 'pos'
        delay(9);                       // waits 15ms for the servo to reach the position
      }
      //delay(1000);

    }
    void descar(){
         for (pos = Sdesce.read(); pos <= 145; pos += 1) { // goes from 180 degrees to 0 degrees
        Sdesce.write(pos);              // tell servo to go to position in variable 'pos'
        delay(9);
      }
            for (pos = Sabre.read(); pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
        Sabre.write(pos);              // tell servo to go to position in variable 'pos'
        delay(9);                       // waits 15ms for the servo to reach the position
      }
            for (pos = Sdesce.read(); pos >= 100; pos -= 1) {
        Sdesce.write(pos);
        delay(9);

      }
               for (pos = Sdesce.read(); pos <= 145; pos += 1) { // goes from 180 degrees to 0 degrees
        Sdesce.write(pos);              // tell servo to go to position in variable 'pos'
        delay(9);
      }
    }
};
#endif
