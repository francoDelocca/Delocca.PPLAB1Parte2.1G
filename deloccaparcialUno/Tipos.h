#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED
#include "Servicios.h"
typedef struct{
    int id;
    char descripcion[20];
}eTipo;
#endif // TIPOS_H_INCLUDED


void listarTipos(eTipo tipos[], int tamTipos);


void cargarDescripcionTipo (char descripcion[], int id, eTipo tipos[], int tamTipo);
