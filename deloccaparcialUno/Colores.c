#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Colores.h"

//-------------------------------------------------------------------------
void cargarNombreColor (char nombreColor[], int id, eColor colores[], int tamColores){

	for (int i=0; i<tamColores; i++)
    {
        if (colores[i].id == id)
        {
            strcpy(nombreColor, colores[i].nombreColor);
        }
	}

}


//------------------------------------------------------
void listarColores(eColor colores[], int tamColores)
{
    system("cls");
    printf("\n*** Listado de colores ***\n\n");
    printf("   Id       DESCRIPCION\n");
    for (int i=0; i< tamColores; i++)
    {
       printf("    %d    %10s\n",colores[i].id, colores[i].nombreColor);
    }
    printf("\n\n");
}
