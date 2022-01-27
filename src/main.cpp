#include <Arduino.h>

#include <Servo.h>

//////////////Servomotores
Servo petalo1; // crea el objeto servo
Servo petalo2; // crea el objeto servo
Servo petalo3; // crea el objeto servo
Servo petalo4; // crea el objeto servo
Servo petalo5; // crea el objeto servo
Servo petalo6; // crea el objeto servo

//////////////
int pos1 = 20; // posicion del servo offset inicial 130
int pos2 = 20; // posicion del servo offset inicial 130
int pos3 = 20; // posicion del servo offset inicial 130
int pos4 = 20; // posicion del servo offset inicial 130
int pos5 = 20; // posicion del servo offset inicial 130
int pos6 = 20; // posicion del servo offset inicial 130

//////////////

int estado1 = 0; // Estado del paso del servomotor
int estado2 = 0; // Estado del paso del servomotor
int estado3 = 0; // Estado del paso del servomotor
int estado4 = 0; // Estado del paso del servomotor
int estado5 = 0; // Estado del paso del servomotor
int estado6 = 0; // Estado del paso del servomotor

/////////////

void offset()
{
    ///////////////////////////////////// Offset motor1
    int x1 = petalo1.read();
    pos1 = x1;
    for (int i = x1 - 20; i >= 0; i--)
    {
        pos1--;
        petalo1.write(pos1);
        delay(10);
    }
    ///////////////////////////////////// Offset motor2
    int x2 = petalo2.read();
    pos2 = x2;
    for (int i = x2 - 20; i >= 0; i--)
    {
        pos2--;
        petalo2.write(pos2);
        delay(10);
    }
    ///////////////////////////////////// Offset motor3
    int x3 = petalo3.read();
    pos3 = x3;
    for (int i = x3 - 20; i >= 0; i--)
    {
        pos3--;
        petalo3.write(pos3);
        delay(10);
    }
    ///////////////////////////////////// Offset motor4
    int x4 = petalo4.read();
    pos4 = x4;
    for (int i = x4 - 20; i >= 0; i--)
    {
        pos4--;
        petalo4.write(pos4);
        delay(10);
    }
    ///////////////////////////////////// Offset motor5
    int x5 = petalo5.read();
    pos5 = x5;
    for (int i = x5 - 20; i >= 0; i--)
    {
        pos5--;
        petalo5.write(pos5);
        delay(10);
    }
    ///////////////////////////////////// Offset motor6
    int x6 = petalo6.read();
    pos6 = x6;
    for (int i = x6 - 20; i >= 0; i--)
    {
        pos6--;
        petalo6.write(pos6);
        delay(10);
    }
}

void cerrar()
{
    ///////////////////////////////////// ABRIR PETALO1
    if (pos1 <= 130 && estado1 == 0)
    {
        pos1++;
        petalo1.write(pos1);
        delay(10);
        if (pos1 == 130)
        {
            estado1 = 1;
        }
    }
    ///////////////////////////////////// ABRIR PETALO2
    if (pos2 <= 130 && estado2 == 0 && pos1 >= 65)
    {
        pos2++;
        petalo2.write(pos2);
        delay(10);
        if (pos2 == 130)
        {
            estado2 = 1;
        }
    }
    ///////////////////////////////////// ABRIR PETALO3
    if (pos3 <= 130 && estado3 == 0 && pos2 >= 65)
    {
        pos3++;
        petalo3.write(pos3);
        delay(10);
        if (pos3 == 130)
        {
            estado3 = 1;
        }
    }
    ///////////////////////////////////// ABRIR PETALO4
    if (pos4 <= 130 && estado4 == 0 && pos3 >= 65)
    {
        pos4++;
        petalo4.write(pos4);
        delay(10);
        if (pos4 == 130)
        {
            estado4 = 1;
        }
    }
    ///////////////////////////////////// ABRIR PETALO5
    if (pos5 <= 130 && estado5 == 0 && pos4 >= 65)
    {
        pos5++;
        petalo5.write(pos5);
        delay(10);
        if (pos5 == 130)
        {
            estado5 = 1;
        }
    }
    ///////////////////////////////////// ABRIR PETALO6
    if (pos6 <= 130 && estado6 == 0 && pos5 >= 65)
    {
        pos6++;
        petalo6.write(pos6);
        delay(10);
        if (pos6 == 130)
        {
            estado6 = 1;
        }
    }
}

void abrir()
{
    ///////////////////////////////////// ABRIR PETALO1
    if (pos1 >= 20 && estado1 == 1)
    {
        pos1--;
        petalo1.write(pos1);
        delay(10);
        if (pos1 == 20)
        {
            estado1 = 0;
        }
    }
    ///////////////////////////////////// ABRIR PETALO2
    if (pos2 >= 20 && estado2 == 1 && pos1 <= 65)
    {
        pos2--;
        petalo2.write(pos2);
        delay(10);
        if (pos2 == 20)
        {
            estado2 = 0;
        }
    }
    ///////////////////////////////////// ABRIR PETALO3
    if (pos3 >= 20 && estado3 == 1 && pos2 <= 65)
    {
        pos3--;
        petalo3.write(pos3);
        delay(10);
        if (pos3 == 20)
        {
            estado3 = 0;
        }
    }
    ///////////////////////////////////// ABRIR PETALO4
    if (pos4 >= 20 && estado4 == 1 && pos3 <= 65)
    {
        pos4--;
        petalo4.write(pos4);
        delay(10);
        if (pos4 == 20)
        {
            estado4 = 0;
        }
    }
    ///////////////////////////////////// ABRIR PETALO5
    if (pos5 >= 20 && estado5 == 1 && pos4 <= 65)
    {
        pos5--;
        petalo5.write(pos5);
        delay(10);
        if (pos5 == 20)
        {
            estado5 = 0;
        }
    }
    ///////////////////////////////////// ABRIR PETALO6
    if (pos6 >= 20 && estado6 == 1 && pos5 <= 65)
    {
        pos6--;
        petalo6.write(pos6);
        delay(10);
        if (pos6 == 20)
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
    ///////////////// Generador de punto de partida
    Serial.begin(9600);
    Serial.println(petalo1.read());
    offset();
}

void loop()
{
    abrir();
    cerrar();
}