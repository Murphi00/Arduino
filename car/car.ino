#include <SoftwareSerial.h>
SoftwareSerial bluetooth (8, 9);

int esquerdaFrente = 6;
int esquerdaRe = 7;
int direitaFrente = 4;
int direitaRe = 5;

char c;

void andarFrente();
void re();
void direita();
void esquerda();
void parar();

void setup() {
  pinMode(esquerdaFrente, OUTPUT);
  pinMode(esquerdaRe, OUTPUT);
  pinMode(direitaRe, OUTPUT);
  pinMode(direitaFrente, OUTPUT);

  bluetooth.begin(9600);
  //Serial.begin(9600);
}

void loop() {

  if (bluetooth.available() > 0) {
    c = bluetooth.read();

    switch (c) {
      case '1':
        andarFrente();
        break;

      case '2':
        re();
        break;

      case '3':
        direita();
        break;

      case '4':
        esquerda();
        break;

      case '0':
        parar();
        break;
    }
  }

}

void andarFrente() {
  digitalWrite(esquerdaFrente, HIGH);
  digitalWrite(esquerdaRe, LOW);

  digitalWrite(direitaFrente, HIGH);
  digitalWrite(direitaRe, LOW);
}

void re() {
  digitalWrite(esquerdaFrente, LOW);
  digitalWrite(esquerdaRe, HIGH);

  digitalWrite(direitaFrente, LOW);
  digitalWrite(direitaRe, HIGH);
}

void esquerda() {
  digitalWrite(direitaFrente, HIGH);
  digitalWrite(direitaRe, LOW);

  digitalWrite(esquerdaFrente, LOW);
  digitalWrite(esquerdaRe, LOW);
}

void direita() {
  digitalWrite(direitaFrente, LOW);
  digitalWrite(direitaRe, LOW);

  digitalWrite(esquerdaFrente, HIGH);
  digitalWrite(esquerdaRe, LOW);
}

void parar() {
  digitalWrite(direitaFrente, LOW);
  digitalWrite(direitaRe, LOW);

  digitalWrite(esquerdaFrente, LOW);
  digitalWrite(esquerdaRe, LOW);
}
