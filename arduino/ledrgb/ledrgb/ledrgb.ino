// ==========================================================================
// LED RGB 
// tbytecreator@gmail.com
// 2025-05-14 
// ==========================================================================
int Vermelho = 9;   //Pino Vermelho conectado ao pino 11 do Arduino
int Verde = 10;     //Pino Azul conectado ao pino 10 do Arduino
int Azul = 11;      //Pino Verde conectado ao pino 9 do Arduino
int tempo = 5;

void setup()
{
  pinMode(Vermelho, OUTPUT); //Pino 11 do arduino como saída
  pinMode(Azul, OUTPUT); //Pino 10 do arduino como saída
  pinMode(Verde, OUTPUT); //Pino 9 do arduino como saída
}
void loop()
{
  analogWrite(Vermelho, 255); //Apaga o led vermelho
  analogWrite(Azul, 255); //Apaga o led azul
  analogWrite(Verde, 255); //Apaga o led verde

  for(int i=0; i<255; i++)
  {
    analogWrite(Vermelho, i); //Acende os três LEDS e apaga o vermelho
    analogWrite(Azul, 0);     //lentamente mostrando a mistura do Azul
    analogWrite(Verde, 0);    //com o verde.
    delay(tempo);
  }

  for(int i=0; i<255; i++)
  {
    analogWrite(Vermelho, 255); //Agora com o vermelho apagado, apaga o azul
    analogWrite(Azul, i);       //lentamente mostrando apenas o verde
    analogWrite(Verde, 0);      //aceso.
    delay(tempo);
  }

  for(int i=255; i>0; i--)
  {
    analogWrite(Vermelho, i); //Com apenas o verde aceso, o vermelho começa a
    analogWrite(Azul, 255);   //acender lentamente ficando o verde e o
    analogWrite(Verde, 0);  //vermelho acesos
    delay(tempo);
  }

  for(int i=0; i<255; i++)
  {
    analogWrite(Vermelho, 0); //Com o verde e o vermelho acesos, o verde
    analogWrite(Azul, 255); //começa a se apagar lentamente ficando então
    analogWrite(Verde, i); //apenas o vermelho aceso
    delay(tempo);
  }

  for(int i=255; i>0; i--)
  {
    analogWrite(Vermelho, 0); //Com apenas o vermelho aceso, agora o azul
    analogWrite(Azul, i); //começa a se acender lentamente, ficando
    analogWrite(Verde, 255); //o azul e o vermelho acesos
    delay(tempo);
  }
 
  for(int i=255; i>0; i--) 
  {
    analogWrite(Vermelho, i); //Neste ponto com azul e vermelho acesos, o
    analogWrite(Azul, 0);     //vermelho se apaga lentamente e fica apenas
    analogWrite(Verde, 255);  //o azul aceso
    delay(tempo);
  }
 
  for(int i=255; i>0; i--)
  {
    analogWrite(Vermelho, 255); //Agora com apenas o azul aceso, o verde se
    analogWrite(Azul, 0); //acende lentamente ficando novamente o verde
    analogWrite(Verde, i); //e o azul acesos
    delay(tempo);
  }

  for(int i=255; i>0; i--)
  {
    analogWrite(Vermelho, i); //E por fim o vermelho se acende lentamente
    analogWrite(Azul, 0); //juntamente com o azul e o verde voltando
    analogWrite(Verde, 0); //acender branco novamente iniciando novamente
    delay(tempo); //o ciclo
  }
}
