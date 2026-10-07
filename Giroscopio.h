#ifndef Giroscopio_h
#define Giroscopio_h

#include <Wire.h>

class Giroscopio {
  public:

    const int MPU = 0x68;
    int GyZ = 0;

    Motores* motor;
    Giroscopio(Motores *m) {
      motor = m;
    }


    void b() {
      Wire.begin();
      Wire.beginTransmission(MPU);
      Wire.write(0x6B);
      //Inicializa o MPU-6050
      Wire.write(0);
      Wire.endTransmission(true);
    }


    void Mgiro(int graus) {
      float yaw = 0;
      int consta;
      motor->Pfrente();
      delay(600);
      motor->frear();
      if (graus < 0) {
        motor->Pdir();

      }
      else {
        motor->Pesq();
      }
      giro(abs(graus));
      motor->frear();

    }


    bool giro(unsigned int val) {
      unsigned long resultado = 0;
      unsigned long ref = map(val, 0, 360, 0, 2050000);

      while (true) {
        Wire.beginTransmission(MPU);
        Wire.write(0x47); // starting with register 0x3B (ACCEL_XOUT_H)
        Wire.endTransmission(false);
        Wire.requestFrom(MPU, 14, true);
        GyZ = Wire.read() << 8 | Wire.read(); //0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
        if (GyZ < 0) {
          GyZ *= (-1);
        }
        if (GyZ > 250) {
          resultado += (GyZ);
        }
        //Serial.println(resultado);
        if (resultado >= ref) {
          return true;
        }
        delay(20);
      }

    }
};
#endif
