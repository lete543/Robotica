#ifndef Ultrasonicos_h
#define Ultrasonicos_h

//Classe do para leitura dos sensores Ultrasonico
#include<Ultrasonic.h>
//o erro ult
class Ultrasonicos {
  public:
    float resul;
    float resul1;
    float resul2;
    float resulf;

    //inicializador da biblioteca
    Ultrasonic* frente;
    Ultrasonic* esquerda;
    Ultrasonic* direita;

    Motores* motor;
    Giroscopio* gir;
    Pid* pid;

    Ultrasonicos(int trig, int echo, int trig2, int echo2, int trig3, int echo3, Motores* motoress, Giroscopio* giro, Pid* pidU) {
      motor = motoress;
      gir = giro;
      pid = pidU;
      frente = new Ultrasonic(trig, echo);
      esquerda = new Ultrasonic(trig2, echo2);
      direita = new Ultrasonic(trig3, echo3);
    }

    float erroUlt() {
      resul = frente->read();
      resul -= 5;
      resul *= 3;
      resul /= 10;
      if(resul>1) resul = 1;
      if(resul < 0.4) resul = 0;
      return   resul;
    }
    float Vdir(){
      resul1 = direita->read();
      return resul1;
    }
    float Vesq(){
      resul2 = esquerda->read();
      return resul2;
    }
    float Vfre(){
      resulf = frente->read();
      return resulf;
    }
    int edir(int a) {
      resul1 = direita->read();
      if (resul1  <= a) {
        return 1;
      }
      else {
        return 0;
      }
    }
    int eesq(int a1) {
      resul2 = esquerda->read();
      if (resul2 <= a1) {
        return 1;
      }
      else {
        return 0;
      }
    }

    int udir() {
            resul1 = direita->read();
            if (resul1  <= 12) {
              return 1;
            }
            else {
              return 0;
            }
    }
    int uesq() {
            resul2 = esquerda->read();
            if (resul2 <= 12) {
              return 1;
            }
            else {
              return 0;
            }
    }



//   
 void desvio(int res) {
      if (res == 1) {
        gir->Mgiro(90);
        for (int c1 = 0; c1 < 2; c1++) {
          while (true) {
            if (udir() == 0) {
              if (udir() == 0) {
                break;
              }
            }
           motor->Pfrente();
            delay(700);
            //motor->frear();
          }
          gir->Mgiro(-90);

          while (true) {
            //Serial.println(udir());
            if (udir() == 1) {
             // motor->frear();
              udir();
              if (udir() == 1) {
                break;
              }
            }
            motor->Pfrente();
            delay(700);
//            motor->frear();
          }
        }
        gir->Mgiro(90);
      }
      else {
        gir->Mgiro(-90);
        motor->frear();
        // erial.p2rintln(udir());
        for (int c1 = 0; c1 < 2; c1++) {

          while (true) {
            if (uesq() == 0) {
              motor->frear();
              uesq();
              if (uesq() == 0) {
                break;
              }
            }
            pid->calculo(0, 10);
            delay(700);
            motor->frear();
          }
          pid->calculo(0, 10);
          delay(400);
          motor->frear();
          gir->Mgiro(90);

          while (true) {
            if (uesq() == 1) {
              motor->frear();
              uesq();
              if (uesq() == 1) {
                break;
              }
            }
            pid->calculo(0, 18);
            delay(700);
            motor->frear();
          }
        }
        gir->Mgiro(-90);
      }
    }
};
#endif
