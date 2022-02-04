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

//////////////
int pos1 = 180; // posicion del servo offset inicial 130
int pos2 = 180; // posicion del servo offset inicial 130
int pos3 = 180; // posicion del servo offset inicial 130
int pos4 = 150; // posicion del servo offset inicial 130
int pos5 = 175; // posicion del servo offset inicial 130
int pos6 = 180; // posicion del servo offset inicial 130

//////////////

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

void offset()
{
    ///////////////////////////////////// Offset motor1
    int x1 = petalo1.read();
    pos1 = x1;
    for (int i = x1 + 170; i >= 0; i++)
    {
        pos1++;
        petalo1.write(pos1);
        delay(10);
    }
    ///////////////////////////////////// Offset motor2
    int x2 = petalo2.read();
    pos2 = x2;
    for (int i = x2 + 170; i >= 0; i++)
    {
        pos2++;
        petalo2.write(pos2);
        delay(10);
    }
    ///////////////////////////////////// Offset motor3
    int x3 = petalo3.read();
    pos3 = x3;
    for (int i = x3 + 170; i >= 0; i++)
    {
        pos3++;
        petalo3.write(pos3);
        delay(10);
    }
    ///////////////////////////////////// Offset motor4
    int x4 = petalo4.read();
    pos4 = x4;
    for (int i = x4 + 170; i >= 0; i++)
    {
        pos4++;
        petalo4.write(pos4);
        delay(10);
    }
    ///////////////////////////////////// Offset motor5
    int x5 = petalo5.read();
    pos5 = x5;
    for (int i = x5 + 170; i >= 0; i++)
    {
        pos5++;
        petalo5.write(pos5);
        delay(10);
    }
    ///////////////////////////////////// Offset motor6
    int x6 = petalo6.read();
    pos6 = x6;
    for (int i = x6 + 170; i >= 0; i++)
    {
        pos6++;
        petalo6.write(pos6);
        delay(10);
    }
}

void abrir()
{
    ///////////////////////////////////// ABRIR PETALO1
    if (estado1 == 0)
    {
        pos1--;
        petalo1.write(pos1);
        delay(10);
        if (pos1 == 45) // Ultimo angulo de apertura
        {
            estado1 = 1;
        }
    }
    ///////////////////////////////////// ABRIR PETALO2
    if (estado2 == 0 && pos1 <= 90)
    {
        pos2--;
        petalo2.write(pos2);
        delay(10);
        if (pos2 == 45) // Ultimo angulo de apertura
        {
            estado2 = 1;
        }
    }
    ///////////////////////////////////// ABRIR PETALO3
    if (estado3 == 0 && pos2 <= 90)
    {
        pos3--;
        petalo3.write(pos3);
        delay(10);
        if (pos3 == 30) // Ultimo angulo de apertura
        {
            estado3 = 1;
        }
    }
    ///////////////////////////////////// ABRIR PETALO4
    if (estado4 == 0 && pos3 <= 90)
    {
        pos4--;
        petalo4.write(pos4);
        delay(10);
        if (pos4 == 10) // Ultimo angulo de apertura
        {
            estado4 = 1;
        }
    }
    ///////////////////////////////////// ABRIR PETALO5
    if (estado5 == 0 && pos4 <= 90)
    {
        pos5--;
        petalo5.write(pos5);
        delay(10);
        if (pos5 == 40) // Ultimo angulo de apertura
        {
            estado5 = 1;
        }
    }
    ///////////////////////////////////// ABRIR PETALO6
    if (estado6 == 0 && pos5 <= 90)
    {
        pos6--;
        petalo6.write(pos6);
        delay(10);
        if (pos6 == 20) // Ultimo angulo de apertura
        {
            estado6 = 1;
        }
    }
}

void cerrar()
{
    ///////////////////////////////////// ABRIR PETALO1
    if (estado1 == 1)
    {
        pos1++;
        petalo1.write(pos1);
        delay(10);
        if (pos1 == 170)
        {
            estado1 = 0;
        }
    }
    ///////////////////////////////////// ABRIR PETALO2
    if (estado2 == 1 && pos1 >= 90)
    {
        pos2++;
        petalo2.write(pos2);
        delay(10);
        if (pos2 == 170)
        {
            estado2 = 0;
        }
    }
    ///////////////////////////////////// ABRIR PETALO3
    if (estado3 == 1 && pos2 >= 90)
    {
        pos3++;
        petalo3.write(pos3);
        delay(10);
        if (pos3 == 170)
        {
            estado3 = 0;
        }
    }
    ///////////////////////////////////// ABRIR PETALO4
    if (estado4 == 1 && pos3 >= 90)
    {
        pos4++;
        petalo4.write(pos4);
        delay(10);
        if (pos4 == 170)
        {
            estado4 = 0;
        }
    }
    ///////////////////////////////////// ABRIR PETALO5
    if (estado5 == 1 && pos4 >= 90)
    {
        pos5++;
        petalo5.write(pos5);
        delay(10);
        if (pos5 == 170)
        {
            estado5 = 0;
        }
    }
    ///////////////////////////////////// ABRIR PETALO6
    if (estado6 == 1 && pos5 >= 90)
    {
        pos6++;
        petalo6.write(pos6);
        delay(10);
        if (pos6 == 170)
        {
            estado6 = 0;
        }
    }
}

void abrirtodo()
{
    ///////////////////////////////////// ABRIR PETALO1
    if (estado1 == 0)
    {
        pos1--;
        petalo1.write(pos1);
        delay(10);
        if (pos1 == 45) // Ultimo angulo de apertura
        {
            estado1 = 1;
        }
    }
    ///////////////////////////////////// ABRIR PETALO2
    if (estado2 == 0)
    {
        pos2--;
        petalo2.write(pos2);
        delay(10);
        if (pos2 == 45) // Ultimo angulo de apertura
        {
            estado2 = 1;
        }
    }
    ///////////////////////////////////// ABRIR PETALO3
    if (estado3 == 0)
    {
        pos3--;
        petalo3.write(pos3);
        delay(10);
        if (pos3 == 30) // Ultimo angulo de apertura
        {
            estado3 = 1;
        }
    }
    ///////////////////////////////////// ABRIR PETALO4
    if (estado4 == 0)
    {
        pos4--;
        petalo4.write(pos4);
        delay(10);
        if (pos4 == 10) // Ultimo angulo de apertura
        {
            estado4 = 1;
        }
    }
    ///////////////////////////////////// ABRIR PETALO5
    if (estado5 == 0)
    {
        pos5--;
        petalo5.write(pos5);
        delay(10);
        if (pos5 == 40) // Ultimo angulo de apertura
        {
            estado5 = 1;
        }
    }
    ///////////////////////////////////// ABRIR PETALO6
    if (estado6 == 0)
    {
        pos6--;
        petalo6.write(pos6);
        delay(10);
        if (pos6 == 20) // Ultimo angulo de apertura
        {
            estado6 = 1;
        }
    }
}

void cerrartodo()
{
    ///////////////////////////////////// ABRIR PETALO1
    if (estado1 == 1)
    {
        pos1++;
        petalo1.write(pos1);
        delay(10);
        if (pos1 == 170)
        {
            estado1 = 0;
        }
    }
    ///////////////////////////////////// ABRIR PETALO2
    if (estado2 == 1)
    {
        pos2++;
        petalo2.write(pos2);
        delay(10);
        if (pos2 == 170)
        {
            estado2 = 0;
        }
    }
    ///////////////////////////////////// ABRIR PETALO3
    if (estado3 == 1)
    {
        pos3++;
        petalo3.write(pos3);
        delay(10);
        if (pos3 == 170)
        {
            estado3 = 0;
        }
    }
    ///////////////////////////////////// ABRIR PETALO4
    if (estado4 == 1)
    {
        pos4++;
        petalo4.write(pos4);
        delay(10);
        if (pos4 == 170)
        {
            estado4 = 0;
        }
    }
    ///////////////////////////////////// ABRIR PETALO5
    if (estado5 == 1)
    {
        pos5++;
        petalo5.write(pos5);
        delay(10);
        if (pos5 == 170)
        {
            estado5 = 0;
        }
    }
    ///////////////////////////////////// ABRIR PETALO6
    if (estado6 == 1)
    {
        pos6++;
        petalo6.write(pos6);
        delay(10);
        if (pos6 == 170)
        {
            estado6 = 0;
        }
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
    /////////////////
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
    // petalo1.write(180);
    abrirtodo();
    cerrartodo();
    /*
        pixels.clear(); // limpiamos el posible color anterior
        for (int i = 0; i < 197; i++)
        {
            pixels.setPixelColor(i, pixels.Color(255, 0, 0)); // establecemos 50 (intensidad) en el nivel de verde de la matrz (R,G,B)
            pixels.show();
            delay(10);
        }

        for (int i = 0; i < 197; i++)
        {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // establecemos 50 (intensidad) en el nivel de verde de la matrz (R,G,B)
            pixels.show();
            delay(10);
        }
        */
}