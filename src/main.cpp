#include <Arduino.h>
///////////////// Libreria del servomotor
#include <Servo.h>
////////////////// Libreria de la tira LED
#include <Adafruit_NeoPixel.h> //Incluimos la libreria de Adafruit NeoPixel con la que controlaremos los LED.
//#include <Adafruit_Sensor.h>

/*
Los servomotores empiezan cerrados en el 180 (170)
Y se abren a una altura de 60 o un poco ma algunos.
*/
//////////////Servomotores
Servo petalo1; // crea el objeto servo
Servo petalo2; // crea el objeto servo
Servo petalo3; // crea el objeto servo
Servo petalo4; // crea el objeto servo
Servo petalo5; // crea el objeto servo
Servo petalo6; // crea el objeto servo

int tiemposervo = 10;

//////////////
int pos1 = 180; // posicion del servo offset inicial 130
int pos2 = 170; // posicion del servo offset inicial 130
int pos3 = 150; // posicion del servo offset inicial 130
int pos4 = 135; // posicion del servo offset inicial 130
int pos5 = 158; // posicion del servo offset inicial 130
int pos6 = 167; // posicion del servo offset inicial 130

//////////////
int caso = 0; // Posición del momento
int estadoLED = 0;
int estado1 = 0; // Estado del paso del servomotor
int estado2 = 0; // Estado del paso del servomotor
int estado3 = 0; // Estado del paso del servomotor
int estado4 = 0; // Estado del paso del servomotor
int estado5 = 0; // Estado del paso del servomotor
int estado6 = 0; // Estado del paso del servomotor

///////////// Declaramos libreria NEOPIXEL
Adafruit_NeoPixel pixels(197, 8, NEO_GRB + NEO_KHZ800); // inicializamos el LED PIXEL
/////////////

void abrir()
{
    ///////////////////////////////////// Servo 1
    for (uint8_t i = 180; i > 45; i--)
    {
        petalo1.write(i);
        delay(tiemposervo);
    }
    ///////////////////////////////////// Servo 2
    for (uint8_t i = 170; i > 45; i--)
    {
        petalo2.write(i);
        delay(tiemposervo);
    }
    ///////////////////////////////////// Servo 3
    for (uint8_t i = 150; i > 30; i--)
    {
        petalo3.write(i);
        delay(tiemposervo);
    } ///////////////////////////////////// Servo 4
    for (uint8_t i = 135; i > 20; i--)
    {
        petalo4.write(i);
        delay(tiemposervo);
    }
    ///////////////////////////////////// Servo 5
    for (uint8_t i = 158; i > 40; i--)
    {
        petalo5.write(i);
        delay(tiemposervo);
    }
    ///////////////////////////////////// Servo 6
    for (uint8_t i = 167; i > 30; i--)
    {
        petalo6.write(i);
        delay(tiemposervo);
    }
}

void cerrar()
{
    ///////////////////////////////////// Servo 1
    for (uint8_t i = 45; i < 180; i++)
    {
        petalo1.write(i);
        delay(tiemposervo);
    }
    ///////////////////////////////////// Servo 2
    for (uint8_t i = 45; i < 170; i++)
    {
        petalo2.write(i);
        delay(tiemposervo);
    }
    ///////////////////////////////////// Servo 3
    for (uint8_t i = 30; i < 150; i++)
    {
        petalo3.write(i);
        delay(tiemposervo);
    }
    ///////////////////////////////////// Servo 4
    for (uint8_t i = 20; i < 135; i++)
    {
        petalo4.write(i);
        delay(tiemposervo);
    }
    ///////////////////////////////////// Servo 5
    for (uint8_t i = 40; i < 158; i++)
    {
        petalo5.write(i);
        delay(tiemposervo);
    }
    ///////////////////////////////////// Servo 6
    for (uint8_t i = 30; i < 167; i++)
    {
        petalo6.write(i);
        delay(tiemposervo);
    }
}

void setup()
{
    petalo1.attach(3);  // vincula el servo al pin digital 3
    petalo2.attach(5);  // vincula el servo al pin digital 5
    petalo3.attach(6);  // vincula el servo al pin digital 6
    petalo4.attach(9);  // vincula el servo al pin digital 9
    petalo5.attach(10); // vincula el servo al pin digital 10
    petalo6.attach(11); // vincula el servo al pin digital 11
    Serial.begin(9600);
    pinMode(A0, INPUT);
    /////////////////
    Serial.begin(9600);
    pixels.begin(); // Inicializamos el objeto "pixels"
    pixels.clear();
    ///////////////// Ofseet
    // offset();
    petalo1.write(pos1);
    petalo2.write(pos2);
    petalo3.write(pos3);
    petalo4.write(pos4);
    petalo5.write(pos5);
    petalo6.write(pos6);
    delay(500);
}

void loop()
{
    ///////////////////////////////// Leemos el valor del sensor
    int distancia = 0;
    for (uint8_t i = 0; i < 50; i++)
    {
        distancia = analogRead(A0);
        distancia = distancia + distancia;
    }
    int sensor = distancia / 50;
    Serial.println(sensor);

    /////////////////////////////////// Si detectamos persona enciende los LEDS
    if (sensor >= 14 && caso == 0)
    {
        for (int i = 0; i < 197; i++)
        {
            pixels.setPixelColor(i, pixels.Color(0, 255, 0)); // establecemos 50 (intensidad) en el nivel de verde de la matrz (R,G,B)
            pixels.show();
            delay(3);
        }

        delay(5000);
        caso = 1;
        delay(3000);
    }
    ///////////////////////////// Apagamos los LEDS
    if (caso == 1)
    {
        for (int i = 0; i < 197; i++)
        {
            pixels.setPixelColor(i, pixels.Color(255, 0, 0)); // establecemos 50 (intensidad) en el nivel de verde de la matrz (R,G,B)
            pixels.show();
            delay(5);
        }
        abrir();
        delay(5000);
        cerrar();
        for (int i = 0; i < 197; i++)
        {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // establecemos 50 (intensidad) en el nivel de verde de la matrz (R,G,B)
            pixels.show();
            delay(3);
        }
        caso = 0;
    }
}