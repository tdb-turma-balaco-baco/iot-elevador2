#include <Arduino.h>
#include <Stepper.h>
#include <LiquidCrystal.h>
 
#define LED_01 12
#define LED_02 13

const int stepsPerRevolution = 70; 
int andarAtual = 1;
Stepper myStepper(stepsPerRevolution, 22,23,24,25);

void movimentarMotor(int passos, int voltas){
   for(int i = 0; i < voltas; i++){ 
      myStepper.step(passos);
   }
}

void iniciarLeds(){
   pinMode(LED_01, OUTPUT);
   pinMode(LED_02, OUTPUT);
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
   movimentarMotor(-stepsPerRevolution, 60);
   andarAtual = 1;
   Serial.println("Voce chegou no PRIMEIRO ANDAR");
   ledPrimeiroAndar();
}

void subirElevador(){
   movimentarMotor(+stepsPerRevolution, 50);
   andarAtual = 2;
   Serial.println("Voce chegou no SEGUNDO ANDAR");
   ledSegundoAndar();
}

 
void setup(){
  Serial.begin(9600);
  iniciarLeds();
  ledPrimeiroAndar();
  myStepper.setSpeed(300);
}
void loop(){
   while (Serial.available() > 0)
   {
    Serial.println("Qual andar deseja ir?");

    int andarEscolhido = Serial.parseInt();

    if (andarAtual == 2 && andarEscolhido == 1)
    {
        descerEvelador();
    }   

    else if (andarAtual == 1 && andarEscolhido == 2)
    {
        subirElevador();
    }   
    else {
      Serial.println("Voce ja esta no " + andarEscolhido);
    }
  }
}
