#include "Bicicletas.h"
#include "Tipos.h"
#include "Colores.h"
#include "Trabajos.h"

char menuInformes();

//-------------------------------------------------------------------------------------------------------

void informeNotebooks(eBicicleta bicicletas[], int tamB, eTipo tipos[], int tamTipo, eColor colores[], int tamColores, eTrabajo trabajos[], int tamTr, eServicio servicios[], int tamServ, eCliente clientes[], int tamCliente);
//-----------------------------------------------------------------------------------------------------------------------

void listarBicicletasDeTipo(eBicicleta bicicletas[], int tamB, eTipo tipos[], int tamTipo, eColor colores[], int tamColores, eCliente clientes[], int tamCliente);

//-----------------------------------------------------------------------------------------------------
void listarBicicletasDeColor(eBicicleta bicicletas[], int tamB, eTipo tipos[], int tamTipo, eColor colores[], int tamColores, eCliente clientes[], int tamCliente);

void informarMenorRodadoBicicleta(eBicicleta bicicletas[], int tamB, eColor colores[], int tamColores, eTipo tipos[], int tamTipo, eCliente clientes[], int tamCliente);

void informarBicicletasXTipo(eBicicleta bicicletas[], int tamB, eColor colores[], int tamColores, eTipo tipos[], int tamTipo, eCliente clientes[], int tamCliente);

void mostrarBicicletasPorColorYTipo(eBicicleta bicicletas[], int tamB, eColor colores[], int tamColor, eTipo tipos[], int tamTipo);

int obtenerTotalColoresBicicletas(int idColor, eBicicleta bicicletas[], int tamB);

void informarMayorColor (eBicicleta bicicletas[], int tamB, eColor colores[], int tamColores);

void informarTrabajosDeBicicletas (eTrabajo trabajos[], int tamTr, eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo, eServicio servicios[], int tamServ, eColor colores[], int tamColores, eCliente clientes[], int tamCliente);

void informarBicicletasDeServicio(eBicicleta bicicletas[], int tamB, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTr);

void listarBicicletasPorFechaTrabajo(eBicicleta bicicletas[], int tam, eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamServ);

void preciosServiciosBicicletas(eBicicleta bicicletas[], int tamB, eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eTrabajo trabajos[], int tamTrabajos, eServicio servicios[], int tamServicio, eCliente clientes[], int tamCliente);

