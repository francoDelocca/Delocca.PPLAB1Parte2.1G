#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Servicios.h"

void mostrarServicio(eServicio servicio, int tamServicios){

    printf("%2d    %10s        %d\n", servicio.id, servicio.descripcion, servicio.precio);
}

//---------------------------------------------------------------------------------------
void mostrarServicios(eServicio servicios[], int tamServicios){

 system("cls");
 printf("****** LISTA SERVICIOS ******\n");
 printf("ID	   DESCRIPCION     PRECIO	\n");

    for(int i=0; i<tamServicios; i++)
    {

            mostrarServicio(servicios[i], tamServicios);

    }

}


