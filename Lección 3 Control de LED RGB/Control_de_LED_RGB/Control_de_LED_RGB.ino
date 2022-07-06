//Uso de un Led RGB y cambio de algunos colores cada segundo
int rojoPin = 3; // El control del color Rojo por el pin 3
int verdePin = 5; //El control del color Verde por el pin 5
int azulPin = 6; //El control del color Azul por el pin 6
// Se definen como salidas a los pines 3, 5, 6; correspondientes al color del RGB
void setup() {
  pinMode(rojoPin, OUTPUT);
  pinMode(verdePin, OUTPUT);
  pinMode(azulPin, OUTPUT);
}

void loop() {
  // Valor del ciclo de trabajo PWM (0 a 255), que nos ayudará a tener control de la intensidad de
  //brillo por cada uno de los colores (rojo, verde, azul), con ayuda de la función "setColor"
  setColor(255, 0, 0); //Brillará en color Rojo
  delay(1000); //Instrucción que durará 1s (1000ms)
  setColor(0, 255, 0); //Brillará en color Verde
  delay(1000); //Instrucción que durará 1s (1000ms)
  setColor(0, 0, 255); //Brillará en color Azul
  delay(1000); //Instrucción que durará 1s (1000ms)
  //Si colocamos el PWM de todos los colores en máximo
  setColor(255, 255, 255); //Brillara en Blanco
  delay(1000); //Instrucción que durará 1s (1000ms)
  //Si realizamos combinación de los valores podremos obtener más gama de colores
  setColor(180, 0, 255); // Brillará en color Morado
  delay(1000); //Instrucción que durará 1s (1000ms)
}
//Función "setColor()" tendremos acceso al control de los pines PWM
//mostrando a la salida los colores que previamente indicamos
//por medio del argumento (rojo, verde, azul); que serán valores de entra:
//rojoValue, verdeValue and azulValue.
void setColor(int rojoValue, int verdeValue, int azulValue) {
  analogWrite(rojoPin, rojoValue);
  analogWrite(verdePin, verdeValue);
  analogWrite(azulPin, azulValue);
}
