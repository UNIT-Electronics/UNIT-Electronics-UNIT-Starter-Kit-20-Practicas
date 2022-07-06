//Librerías para el uso del módulo de tiempo real
#include <ThreeWire.h>
#include <RtcDS1302.h>
//Espacio de matriz para definir datos de hora y fecha
#define countof(a) (sizeof(a) / sizeof(a[0]))
//Pines asociados a la conexión del módulo con la tarjeta UNO R3
ThreeWire myWire(4, 5, 2); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);
//variable bool para activar o desactivar alarma
bool alarma = true;
//variable de salida para encender el led
int led = 9;
//Definición de variables de salida y comienzo de monitor serial y variable RTC
void setup ()
{
  Serial.begin(57600);
  Rtc.Begin();
  pinMode(led, OUTPUT);
}
void loop ()
{
  //Variable now guardará el valor de la fecha y hora actual
  RtcDateTime now = Rtc.GetDateTime(); 
  infoTiempo(now);
  //La variable ejecutará proceso en la función
  infoTiempo; 
  analogWrite(led, LOW); //El led siempre tendrá un valor bajo al iniciar el programa
}
//función infoTiempo que realizará la impresión de datos de hora y fecha
void infoTiempo(const RtcDateTime& dt)
{
  char datestring[20];
  snprintf_P(datestring, countof(datestring), PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
             dt.Month(),
             dt.Day(),
             dt.Year(),
             dt.Hour(),
             dt.Minute(),
             dt.Second() );
  //configuración de activación de alarma a las 14hr y 47 min
  if (dt.Hour() == 14 && dt.Minute() == 47) {
    if (alarma = true) {
      Serial.println("Alarma");
      analogWrite(led, HIGH);
      alarma = false; //desactiva alarma
    }
  }
  Serial.println(datestring);
  delay(1000);
  //configuración desactivación de alarma a las 14hr y 49 min
  if (dt.Hour() == 14 && dt.Minute() == 49) analogWrite(led, LOW);
  alarma = true;
}
