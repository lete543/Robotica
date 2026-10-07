#ifndef SensorCor_h
#define SensorCor_h

#define RED 40
#define GREEN 38
#define BLUE 36

//tentar fazer com todas cores

//ANT
//#define   BLUE 37
//#define GREEN 35
//#define RED 39


#define fatH 15
#define fatS 5
#define fatV 10

#define num 8


class SensorCor {
  private:

    //  pq não pode passar um valor para variaveis aqui

    int porta;

    float Vh;
    float Vs;
    float Vv;

    float h = 0;
    float s = 0;
    float v = 0;


    float corRed;
    float corGreen;
    float corBlue;

    void ModoLeds() {
      //Led
      pinMode(RED, OUTPUT);
      pinMode(GREEN, OUTPUT);
      pinMode(BLUE, OUTPUT);
    }
    void desligandoLeds() {
      //Desligando os leds
      digitalWrite(RED, 1);
      digitalWrite(GREEN, 1);
      digitalWrite(BLUE, 1);
    }




  public:
    SensorCor(int pin, float vh, float vs, float vv) {

      Vh = vh;
      Vs = vs;
      Vv = vv;

      porta = pin;
      pinMode(porta, INPUT);

      ModoLeds();
      desligandoLeds();

    }
    void ligaR() {
      //Desligando os leds
      digitalWrite(RED, 0);
      digitalWrite(GREEN, 1);
      digitalWrite(BLUE, 1);
    }
    void ligaG() {
      //Desligando os leds
      digitalWrite(RED, 1);
      digitalWrite(GREEN, 0);
      digitalWrite(BLUE, 1);
    }
    void ligaB() {
      //Desligando os leds
      digitalWrite(RED, 1);
      digitalWrite(GREEN, 1);
      digitalWrite(BLUE, 0);
    }

    float ler() {
      corRed = 0, corGreen = 0, corBlue = 0;
      for (int i = 0; i < num; i++) {
        digitalWrite(RED, 0);
        delay(10);
        corRed += map(analogRead(porta), 0, 1023, 0, 200);
        corRed = analogRead(porta);
        digitalWrite(RED, 1);

        digitalWrite(GREEN, 0);
       delay(10);
       corGreen += map(analogRead(porta), 0, 1023, 0, 200);
       digitalWrite(GREEN, 1);

        digitalWrite(BLUE, 0);
        delay(10);
        corBlue += map(analogRead(porta), 0, 1023, 0, 200);
        digitalWrite(BLUE, 1);
      }
      corRed /= num;
      corGreen /= num;
      corBlue /= num;


    }


    int rangeHSV() {
      hsv();
      //          h         s        v

      //  1   v  -27.86   0.14     0.93
      //      v  10
      //  2   c  52.80    0.19     0.67
      //  3   b  44.35    0.30     0.38
      //  4   p  42.00    0.05     0.95


      float HMin = abs(Vh) - fatH;
      float HMax = abs(Vh) + fatH;

      float SMin = abs(Vs) - fatS;
      float SMax = abs(Vs) + fatS;

      float VMin = abs(Vv) - fatV;
      float VMax = abs(Vv) + fatV;


      if ( abs(h) >= HMin && abs(h) <= HMax && abs(s) >= SMin && abs(s) <= SMax && abs(v) >= VMin && abs(v) <= VMax ) {
        return 1;
      }

      //      //azul no verde e preto valores proximos

      else {
        return 0;
      }

    }

    float hsv() {
      ler();
      float Red = (float)corRed / 200;
      float Green = (float)corGreen / 200;
      float Blue = (float)corBlue / 200;


      float ma = max(max(Red, Green), Blue);
      float mi = min(min(Red, Green), Blue);

      s = (ma - mi) / ma;


      v = ma;

      if ( ma == Red && Green >= Blue) {
        h = 60 * ((Green - Blue) / (ma - mi));
      }
      else if ( ma == Red  &&  Green < corBlue) {
        h = 60 * ((Green - Blue) / (ma - mi));
      }
      else if ( ma == Green ) {
        h = 60 * ((Blue - Red) / (ma - mi)) + 120;
      }
      else if ( ma == Blue ) {
        h = 60 * ((Red - Green) / (ma - mi)) + 240;
      }
      else {
        h = h;
      }


      //   s   invertido pela cor


    }
    void calibra() {
      hsv();
      Serial.print(h);
      Serial.print(",");
      Serial.print(s);
      Serial.print(",");
      Serial.println(v);
    }

};
#endif

/*#ifndef SensorCor_h
  #define SensorCor_h

  #define REDL 40
  #define GREENL 38
  #define BLUEL 36

  //tentar fazer com todas cores

  //ANT
  //#define   BLUE 37
  //#define GREEN 35
  //#define RED 39


  #define fatR 20
  #define fatG 20
  #define fatB 20

  #define num 10


  class SensorCor {
  private:

    int porta;

    void ModoLeds() {
      //Led
      pinMode(REDL, OUTPUT);
      pinMode(GREENL, OUTPUT);
      pinMode(BLUEL, OUTPUT);
    }
    void desligandoLeds() {
      //Desligando os leds
      digitalWrite(REDL, 1);
      digitalWrite(GREENL, 1);
      digitalWrite(BLUEL, 1);
    }




  public:
    SensorCor(int pin, float r, float g, float b) {

      R = r;
      G = g;
      B = b;

      porta = pin;
      pinMode(porta, INPUT);

      ModoLeds();
      desligandoLeds();

    }
    float R=0;
    float G=0;
    float B=0;


    float corRed;
    float corGreen;
    float corBlue;

    void ligaR() {
      //Desligando os leds
      digitalWrite(REDL, 0);
      digitalWrite(GREENL, 1);
      digitalWrite(BLUEL, 1);
    }
    void ligaG() {
      //Desligando os leds
      digitalWrite(REDL, 1);
      digitalWrite(GREENL, 0);
      digitalWrite(BLUEL, 1);
    }
    void ligaB() {
      //Desligando os leds
      digitalWrite(REDL, 1);
      digitalWrite(GREENL, 1);
      digitalWrite(BLUEL, 0);
    }

    float ler() {
      corRed = 0, corGreen = 0, corBlue = 0;
      for (int i = 0; i < num; i++) {
        digitalWrite(REDL, 0);
        delay(10);
        corRed += map(analogRead(porta), 0, 1023, 0, 200);
        corRed = analogRead(porta);
        digitalWrite(REDL, 1);

        digitalWrite(GREENL, 0);
        delay(10);
        corGreen += map(analogRead(porta), 0, 1023, 0, 200);
        digitalWrite(GREENL, 1);

        digitalWrite(BLUEL, 0);
        delay(10);
        corBlue += map(analogRead(porta), 0, 1023, 0, 200);
        digitalWrite(BLUEL, 1);
      }
      corRed /= num;
      corGreen /= num;
      corBlue /= num;


    }


    int rangeRGB() {
       //Serial.println(h);
      ler();
      //          h         s        v

      //  1   v  -27.86   0.14     0.93
      //      v  10
      //  2   c  52.80    0.19     0.67
      //  3   b  44.35    0.30     0.38
      //  4   p  42.00    0.05     0.95

      float RMin = R - fatR;
      float RMax = R + fatR;

      float GMin = G - fatG;
      float GMax = G + fatG;

      float BMin = B - fatB;
      float BMax = B + fatB;

  //       Serial.print("(");
  //       Serial.print(corRed);
  //       Serial.print(",");
  //       Serial.print(corGreen);
  //       Serial.print(",");
  //       Serial.print(corBlue);
  //       Serial.println(")");


      if ( corRed >= RMin && corRed <= RMax &&  corGreen >= GMin && corGreen <= GMax && corBlue >= BMin && corBlue <= BMax ) {
        return 1;
      }

      //      //azul no verde e preto valores proximos

      else {
        return 0;
      }

    }

    void calibra() {
      ler();
  //      Vh = h;
  //      G = s;
  //      Vv = v;
       Serial.print("(");
       Serial.print(corRed);
       Serial.print(",");
       Serial.print(corGreen);
       Serial.print(",");
       Serial.print(corBlue);
       Serial.println(")");
    }

  };
  #endif*/
