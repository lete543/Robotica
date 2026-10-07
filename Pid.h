#ifndef Pid_h
#define Pid_h
//muda o u
// e o ja inicializacom um valor
class Pid {
    //  calibrar valores
  private:
    int ea = 0;
    //    atual
    float Kp = 2.0;
    float Kd = 2.0;
    //        float Kd = 0.5;
    //    1.4´´0.02--1.30.kp
       float Ki = 0.001;
    //        float Kd = 0;

    Motores* motores;
  public:
    //float Ki = 0.001;
    Pid(Motores *mot) {
      motores = mot;
    }



    int calculo(int e, float u) {
      // Serial.println(u);
      static float V = 250;
      //static float I = 48276;
//      static float I = 61521.00;
 static float I = 0.00;

      //      Serial.println(e);
      if (abs(e) > 200) {
        I = I;
        //V = 150;
      }
      else {
        //V = min(250 , V + 5);
        I += e;
      }

      if (e == 0) {
        ea = e;
      }
      float D = (e - ea);
      float M = (e * Kp) + (I * Ki) + (D * Kd);

      ea = e;

      
      
      motores->motPid(M, V, u);


      // Serial.print("V ");
       //Serial.println(M);
      //V = V*u/30;
      // Serial.print("V ");
      // Serial.print(V);
      //Serial.print(" u ");
      //Serial.println(u);
      //
      //            Serial.print((V*u)/30);
      //            Serial.print(" ");
      //            Serial.println(V);





      //motores->motPid(M, V);
      //  Serial.println(I);
    }
};
#endif
