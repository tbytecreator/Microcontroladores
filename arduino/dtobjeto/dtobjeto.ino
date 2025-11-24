// ===============================================
// tbytecreator 2025-11-24
// detector de objetos
// ===============================================
int objeto = 0; // variavel para armazenar dados do sensor
int sensor = 5; // sensor conectado ao pino 5

void setup()
{
    pinMode(sensor, INPUT); //pino 5 do arduino como entrada
    Serial.begin(9600);     //enviar e receber dados pela porta USB
}

void loop()
{
    objeto = digitalRead(sensor); //Verifica sinal do sensor
    
    if (objeto == 0)
    {
        //Se o valor do sensor for 0 = Objeto detectado
        Serial.println ("Objeto presente"); 
    }
    else
    {
        //Se o valor do sensor for 1 = Objeto nenhum objeto presente
        Serial.println("Nenhum objeto presente");
    }
}