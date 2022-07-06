//Control del encendido y apagado de un led por medio de push button

int ledPin = 10; // Asignación del Pin 10 para el Led
int onApin = 9; //Asignación del Pin 9 para el push button que nos ayudará a encender el Led
int offBpin = 8; //Asignación del Pin 8 para el push button que nos ayudará a apagar el Led
byte leds = 0; //Se declara una variable leds para controlar en estado, actual del led (on/off)

//Tipo byte (números que representan 8 bits)
void setup()
{
  pinMode(ledPin, OUTPUT); //Declaración del pin de salida a ledPin / pin 10
  //Declaración de los push button en modo PULL UP ()
  //Podamos conectar directamente al Arduino sin apoyo de una resistencia física
  pinMode(onApin, INPUT_PULLUP);
  pinMode(offBpin, INPUT_PULLUP);
}
void loop()
{
//Realizaremos lectura de la entrada digital del pin 9 / pin 8 y realizando acciones dependiendo
//el estado en que se encuentre
if (digitalRead(onApin) == LOW) //Si se presiona el botón del pin 9 que se encuentra en nivel
//Alto pasará a nivel Bajo y por consiguiente...
{
  digitalWrite(ledPin, HIGH); //El led se encenderá
}
if (digitalRead(offBpin) == LOW) //Si se presiona el botón del pin 8
{
  digitalWrite(ledPin, LOW); //El led se apagará
}
}
