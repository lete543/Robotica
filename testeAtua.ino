#include<Cinfra.h>
#include"SensorCor.h"
#include"Motores.h"
#include"Pid.h"
#include"Giroscopio.h"
#include"Ultrasonicos.h"
#include <SensorMercurio.h>
#include"Garra.h"
#include"Sala3.h"
//antigo
//Cinfra encArray(A8, A9,  A10 , A11, A12);
Cinfra encArray(A12, A11 , A10, A9, A8);

Motores motor;

Pid pid(&motor);

//atual
SensorCor direito(A13,192.83,0.32,0.87);
SensorCor esquerdo(A14,184.24,0.31,0.85);

//antigo
//SensorCor direito(A14, 150, 139, 143);
//SensorCor esquerdo(A13, 190, 178, 178);

Giroscopio gir(&motor);

//pensar numa forma com os infra
//verifica a distância q està parando lembrando q pode estar no minimo 10 cm da curva, olhar para a reta e analisar
Ultrasonicos ult(42, 44, 4, 3, 50, 52, &motor, &gir, &pid);

Garra garra;

Sala3 sala3(&motor, &gir, &pid, &garra, &ult);

//const int buttonPin = 53;
//int buttonState = 0;

void setup() {
  //   Serial.begin(115200);
  Serial.begin(250000);
  gir.b();
  //pinMode(buttonPin, INPUT);
  garra.garraC();
}

void loop() {
  //direito.calibra();
//Serial.println(esquerdo.rangeHSV());

  //  buttonState = digitalRead(buttonPin);
  //  if (buttonState == 0) {
  //    motor.frear();
  //    delay(1000);
  //   if (buttonState == 0) {
  //    esquerdo.calibra();
  //    direito.calibra();
  //   }
  //  }
  //

  //Serial.println(ult.erroUlt());
  //  //  //  ---------------------------------------------- -curvas e encr
    ult.erroUlt();
//    if (ult.erroUlt() <= 1) {
      if (ult.erroUlt() == 0) {
        delay(100);
        if (ult.erroUlt() == 0) {
        esquerdo.ligaB();
        ult.desvio(1);
      }
    }
    //
    if (ult.eesq(15) == 1 && ult.edir(15) == 1) {
      encArray.leitura();
      pid.calculo(encArray.erro(), 1);
      delay(1000);
      if (ult.eesq(15) == 1 && ult.edir(15) == 1) {
        pid.calculo(encArray.erro(), 1);
        delay(1000);
        esquerdo.ligaB();
        while (ult.eesq(15) == 1 && ult.edir(15) == 1) {
          encArray.leitura();
          pid.calculo(encArray.erro(), 1);
        }
        motor.frear();
        sala3.sala();
      }
    }
  encArray.leitura();
  int  val = encArray.comparar();
  if (abs(val) > 2) {
    //esquerdo.ligaG();
    //    nao esta perfeito testar mais enc +
    motor.arrumarR();
    if (val == 4) {
      if (esquerdo.rangeHSV() == 1 && direito.rangeHSV() == 1) {
        gir.Mgiro(-180);
      }
      else if (direito.rangeHSV() == 1) {
        gir.Mgiro(-90);
      }
      else if (esquerdo.rangeHSV() == 1) {
        gir.Mgiro(90);
      }
      else {
        pid.calculo(0, 1);
        delay(650);
      }
    }
    else if (val > 0) {
      esquerdo.ligaR();
      if (esquerdo.rangeHSV() == 1 ) {
        gir.Mgiro(90);
      }
      else {
        pid.calculo(0, 1);
        delay(650);
      }
    }
    else if (val < 0) {
      esquerdo.ligaG();
      if (direito.rangeHSV() == 1) {
        gir.Mgiro(-90);
      }
      else {
        pid.calculo(0, 1);
        delay(650);
      }
    }
  }
//  else if (abs(val) == 2) {
//    esquerdo.ligaB();
//    motor.arrumarR();
//    if (val == 2) {
//      gir.Mgiro(90);
//    }
//    else {
//      gir.Mgiro(-90);
//    }
//  }
  else {
    esquerdo.ligaR();
    encArray.leitura();
    ult.erroUlt();
    // pid.calculo(encArray.erro(), 1);
    pid.calculo(encArray.erro(), ult.erroUlt());
  }
}
////if(gir.acel()>10){
////  motor.pare();
////  delay(300);
////  if(gir.acel()>10){
////  motor.pare();
////  delay(2000);
////  }
//se aumentar o rangedos internos-usar condição curva
