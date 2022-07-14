#include <SoftwareSerial.h> //Biblioteca para conectar com o bluetooth (já vem instalado), não precisa baixar
#include <String.h>

SoftwareSerial bluetooth(2, 3); // Portas para o serial do bluetooth (RX, TX)

int green1 = 7; // Pinos digitais dos leds
int green2 = 6;
int red1 = 8;
int red2 = 9;
int yel1 = 11;
int yel2 = 12;

char text; // Variável que vai ler o valor enviado pelo bluetooth

void piscar(char led1, char led2);
void acender(char led, char led1);
void apagar(char led1, char led2);
void acenderTodos();
void piscarTodos();

void setup()

{
  bluetooth.begin(9600);   //inicializando serial
  pinMode(green1, OUTPUT); //Ligando a saída dos leds
  pinMode(green2, OUTPUT);
  pinMode(red1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(yel1, OUTPUT);
  pinMode(yel2, OUTPUT);

}

void loop() {
  if (bluetooth.available() > 0) { //Se o bluetooth estiver funcionando, vai ser lido o "valor", para reproduzir o comando
    text = bluetooth.read();

    if (text == '0') {
      apagar(green1, green2);
      apagar(yel1, yel2);
      apagar(red1, red2);
      bluetooth.println("LEDs DESLIGADOS");
    }

    else if (text == '1') {
      acender(green1, green2);
      bluetooth.println("LED VERDE LIGADO");
    }

    else if (text == '2') {
      acender(red1, red2);
      bluetooth.println("LED VERMELHO LIGADO");
    }

    else if (text == '3') {
      acender(yel1, yel2);
      bluetooth.println("LED AMARELO LIGADO");
    }

    else if (text == '4') {
      acender(green1, green2);
      acender(yel1, yel2);
      acender(red1, red2);
    }

    else if (text == '5') {
      piscar(green1, green2);
    }

    else if (text == '6') {
      acenderTodos();
    }

    else if (text == '7') {
      piscarTodos();
    }

    else if (text == '8') {
      piscar(red1, red2);
    }

    else if (text == '9') {
      piscar(yel1, yel2);
    }
  }
}

void acender(char led, char led1) {
  digitalWrite(led, HIGH);
  digitalWrite(led1, HIGH);
  delay(100);
}

void apagar(char led1, char led2) {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

void piscar(char led1, char led2) {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(50);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  delay(50);
}

void acenderTodos() {
  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);
  digitalWrite(yel1, HIGH);
  digitalWrite(yel2, HIGH);
  digitalWrite(green1, HIGH);
  digitalWrite(green2, HIGH);
}

void piscarTodos() {
  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);
  delay(50);
  digitalWrite(red1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(yel1, HIGH);
  digitalWrite(yel2, HIGH);
  delay(50);
  digitalWrite(yel1, LOW);
  digitalWrite(yel2, LOW);
  digitalWrite(green1, HIGH);
  digitalWrite(green2, HIGH);
  delay(50);
  digitalWrite(green1, LOW);
  digitalWrite(green2, LOW);
}
