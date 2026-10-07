#ifndef Motores_h
#define Motores_h

#define me1 6
#define me2 5
#define md1 7
#define md2 8

class Motores {
  public:
    int Vd1 = 0;
    int Vd2 = 0;
    int Ve1 = 0;
    int Ve2 = 0;

    Motores() {
      pinMode(md1, OUTPUT);
      pinMode(md2, OUTPUT);
      pinMode(me1, OUTPUT);
      pinMode(me2, OUTPUT);
      
      analogWrite(md1,  0);
      analogWrite(md2, 0);
      analogWrite(me1,  0);
      analogWrite(me2,  0);
    }

    void mover(int e1, int d1) {
      int d2 = 0, e2 = 0;
      if (d1 > 0) {
        d2 = 0;
      }
      else {
        d2 = abs(d1);
        d1 = 0;
      }
      if (e1 > 0) {
        e2 = 0;
      }
      else {
        e2 = abs(e1);
        e1 = 0;
      }
      Vd1 = d1;
      Vd2 = d2;
      Ve1 = e1;
      Ve2 = e2;
      analogWrite(md1,  Vd1);
      analogWrite(md2, Vd2);
      analogWrite(me1,  Ve1);
      analogWrite(me2,  Ve2);
    }
    void frear() {
      analogWrite(md1,  Vd2);
      analogWrite(md2, Vd1);
      analogWrite(me1,  Ve2);
      analogWrite(me2,  Ve1);
      delay(35);
      mover(0, 0);
      //
      delay(50);
    }
    void motPid(float M, float V, float u) {

      if (V != 0) {
        M = (250.0 / V) * M;
      }
      else {
        M = 0;
      }
      //Serial.println(M);
      if (M > 500) {
        M = 500;
      }
      else if (M < -500) {
        M = -500;
      }

      
      float N = (V * u) / 10;
      float andar1 = ((V - M) * u);
      float andar2 = ((V + M) * u);
      float andar3 = ( V * u );
      
      if (andar1 > 250) {
        andar1 = 250;
      }
      
      if (andar2 > 250) {
        andar2 = 250;
      }

      if (andar3 > 250) {
        andar3 = 250;
      }
      
      if (M > 0) {
        andar(andar1, andar3);
      }
      else {
        andar(andar3, andar2);
      }
      //      ver valores por serem dobro
    }
    void andar(int esq, int dir) {
      //Motor da esquerda
      //analogWrite(me1,-esq*(esq<0))
      //analogWrite(me2,esq*(esq>0));
      //Se erro for menor que 0, virar para esquerda
      if (esq <0) {
        digitalWrite(me1, 0);
        analogWrite(me2, -esq);
        //        analogWrite(me2, -esq);
      }
      else {
        analogWrite(me1, esq);
        digitalWrite(me2, 0);
      }

      //Motor direita
      //Se erro for menor que 0, virar para esquerda
      if (dir < 0) {
        digitalWrite(md1, 0);
        analogWrite(md2, -dir);
      }
      //Se erro for maior que 0, virar para esquerda
      else {
        analogWrite(md1, dir);
        digitalWrite(md2, 0);
      }
      //      Serial.print(esq);
      //      Serial.print(" ");
      //      Serial.println(dir);
    }

    void pare() {
      mover(0, 0);
    }

    void Ptras() {
      mover(-250, -215);
    }

    void Pesq() {
      mover(-250, 215);
    }
    void Pdir() {
      mover(250, -215);
    }
    void Pfrente() {
      mover(255, 215);
    }

    void encMot() {
      Ptras();
      delay(100);
    }


    void arrumarR() {
      encMot();
      frear();
    }
};
#endif
