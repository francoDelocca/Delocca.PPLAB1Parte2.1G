#include "Tipos.h"
#include "Colores.h"
#include "Servicios.h"
#include "Clientes.h"
#include "Servicioss.h"
#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED
typedef struct{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int idCliente;
    float rodado;
    int isEmpty;
}eBicicleta;

#endif // BICICLETAS_H_INCLUDED


int altaBicicleta(int idBici, eBicicleta bicicletas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColores, eCliente clientes[], int tamCliente);

//------------------------------------------------------------------------------------------------------------------------


void modificarBicicletas(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamTipo, eColor colores[], int tamColores, eCliente clientes[], int tamCliente);



int menuModificar();



void ordenarBicicletas(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamTipo, eColor colores[], int tamColor, eCliente clientes[], int tamCliente);





int buscarBicicleta(int id, eBicicleta bicicletas[], int tam);



void mostrarBicicletas(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamTipo, eColor colores[], int tamColores, eCliente clientes[], int tamCliente);



void inicializarBicicletas(eBicicleta bicicletas[], int tam);


void mostrarBicicleta(eBicicleta bici, eTipo tipos[], int tamTipo, eColor colores[], int tamColores, eCliente clientes[], int tamCliente);


int menu();


void bajaBicicleta(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamTipo, eColor colores[], int tamColor, eCliente clientes[], int tamCliente);


