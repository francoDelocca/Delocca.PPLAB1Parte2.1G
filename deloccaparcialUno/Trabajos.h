#include "Tipos.h"
#include "Bicicletas.h"
#include "Colores.h"
#include "Servicios.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
typedef struct{
 int dia;
 int mes;
 int anio;
}eFecha;


typedef struct{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;
#endif // TRABAJO_H_INCLUDED



int altaTrabajo(int id, eBicicleta bicicletas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColores, eServicio servicios[], int tamServ, eTrabajo trabajos[], int tamTrabajo, eCliente clientes[], int tamCliente);


void mostrarTrabajos(eTrabajo trabajos[], int tam, eBicicleta bicicletas[], int tamBici, eServicio servicios[], int tamServ);


void mostrarTrabajo(eTrabajo trabajo, eBicicleta bicicletas[], int tamBici, eServicio servicios[], int tamServ);


int cargarDescripcionServicioTrabajo (char descripcion[], int id, eServicio servicios[], int tam);


int cargarMarcaBicicletaTrabajo (char marca[], int id, eBicicleta bicicletas[], int tam);


void inicializarTrabajos(eTrabajo trabajos[], int tam);

