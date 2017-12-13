
#include <Adafruit_NeoPixel.h>
#include "WS2812_Definitions.h"

#define PIN 4// Pino de controle
#define LED_COUNT 60// Quantidade de LED's
unsigned long fita=0x000000;// recebe valores em hexa referente as cores
unsigned long pri=0x000033;
unsigned long seg=0x003201;
unsigned long ter=0x320001;
//Cria uma instância da Classe Adafruit NeoPixel chamado "leds"
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  leds.begin(); // Inicia a fita de LED
  clearLEDs();   // Apaga todos os LEDs
  leds.show(); // Atualiza o estados dos LEDs
}


void loop()
{
  int l=0;//conta a posição dos LEDs
  int DD=50;//Variavel de envio do valor do delay

  for(int k=0; k<6;k++)//1º laço
  {
    for(int j=0;j<6;j++)//2º laço
    {
      for(int i=0;i<5;i++)//3º laço
      {
        if( l>= LED_COUNT) l=0;//Verifica se ultrapassou o limite da fita
        fita=fita+pri;//Coforme a tabela inseri o valor na constante e incrementa
        ligaLED(l,DD);//Envia a posição na fita e envia o tempo ligado
        //apagaLED(l,DD);//Envia a posição na fita e envia o tempo desligad//// Tirar comentario caso queira utilizar um unico LED
         l++;//Incrementa posição na fita
      }
       if(j<5)//Compara se não ultrapassou o limite pois foram feitas duas somas seguidas e uma tera que ser ignorada
         {
          if(l>= LED_COUNT)l=0;
           fita=fita+seg;
           ligaLED(l,DD);
          // apagaLED(l,DD);// Tirar comentario caso queira utilizar um unico LED
           l++;//Incrementa posição na fita
           }

      }
       if(k<5)//Compara se não ultrapassou o limite pois foram feitas duas somas seguidas e uma tera que ser ignorada
         {
          if(l>= LED_COUNT)l=0;
             fita=fita+ter;
             ligaLED(l,DD);
             //apagaLED(l,DD);// Tirar comentario caso queira utilizar um unico LED
             l++;//Incrementa posição na fita
          }
     }  
}


//Função liga led individual
void ligaLED(int g, int d)//Recebe a posição e tempo de Delay
{
delay(d); //Seta o tempo

leds.setPixelColor(g, fita);//Aciona o LED requerido
 leds.show();//Atualiza o LED
}



//Função apaga LED individual
void apagaLED(int g, int d)//Recebe a posição e tempo de Delay
{
delay(d); //Seta o tempo
leds.setPixelColor(g, 0);//Desaciona o LED requerido
 leds.show();//Atualiza o LED
}

//Função apaga LEDs geral
void clearLEDs()
{
  for (int p=0; p<LED_COUNT; p++)
  {
    leds.setPixelColor(p, 0);
    leds.show();
  }
}
