// Exemplo de semáforo
// TByteCreator 2025

int Led_Vermelho = 7; //LED Vermelho conectado ao pino 7
int Led_Amarelo = 4;  //LED Amarelo conectado ao pino 4
int Led_Verde = 1;    //LED Verde conectado ao pino 1

void setup()
{
  pinMode(Led_Vermelho, OUTPUT); //Pino 7 do arduino como saída
  pinMode(Led_Amarelo, OUTPUT); //Pino 4 do arduino como saída
  pinMode(Led_Verde, OUTPUT); //Pino 1 do arduino como saída
}

void loop()
{
  digitalWrite(Led_Vermelho, HIGH); //Acende o led vermelho
  delay(4000); //permanece 4s com o led vermelho aceso
  digitalWrite(Led_Vermelho, LOW); //Apaga o led vermelho

  digitalWrite(Led_Verde, HIGH); //Acende imediatamente o led verde
  delay(4000); //permanece 4s com o led verde aceso
  digitalWrite(Led_Verde, LOW); //Apaga o led verde

  digitalWrite(Led_Amarelo, HIGH); //Acende imediatamente o led amarelo
  delay(2000); //permanece 2s com o led amarelo aceso
  digitalWrite(Led_Amarelo, LOW); //Apaga o led amarelo
}
