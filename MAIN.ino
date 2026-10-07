// Inclusão das bibliotecas do sistema para controle de sensores, atuadores e algoritmos
#include<Cinfra.h>
#include"SensorCor.h"
#include"Motores.h"
#include"Pid.h"
#include"Giroscopio.h"
#include"Ultrasonicos.h"
#include <SensorMercurio.h>
#include"Garra.h"
#include"Sala3.h"

// Antigo mapeamento dos sensores infravermelhos seguidores de linha
//Cinfra encArray(A8, A9,  A10 , A11, A12);

// Instanciação do array de sensores infravermelhos indicando os pinos analógicos
Cinfra encArray(A12, A11 , A10, A9, A8);

// Instanciação do objeto responsável pelo controle dos motores
Motores motor;

// Instanciação do controlador PID associado aos motores
Pid pid(&motor);

// Instanciação e calibração dos sensores de cor direito e esquerdo (Pino, Parâmetros de calibração)
SensorCor direito(A13,192.83,0.32,0.87);
SensorCor esquerdo(A14,184.24,0.31,0.85);

// Parâmetros antigos de calibração dos sensores de cor (referência)
//SensorCor direito(A14, 150, 139, 143);
//SensorCor esquerdo(A13, 190, 178, 178);

// Instanciação do giroscópio associado ao controle de motores
Giroscopio gir(&motor);

// Instanciação do conjunto de sensores ultrassônicos passando pinos e referências dos módulos de motor, giroscópio e PID
Ultrasonicos ult(42, 44, 4, 3, 50, 52, &motor, &gir, &pid);

// Instanciação do atuador da garra mecânica
Garra garra;

// Instanciação do módulo da Sala 3 passando os controladores necessários
Sala3 sala3(&motor, &gir, &pid, &garra, &ult);

// Declaração de pino e variável para leitura de botão (desativados)
//const int buttonPin = 53;
//int buttonState = 0;

void setup() {
  // Inicialização da comunicação serial a 250000 bps
  // Serial.begin(115200);
  Serial.begin(250000);
  
  // Inicializa a calibração/configuração base do giroscópio
  gir.b();
  
  // Configuração do pino do botão como entrada (desativado)
  //pinMode(buttonPin, INPUT);
  
  // Posição inicial ou calibração da garra mecânica
  garra.garraC();
}

void loop() {
  // Rotinas de calibração ou testes de leitura do sensor de cor (desativadas)
  //direito.calibra();
  //Serial.println(esquerdo.rangeHSV());

  // Leitura do estado do botão para calibração manual (desativado)
  // buttonState = digitalRead(buttonPin);
  // if (buttonState == 0) {
  //   motor.frear();
  //   delay(1000);
  //  if (buttonState == 0) {
  //   esquerdo.calibra();
  //   direito.calibra();
  //  }
  // }

  // Exibição do erro ultrassônico no monitor serial (desativado)
  //Serial.println(ult.erroUlt());
  // ---------------------------------------------- -curvas e encr
  
  // Realiza a leitura e verifica a presença de obstáculos com o sensor ultrassônico
  ult.erroUlt();
  // if (ult.erroUlt() <= 1) {
  
  // Se for detectado um obstáculo (erro igual a 0)
  if (ult.erroUlt() == 0) {
    delay(100); // Aguarda para confirmar a leitura do obstáculo
    
    // Confirmação de obstáculo à frente
    if (ult.erroUlt() == 0) {
      esquerdo.ligaB(); // Aciona o LED/indicador azul
      ult.desvio(1);    // Executa a rotina de desvio de obstáculo
    }
  }

  // Verifica se há paredes ou espaço suficiente em ambos os lados (distância de 15 cm)
  if (ult.eesq(15) == 1 && ult.edir(15) == 1) {
    encArray.leitura(); // Lê os sensores infravermelhos
    pid.calculo(encArray.erro(), 1); // Atualiza a trajetória via PID
    delay(1000);
    
    // Confirmação após 1 segundo para verificar entrada na área da Sala 3
    if (ult.eesq(15) == 1 && ult.edir(15) == 1) {
      pid.calculo(encArray.erro(), 1);
      delay(1000);
      esquerdo.ligaB(); // Aciona o indicador azul
      
      // Mantém o alinhamento via PID enquanto estiver na transição da sala
      while (ult.eesq(15) == 1 && ult.edir(15) == 1) {
        encArray.leitura();
        pid.calculo(encArray.erro(), 1);
      }
      
      // Freia o robô ao chegar ao destino e inicia o algoritmo da Sala 3
      motor.frear();
      sala3.sala();
    }
  }

  // Leitura padrão do array de sensores infravermelhos para detecção de curvas e cruzamentos
  encArray.leitura();
  int val = encArray.comparar(); // Compara a leitura dos sensores para identificar o tipo de cruzamento/curva

  // Se for detectada uma curva acentuada ou cruzamento (valor absoluto de val > 2)
  if (abs(val) > 2) {
    //esquerdo.ligaG();
    // nao esta perfeito testar mais enc +
    
    motor.arrumarR(); // Ajusta a velocidade ou alinhamento para manobra
    
    // Cruzamento em T ou retorno (val == 4)
    if (val == 4) {
      // Se ambos os sensores de cor detectarem marcação verde, faz curva de 180 graus (retorno)
      if (esquerdo.rangeHSV() == 1 && direito.rangeHSV() == 1) {
        gir.Mgiro(-180);
      }
      // Se apenas o sensor direito detectar marcação verde, gira 90 graus para a direita
      else if (direito.rangeHSV() == 1) {
        gir.Mgiro(-90);
      }
      // Se apenas o sensor esquerdo detectar marcação verde, gira 90 graus para a esquerda
      else if (esquerdo.rangeHSV() == 1) {
        gir.Mgiro(90);
      }
      // Se não houver marcação verde, segue em frente por um curto período
      else {
        pid.calculo(0, 1);
        delay(650);
      }
    }
    // Curva ou cruzamento para a esquerda (val > 0)
    else if (val > 0) {
      esquerdo.ligaR(); // Aciona indicador vermelho
      
      // Se o sensor esquerdo confirmar marcação verde, realiza o giro de 90 graus para a esquerda
      if (esquerdo.rangeHSV() == 1 ) {
        gir.Mgiro(90);
      }
      // Caso contrário, continua em frente
      else {
        pid.calculo(0, 1);
        delay(650);
      }
    }
    // Curva ou cruzamento para a direita (val < 0)
    else if (val < 0) {
      esquerdo.ligaG(); // Aciona indicador verde
      
      // Se o sensor direito confirmar marcação verde, realiza o giro de 90 graus para a direita
      if (direito.rangeHSV() == 1) {
        gir.Mgiro(-90);
      }
      // Caso contrário, continua em frente
      else {
        pid.calculo(0, 1);
        delay(650);
      }
    }
  }
  // Condição alternativa para curvas de valor 2 (desativada)
  // else if (abs(val) == 2) {
  //   esquerdo.ligaB();
  //   motor.arrumarR();
  //   if (val == 2) {
  //     gir.Mgiro(90);
  //   }
  //   else {
  //     gir.Mgiro(-90);
  //   }
  // }
  
  // Caminho normal de linha reta / curva suave
  else {
    esquerdo.ligaR(); // Aciona indicador vermelho
    encArray.leitura(); // Atualiza leitura dos infravermelhos
    ult.erroUlt();     // Atualiza distância dos ultrassônicos
    
    // Executa o cálculo PID ajustando a velocidade dos motores de acordo com o erro da linha e do ultrassom
    // pid.calculo(encArray.erro(), 1);
    pid.calculo(encArray.erro(), ult.erroUlt());
  }
}

// Verificação de rampa ou aceleração brusca via giroscópio (desativado)
////if(gir.acel()>10){
////  motor.pare();
////  delay(300);
////  if(gir.acel()>10){
////  motor.pare();
////  delay(2000);
////  }
//se aumentar o rangedos internos-usar condição curva
