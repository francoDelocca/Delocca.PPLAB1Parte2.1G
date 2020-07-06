#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Servicioss.h"

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

int buscarServicio(int id, eServicio servicios[], int tamServ){

  int indice= -1;

    for(int i=0; i<tamServ; i++)
    {
        if(servicios[i].id == id)
        {
            indice= i;
            break;
        }
    }
  return indice;
}
