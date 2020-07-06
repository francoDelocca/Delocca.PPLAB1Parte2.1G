#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED
#include "Servicios.h"
typedef struct{
    int id;
    char nombreColor[20];
}eColor;
#endif // COLORES_H_INCLUDED


void listarColores(eColor colores[], int tamColores);


void cargarNombreColor (char nombreColor[], int id, eColor colores[], int tamColores);
