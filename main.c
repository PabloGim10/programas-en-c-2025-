#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct
{
    int anio, mes, dia, hora, minuto, segundo;
} tiempo;

typedef struct
{
    char * nombre;
    tiempo ultima_mod;
} Archivo;




void iniTIEMPO (tiempo* t)
{
    t->anio=rand() % 2026;
    t->mes = rand() % 13;
    t->dia = rand() % 30;
    t->hora = rand() % 24;
    t->minuto = rand() % 60;
    t->segundo = rand() % 60;
}

void INIarchivo (Archivo * lista, int n)
{

    for (int i=0; i<n; i++)
    {

        tiempo* temp = &lista[i].ultima_mod;
        lista[i].nombre = (char*)malloc(100 * sizeof(char));
        printf("ingrese el nombre del archivo %d: ", i+1);
        scanf("%s",lista[i].nombre);

        iniTIEMPO(temp);


    }
}

void mostrarLista(Archivo* lista, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Archivo #%d\n", i + 1);
        printf("Nombre: %s\n", lista[i].nombre);
        printf("Ultima modificacion: %02d/%02d/%04d %02d:%02d:%02d\n",
               lista[i].ultima_mod.dia,
               lista[i].ultima_mod.mes,
               lista[i].ultima_mod.anio,
               lista[i].ultima_mod.hora,
               lista[i].ultima_mod.minuto,
               lista[i].ultima_mod.segundo);
        printf("-----------------------------\n");
    }
}

void ordena_alfa( Archivo * lista, int n )
{

}

int compara_tiempos (tiempo *T1, tiempo *T2)
{
    if (T1->anio < T2->anio) return 1;
    if (T1->anio > T2->anio) return -1;

    if (T1->mes < T2->mes) return 1;
    if (T1->mes > T2->mes) return -1;

    if (T1->dia < T2->dia) return 1;
    if (T1->dia > T2->dia) return -1;

    if (T1->hora < T2->hora) return 1;
    if (T1->hora > T2->hora) return -1;

    if (T1->minuto < T2->minuto) return 1;
    if (T1->minuto > T2->minuto) return -1;

    if (T1->segundo < T2->segundo) return 1;
    if (T1->segundo > T2->segundo) return -1;

    return 0; // Son iguales

}


int main()
{
    Archivo lista [3];
    srand(time(NULL));
    tiempo T1, T2;
    tiempo* TT1 = &T1;
    tiempo* TT2 = &T2;
    iniTIEMPO(TT1);
    TT2 = &T2;
    iniTIEMPO(TT2);

    printf("EL TIEMPO 1 ES: \n");
    printf("%d / %d / %d     %d : %d : %d \n",T1.dia,T1.mes,T1.anio, T1.hora, T1.minuto, T1.segundo);

    printf("EL TIEMPO 2 ES: \n");
    printf("%d / %d / %d     %d : %d : %d \n",T2.dia,T2.mes,T2.anio, T2.hora, T2.minuto, T2.segundo);


    int comparador = compara_tiempos(TT1, TT2);

    switch (comparador)
    {
    case 1:
        printf("TIEMPO 1 ES ANTERIOR A TIEMPO 2\n");
        break;
    case 0:

        printf("TIEMPO 1 ES IGUAL A TIEMPO 2\n");
        break;

    case -1:
        printf("TIEMPO 1 ES ANTERIOR A TIEMPO 2\n");
        break;
    }

    //Archivo * plist = &lista;

    INIarchivo(lista,3);
    mostrarLista(lista,3);
    return 0;
}
