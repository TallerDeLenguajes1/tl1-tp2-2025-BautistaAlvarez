#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct{
    int velocidad; // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio; // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu; // Tipo de procesador (apuntador a cadena de caracteres)
   } typedef compu;
   char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", //usar este tipo de arreglo
    "Pentium"};
    

int main(){
    srand(time(NULL));

    int numCompu = 5;
    compu *pc = (compu *)malloc(numCompu * sizeof(compu));

    //inicio aleatoriamente los datos a 5 pc's

    for (int i = 0; i < numCompu; i++)
    {
        pc[i].velocidad = 1 + rand()%(3 - 1 + 1);
        pc[i].anio = 2015 + rand()%(2024 - 2015 + 1);
        pc[i].cantidad_nucleos = 1 + rand()%(8 - 1 + 1);
        pc[i].tipo_cpu = tipos[rand() % 6];
    }
    


    return 0;
}