#ifndef Sala3_h
#define Sala3_h
class Sala3 {

  public:

    Motores* motor;
    Giroscopio* gir;
    Pid* pid;
    Ultrasonicos* ult;
    Garra* garra;

    Sala3(Motores* motoress, Giroscopio* giro, Pid* pids, Garra* garras, Ultrasonicos* ults) {
      motor = motoress;
      gir = giro;
      pid = pids;
      ult = ults;
      garra = garras;
    }

    float ref;

    void sala() {
      motor->Pfrente();
      delay(1700);
      //motor->frear();
      gir->Mgiro(90);
      // ref = ult->Vdir();
      //  gir->Mgiro(-135);
      motor->Ptras();
      delay(1900);
      motor->frear();
            garra->abre();
      garra->desce();
      //garra->desce();
      motor->Pfrente();
      delay(5200);
      motor->frear();
      motor->Ptras();
      garra->fecha();
      motor->frear();
      garra->sobe();
      //delay(200);
      //pidSala3(4500);
      //garra->fecha();
      garra->sobe();
      motor->Pfrente();
      delay(1600);
      motor->frear();
      gir->Mgiro(45);
      motor->Pfrente();
      delay(200);
      //pidSala3(200);
      motor->frear();
      if (ult->Vfre() <= 8) {
        gir->Mgiro(-90);
        //Serial.print(ult->eesq(5));
        // Serial.println(" esq");
        if (ult->eesq(5) == 0) {
          gir->Mgiro(90);
          garra->descar();
          delay(800);
          garra->fecha();
          garra->sobe();
          //talvez trocar a ordem
          motor->Ptras();
          delay(1000);
          gir->Mgiro(180);
          motor->Ptras();
          delay(1200);
          motor->frear();
          gir->Mgiro(45);
          garra->abre();
          garra->desce();
          motor->Pfrente();
          delay(800);
          garra->fecha();
          garra->sobe();
          gir->Mgiro(-90);
          //
          motor->Ptras();
          delay(3000);
          motor->frear();
          garra->desce();
          garra->abre();
          motor->Pfrente();
          delay(6500);
          garra->fecha();
          garra->sobe();
          motor->frear();
          gir->Mgiro(180);
          motor->Ptras();
          delay(1200);
          motor->frear();
          motor->Pfrente();
          delay(7200);
          gir->Mgiro(90);
          motor->Pfrente();
          delay(3000);
          gir->Mgiro(-45);
          garra->descar();
          delay(1000);
          garra->fecha();
          garra->sobe();
          motor->Ptras();
          delay(1000);
          gir->Mgiro(180);
          motor->Ptras();
          delay(1200);
          motor->frear();
          gir->Mgiro(45);
          garra->abre();
          garra->desce();
          motor->Pfrente();
          delay(1800);
          garra->fecha();
          garra->sobe();
          gir->Mgiro(-90);
          //
          motor->Ptras();
          delay(3000);
          motor->frear();
          garra->desce();
          garra->abre();
          motor->Pfrente();
          delay(7500);
          garra->fecha();
          garra->sobe();
          motor->frear();
          gir->Mgiro(180);
          motor->Ptras();
          delay(1200);
          motor->frear();
          motor->Pfrente();
          delay(7500);
          gir->Mgiro(90);
          motor->Pfrente();
          delay(5000);
          gir->Mgiro(-45);
        }
      }
      else {
        gir->Mgiro(-135);
        //  gir->Mgiro(-135);
        motor->Ptras();
        delay(1900);
        motor->frear();
        garra->desce();
        garra->abre();
        //garra->desce();
        motor->Pfrente();
        delay(5200);
        motor->frear();
        motor->Ptras();
        garra->fecha();
        motor->frear();
        garra->sobe();
        //delay(200);
        //pidSala3(4500);
        //garra->fecha();
        garra->sobe();
        motor->Pfrente();
        delay(1600);
        motor->frear();
        gir->Mgiro(45);
        motor->Pfrente();
        delay(200);
        //pidSala3(200);
        motor->frear();
        if (ult->Vfre() <= 8) {
          gir->Mgiro(-90);
          //Serial.print(ult->eesq(5));
          // Serial.println(" esq");
          if (ult->eesq(5) == 0) {
            gir->Mgiro(90);
            garra->descar();
            delay(800);
            garra->fecha();
            garra->sobe();
            //talvez trocar a ordem
            motor->Ptras();
            delay(1000);
            gir->Mgiro(180);
            motor->Ptras();
            delay(1200);
            motor->frear();
            gir->Mgiro(45);
            garra->abre();
            garra->desce();
            motor->Pfrente();
            delay(800);
            garra->fecha();
            garra->sobe();
            gir->Mgiro(-90);
            //
            motor->Ptras();
            delay(3000);
            motor->frear();
            garra->desce();
            garra->abre();
            motor->Pfrente();
            delay(6500);
            garra->fecha();
            garra->sobe();
            motor->frear();
            gir->Mgiro(180);
            motor->Ptras();
            delay(1200);
            motor->frear();
            motor->Pfrente();
            delay(7200);
            gir->Mgiro(90);
            motor->Pfrente();
            delay(3000);
            gir->Mgiro(-45);
            garra->descar();
            delay(1000);
            garra->fecha();
            garra->sobe();
            motor->Ptras();
            delay(1000);
            gir->Mgiro(180);
            motor->Ptras();
            delay(1200);
            motor->frear();
            gir->Mgiro(45);
            garra->abre();
            garra->desce();
            motor->Pfrente();
            delay(1800);
            garra->fecha();
            garra->sobe();
            gir->Mgiro(-90);
            //
            motor->Ptras();
            delay(3000);
            motor->frear();
            garra->desce();
            garra->abre();
            motor->Pfrente();
            delay(7500);
            garra->fecha();
            garra->sobe();
            motor->frear();
            gir->Mgiro(180);
            motor->Ptras();
            delay(1200);
            motor->frear();
            motor->Pfrente();
            delay(7500);
            gir->Mgiro(90);
            motor->Pfrente();
            delay(5000);
            gir->Mgiro(-45);
          }
        }
        else {
          gir->Mgiro(-135);
          //  gir->Mgiro(-135);
          motor->Ptras();
          delay(1900);
          motor->frear();
          garra->desce();
          garra->abre();
          //garra->desce();
          motor->Pfrente();
          delay(5200);
          motor->frear();
          motor->Ptras();
          garra->fecha();
          motor->frear();
          garra->sobe();
          //delay(200);
          //pidSala3(4500);
          //garra->fecha();
          garra->sobe();
          motor->Pfrente();
          delay(1600);
          motor->frear();
          gir->Mgiro(45);
          motor->Pfrente();
          delay(200);
          //pidSala3(200);
          motor->frear();
          //Serial.println(ult->Vfre());
          if (ult->Vfre() <= 8) {
            gir->Mgiro(-90);
            //Serial.print(ult->eesq(5));
            // Serial.println(" esq");
            if (ult->eesq(5) == 0) {
              gir->Mgiro(90);
              garra->descar();
              delay(800);
              garra->fecha();
              garra->sobe();
              //talvez trocar a ordem
              motor->Ptras();
              delay(1000);
              gir->Mgiro(180);
              motor->Ptras();
              delay(1200);
              motor->frear();
              gir->Mgiro(45);
              garra->abre();
              garra->desce();
              motor->Pfrente();
              delay(800);
              garra->fecha();
              garra->sobe();
              gir->Mgiro(-90);
              //
              motor->Ptras();
              delay(3000);
              motor->frear();
              garra->desce();
              garra->abre();
              motor->Pfrente();
              delay(6500);
              garra->fecha();
              garra->sobe();
              motor->frear();
              gir->Mgiro(180);
              motor->Ptras();
              delay(1200);
              motor->frear();
              motor->Pfrente();
              delay(7200);
              gir->Mgiro(90);
              motor->Pfrente();
              delay(3000);
              gir->Mgiro(-45);
              garra->descar();
              delay(1000);
              garra->fecha();
              garra->sobe();
              motor->Ptras();
              delay(1000);
              gir->Mgiro(180);
              motor->Ptras();
              delay(1200);
              motor->frear();
              gir->Mgiro(45);
              garra->abre();
              garra->desce();
              motor->Pfrente();
              delay(1800);
              garra->fecha();
              garra->sobe();
              gir->Mgiro(-90);
              //
              motor->Ptras();
              delay(3000);
              motor->frear();
              garra->desce();
              garra->abre();
              motor->Pfrente();
              delay(7500);
              garra->fecha();
              garra->sobe();
              motor->frear();
              gir->Mgiro(180);
              motor->Ptras();
              delay(1200);
              motor->frear();
              motor->Pfrente();
              delay(7500);
              gir->Mgiro(90);
              motor->Pfrente();
              delay(5000);
              gir->Mgiro(-45);
              // Serial.println("ok");
            }
          }
          // delay(3000);
        }
      }
      //Serial.println(ult->Vesq());
    }
    //

    //    pidSala3(int k) {
    //      for (int cont = 0; cont < k; cont++) {
    //        pid->calculo(ref - (ult->Vdir()), 30);
    //        delay(1);
    //      }
    //    }
};
#endif
//        gir->Mgiro(135);
//        motor->Ptras();
//        delay(600);
//        motor->frear();
//        garra->abre();
//        garra->desce();
//        //anotar
//        //        pid->calculo(0, 1);
//        //        delay(7000);
//        gir->Mgiro(90);
//        pid->calculo(0, 1);
//        delay(1200);
//        motor->frear();
//        gir->Mgiro(-90);
//        motor->Ptras();
//        delay(800);
//        pid->calculo(0, 1);
//        delay(3000);
//        garra->fecha();
//        garra->sobe();
//        gir->Mgiro(180);
//        motor->Ptras();
//        delay(800);
//        pid->calculo(0, 1);
//        delay(3000);
//                gir->Mgiro(90);
//        pid->calculo(0, 1);
//        delay(1200);
//        gir->Mgiro(-45);
//        garra->abre();
//        garra->desce();
//        pid->calculo(0, 1);
//        delay(7000);
//        garra->fecha();
//        garra->sobe();
//        //
//        delay(100);
//        motor->frear();
//        gir->Mgiro(180);
//        pid->calculo(0, 1);
//        delay(7500);
//         motor->frear();
//motor->Ptras();
//        delay(800);
//        garra->abre();
//        garra->desce();
//        garra->fecha();
//        garra->sobe();
//        delay(100);
//        motor->frear();
//        gir->Mgiro(180);
//        pid->calculo(0, 1);
//        delay(3000);
//        gir->Mgiro(90);
//        pid->calculo(0, 1);
//        delay(1000);
//        gir->Mgiro(-45);
//
//      motor->Ptras();
//      delay(1800);
//      motor->frear();
//      garra->abre();
//      garra->desce();
//      pid->calculo(0, 1);
//      delay(4500);
//      garra->fecha();
//      garra->sobe();
//      motor->frear();
//      gir->Mgiro(45);
//      pid->calculo(0, 1);
//      delay(200);
//      motor->frear();
/*class Sala3 {

  public:
    Motores* motor;
    Giroscopio* gir;
    Pid* pid;
    Ultrasonicos* ult;
    Garra* garra;

    Sala3(Motores* motoress, Giroscopio* giro, Pid* pids, Garra* garras, Ultrasonicos* ults) {
      motor = motoress;
      gir = giro;
      pid = pids;
      ult = ults;
      garra = garras;
    }
    void sala() {
      pid->calculo(0, 1);
      delay(1000);
      //motor->frear();
      gir->Mgiro(90);
      motor->Ptras();
      delay(2000);
      garra->abre();
      garra->desce();
      pid->calculo(0, 1);
      delay(7900);
      garra->fecha();
      garra->sobe();
      delay(100);
      motor->frear();
      gir->Mgiro(45);
      if (ult->erroUlt() <= 5) {
        garra->descar();
        garra->fecha();
        motor->Ptras();
      delay(1000);
      gir->Mgiro(45);

      }
    }
  };*/
