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
    
    void listarPCs(compu pcs[], int cantidad);
    void mostrarMasVieja(compu pcs[], int cantidad);
    void mostrarMasVeloz(compu pcs[], int cantidad);


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

    listarPCs(pc,numCompu);
    mostrarMasVieja(pc,numCompu);
    mostrarMasVeloz(pc,numCompu);
    


    return 0;
}

void listarPCs(compu pcs[], int cantidad){
    for (int i = 0; i < cantidad; i++)
    {
        printf("Pc %d\n", i+1);
        printf("Anio de fabricacion: %d\n", pcs[i].anio);
        printf("Cantidad de nucleos: %d\n", pcs[i].cantidad_nucleos);
        printf("Velocidad de procesamiento en GHz: %d\n", pcs[i].velocidad);
        printf("Tipo de procesador: %s\n", pcs[i].tipo_cpu);
    }
    
}

void mostrarMasVieja(compu pcs[], int cantidad){
    int laMasVieja = 2025, pcNum;
    for (int i = 0; i < cantidad; i++)
    {
        if (laMasVieja > pcs[i].anio)
        {
            laMasVieja = pcs[i].anio;
            pcNum = i;
        }
    }
    printf("---La pc mas vieja es la Pc %d---\n", pcNum + 1);
    printf("Anio de fabricacion: %d\n", pcs[pcNum].anio);
    printf("Cantidad de nucleos: %d\n", pcs[pcNum].cantidad_nucleos);
    printf("Velocidad de procesamiento en GHz: %d\n", pcs[pcNum].velocidad);
    printf("Tipo de procesador: %s\n", pcs[pcNum].tipo_cpu);
}

void mostrarMasVeloz(compu pcs[], int cantidad){
    int laMasRapida = 0, pcNum;
    for (int i = 0; i < cantidad; i++)
    {
        if (laMasRapida < pcs[i].velocidad)
        {
            laMasRapida = pcs[i].velocidad;
            pcNum = i;
        }
    }
    printf("+++La pc mas rapida es la Pc %d+++\n", pcNum + 1);
    printf("Anio de fabricacion: %d\n", pcs[pcNum].anio);
    printf("Cantidad de nucleos: %d\n", pcs[pcNum].cantidad_nucleos);
    printf("Velocidad de procesamiento en GHz: %d\n", pcs[pcNum].velocidad);
    printf("Tipo de procesador: %s\n", pcs[pcNum].tipo_cpu);
}