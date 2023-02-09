#include <Arduino.h>
#include <Stepper.h>

#define LED_01 3
#define LED_02 4

#define BUTTON_1 5
#define BUTTON_2 6

const int stepsPerRevolution = 65; 
int andarAtual = 1;
Stepper myStepper(stepsPerRevolution, 8,10,9,11);
 
void setup(){
  myStepper.setSpeed(300); //VELOCIDADE DO MOTOR

  //iniciarLeds();
  //iniciarBotoes();

}
void loop(){
   if (acionadoBotaoPrimeiroAndar && andarAtual == 2)
   {
      descerEvelador();
   }   

   if (acionadoBotaoSegundoAndar && andarAtual == 1)
   {
      subirElevador();
   }   
}

void subirElevador(){
   movimentarMotor(stepsPerRevolution);
   andarAtual = 2;
   ledSegundoAndar();
}

void descerEvelador(){
   movimentarMotor(-stepsPerRevolution);
   andarAtual = 1;
   ledPrimeiroAndar();
}

void movimentarMotor(int passos){
   for(int i = 0; i < 50; i++){ 
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