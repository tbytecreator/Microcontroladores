// ========================================
// tbytecreator 2025-11-24 
// Medindo Temperatura com Sensor NTC
// ========================================
int pinoNtc = 5;     //Pino analógico onde o sensor NTC está conectado
int valorSensor = 0; //Variável para armazenar o valor lido do sensor 

void setup()
{
    Serial.begin(9600); // enviar dados através da porta USB
}

void loop()
{
    valorSensor = analogRead(pinoNtc);  //Lê sinal do sensor
    Serial.print ("Valor do Sensor = ");//Escreve mensagem no monitor
    Serial.println (valorSensor);       //Escreve valor do sensor no monitor
    delay (1000);                       //Espera 1 segundo para mostrar novo valor
}