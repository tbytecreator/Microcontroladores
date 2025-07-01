//========================================================================== 
// TByteCreator Detector de objetos
// 2025-06-29
//========================================================================== 
int Objeto = 0; // flag que determina se temos objeto proximo
int Sensor = 5; // pino do sensor de proximidade TCRT5000

void setup() 
{
  pinMode(Sensor, INPUT); // preparamos o pino do sensor para input  
  Serial.begin(9600);     // inicializamos a porta serial com 9600b
}

void loop() 
{
  Objeto = digitalRead(Sensor); // lemos o sensor
  if (Objeto == 1)
  { 
    // este fabricante usa 1 como nenhum objeto presente
    Serial.println ("Nenhum objeto presente"); 
  }
  else 
  {
    // temos um objeto proximo do sensor
    Serial.println ("Objeto detectado");
  } 
}
