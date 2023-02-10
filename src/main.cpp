#include <Arduino.h>
#include <Stepper.h>

#define LED_01 12
#define LED_02 13

#define BUTTON_1 7
#define BUTTON_2 6

const int stepsPerRevolution = 65; 
int andarAtual = 1;
Stepper myStepper(stepsPerRevolution, 8,10,9,11);


void movimentarMotor(int passos){
   for(int i = 0; i < 150; i++){ 
      myStepper.step(passos);
   }
}

bool acionadoBotaoPrimeiroAndar(){
   return digitalRead(BUTTON_1) == LOW;
}

bool acionadoBotaoSegundoAndar(){
   return digitalRead(BUTTON_2) == LOW;
}

void iniciarLeds(){
   pinMode(LED_01, OUTPUT);
   pinMode(LED_02, OUTPUT);
}

void iniciarBotoes(){
     pinMode(BUTTON_1, INPUT_PULLUP);
     pinMode(BUTTON_2, INPUT_PULLUP);
}

void ledSegundoAndar(){
   digitalWrite(LED_02, HIGH);
   digitalWrite(LED_01, LOW);
}

void ledPrimeiroAndar(){
   digitalWrite(LED_01, HIGH);
   digitalWrite(LED_02, LOW);
}

void descerEvelador(){
   movimentarMotor(stepsPerRevolution);
   andarAtual = 1;
   ledPrimeiroAndar();
}

void subirElevador(){
   movimentarMotor(-stepsPerRevolution);
   andarAtual = 2;
   ledSegundoAndar();
}

 
void setup(){
  myStepper.setSpeed(300); //VELOCIDADE DO MOTOR
  iniciarLeds();
  iniciarBotoes();
  andarAtual = 1;
  ledPrimeiroAndar();

}
void loop(){
   if (acionadoBotaoPrimeiroAndar() && andarAtual == 2)
   {
      descerEvelador();
   }   

   if (acionadoBotaoSegundoAndar() && andarAtual == 1)
   {
      subirElevador();
   }   
}
