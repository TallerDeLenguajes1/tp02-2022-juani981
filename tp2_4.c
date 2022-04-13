#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
#define CANTCOMPUS 5
struct compu
{
    int velocidad;
    int anio;
    int cantidad;
    char *tipo_cpu;
} typedef compu;

void mostrar (compu *computadora,int cant);
void masRapida (compu *computadora,int cant);
void masVieja(compu *computadora,int cant);

int main()
{
    compu computadoras[CANTCOMPUS];
    compu *compu_usuario;
    compu_usuario=computadoras;
    srand((int)time(NULL));
    char tipos[6][50] = {{"Intel"}, {"AMD"}, {"Celeron"}, {"Athlon"}, {"Core"}, {"Pentium"}};

    for (int i = 0; i < CANTCOMPUS; i++)
    {
        compu_usuario->velocidad = rand()%2 + 1;
        compu_usuario->cantidad= rand()%7 + 1;
        compu_usuario->anio= rand()%7 + 2015 ; // 2015 y 2022
        int aleat = rand()%5;
        compu_usuario->tipo_cpu = tipos[aleat];
        compu_usuario++;
    }

    compu_usuario = computadoras;

    mostrar(compu_usuario,CANTCOMPUS);
    masVieja(compu_usuario,CANTCOMPUS);
    masRapida(compu_usuario,CANTCOMPUS);


    return 0;
}

void mostrar (compu *computadora,int cant){

    
    for (int i = 0; i < cant; i++)
    {
        printf("\n Computadora %d)\n", i+1);
        printf("Velocidad: %d Ghz \n ",computadora->velocidad);
        printf("Cantidad: %d\n",computadora->cantidad);
        printf("Anio: %d\n",computadora->anio);
        printf("Tipo: %s",computadora->tipo_cpu);
        computadora++;
    }
    
}


void masVieja(compu *computadora,int cant){

    int mayor = 2022;
    char *cpu;
    int num;
    for (int i = 0; i < cant; i++)
    {
        if (computadora->anio < mayor)
        {
             mayor = computadora->anio;
             cpu = computadora->tipo_cpu;
             num = i+1;
        }

        computadora++;
    }

    printf("\n La compu mas antigua es la numero %d, una %s del anio %d \n",num,cpu,mayor);
    
}

void masRapida (compu *computadora,int cant){

    int mayor = 0;
    int num;
    char *cpu;

    for (int i = 0; i < cant; i++)
    {
        if (computadora->velocidad > mayor)
        {
             mayor = computadora->velocidad;
             cpu = computadora->tipo_cpu;
             num = i+1;
        }

        computadora++;
    }

    printf("\n La computadora mas rapida es la numero %d, una %s de %d Ghz\n",num,cpu,mayor);
}