class SensorMercurio{
  private:
  int portasi;
  int ler;

  public:
  SensorMercurio(int p){
    portasi = p;
    pinMode(portasi,INPUT);
  }
  
  int leitura(){
    ler=digitalRead(portasi);
    return  ler;
  }
  
  void imprimir(){
    Serial.println(ler);
  }
  
};
