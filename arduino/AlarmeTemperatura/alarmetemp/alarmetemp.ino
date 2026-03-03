/*========================================================================== 
tbytecreator 2026 
Alarme de Temperatura simples
==========================================================================*/ 
int Pino_NTC = 5;   //Sensor NTC conectado ao Pino 5 
int Buzzer = 10;    //Buzzer no pino 10
int Valor_Sensor = 0;

void setup() 
{
    Serial.begin(9600);
    pinMode(Buzzer, OUTPUT); 
}

void loop() 
{
    Valor_Sensor = analogRead(Pino_NTC); //Lê sinal do sensor 
    Serial.println(Valor_Sensor);

    //Verifica se a temperatura ultrapassou o limite 
    if (Valor_Sensor > 900)
    { 
        digitalWrite(Buzzer, HIGH); // Se sim, toca alarme 
    }
    else 
    {
        digitalWrite(Buzzer, LOW); // Caso contrário desliga o alarme 
    } 
}