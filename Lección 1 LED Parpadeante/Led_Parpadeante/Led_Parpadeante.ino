//Parpadeo de un led cada segundo

int ledPin=8; //Control del Led por medio del pin 8

void setup()
{
  pinMode(ledPin, OUTPUT); //Se declara al "ledPin" como pin de salida
}

void loop()
{
  digitalWrite(ledPin, HIGH); // Encendido del Led (HIGH marca el nivel de voltaje)
  delay(1000); //Permanecerá en este estado 1000 ms (1s)
  digitalWrite(ledPin, LOW); //Apagado del Led (LOW marca el nivel de voltaje bajo)
  delay(1000); //Permanecerá en este estado 1000 ms (1s)
}
