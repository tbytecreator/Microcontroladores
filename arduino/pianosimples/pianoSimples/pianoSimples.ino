
int Led_Vermelho = 11;
int Led_Amarelo = 10; 
int Led_Verde = 9; 
int Led_Azul = 8; 
int Botao_1 = 7; 
int Botao_2 = 6; 
int Botao_3 = 5; 
int Botao_4 = 4;
int Nota = 0; 
int Buzzer = 12;
int Estado_Botao_1 = 0; 
int Estado_Botao_2 = 0; 
int Estado_Botao_3 = 0; 
int Estado_Botao_4 = 0;


void setup() 
{
  pinMode(Led_Vermelho, OUTPUT); 
  pinMode(Led_Amarelo, OUTPUT); 
  pinMode(Led_Verde, OUTPUT);
  pinMode(Led_Azul, OUTPUT); 
  pinMode(Botao_1, INPUT); 
  pinMode(Botao_2, INPUT); 
  pinMode(Botao_3, INPUT); 
  pinMode(Botao_4, INPUT); 
  pinMode(Buzzer, OUTPUT);
}

void loop() 
{
 
  Estado_Botao_1 = digitalRead(Botao_1); 
  Estado_Botao_2 = digitalRead(Botao_2); 
  Estado_Botao_3 = digitalRead(Botao_3); 
  Estado_Botao_4 = digitalRead(Botao_4); 

  if(Estado_Botao_1 && !Estado_Botao_2 && !Estado_Botao_3 && !Estado_Botao_4) 
  { 
    Nota = 80; 
    digitalWrite(Led_Vermelho, HIGH); 
  } 

  if(!Estado_Botao_1 && Estado_Botao_2 && !Estado_Botao_3 && !Estado_Botao_4) 
  { 
    Nota = 160; 
    digitalWrite(Led_Amarelo, HIGH); 
  } 

  if(!Estado_Botao_1 && !Estado_Botao_2 && Estado_Botao_3 && !Estado_Botao_4) 
  { 
    Nota = 240; 
    digitalWrite(Led_Verde, HIGH); 
  } 
  
  if(!Estado_Botao_1 && !Estado_Botao_2 && !Estado_Botao_3 && Estado_Botao_4) 
  { 
    Nota = 320; 
    digitalWrite(Led_Azul, HIGH); 
  } 

  if (Nota > 0)
  { 
    digitalWrite(Buzzer, HIGH); 
    delayMicroseconds(Nota); 
    digitalWrite(Buzzer, LOW); 
    delayMicroseconds(Nota); 
    Nota = 0; 
    digitalWrite(Led_Vermelho, LOW); 
    digitalWrite(Led_Amarelo, LOW); 
    digitalWrite(Led_Verde, LOW); 
    digitalWrite(Led_Azul, LOW);
  } 
}