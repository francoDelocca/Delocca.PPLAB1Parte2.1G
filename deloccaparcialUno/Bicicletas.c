#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bicicletas.h"

int menu(){

    int opcion;

    system("cls");
    printf("*** Menu de opciones ***\n");
    printf("1) Alta Bicicleta\n");
    printf("2) Modificar bicicleta\n");
    printf("3) Baja bicicleta\n");
    printf("4) Listar bicicleta\n");
    printf("5) Listar colores\n");
    printf("6) Listar tipos\n");
    printf("7) Listar servicios\n");
    printf("8) Alta trabajo\n");
    printf("9) Listar trabajos\n");
    printf("10) Informes\n");
    printf("11) Salir\n");

    printf("Ingrese opcion: \n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

//------------------------------------------------------

int buscarLibreBicicleta(eBicicleta bicicletas[], int tam)
{
	int indice = -1;

	for (int i=0; i< tam; i++)
	{
 		if(bicicletas[i].isEmpty == 1)
		{
    			indice = i;
    			break;
		}
	}
  return indice;
}

int buscarLibreCliente(eCliente clientes[], int tamCliente)
{
	int indice = -1;

	for (int i=0; i< tamCliente; i++)
	{
 		if(clientes[i].isEmpty == 1)
		{
    			indice = i;
    			break;
		}
	}
  return indice;
}

//---------------------------------------------------------
int altaBicicleta(int idBici, eBicicleta bicicletas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColores, eCliente clientes[], int tamCliente){


    int todoOk=0;
    eBicicleta auxBicicleta;
    int indiceBici;

    system("cls");
    printf("*** ALTA Bicicleta *** \n");

    indiceBici= buscarLibreBicicleta(bicicletas, tam);


    if(indiceBici == -1)
    {
        printf("No hay lugar para otra bicicleta\n");
        system("pause");
    }else{

        auxBicicleta.id = idBici;

        printf("Ingrese marca: \n");
        fflush(stdin);
        scanf("%s", auxBicicleta.marca);
        printf("%s", auxBicicleta.marca);
        while(auxBicicleta.marca == NULL || strlen(auxBicicleta.marca) >= 20)
        {

            printf("Error, no ingreso una marca valida. Ingrese marca: \n");
            fflush(stdin);
            scanf("%d", &auxBicicleta.marca);
        }

            listarTipos(tipos, tamTipos);
            printf("Ingrese idTipo: \n");
            scanf("%d", &auxBicicleta.idTipo);

            while(auxBicicleta.idTipo <1000 || auxBicicleta.idTipo>1004)
            {
                printf("Error, no ingreso un id valido. Ingrese id tipo: \n");
                listarTipos(tipos, tamTipos);
                fflush(stdin);
                scanf("%d", &auxBicicleta.idTipo);
            }

                printf("Ingrese rodado: (Solo se admite 20, 26, 27.5 y 29)\n");
                scanf("%f", &auxBicicleta.rodado);
                printf("%f", auxBicicleta.rodado);
                while(auxBicicleta.rodado < 20 && auxBicicleta.rodado > 21 || auxBicicleta.rodado < 26 && auxBicicleta.rodado > 27 || auxBicicleta.rodado < 27.5 && auxBicicleta.rodado > 27.6 ||                       auxBicicleta.rodado < 29 && auxBicicleta.rodado > 30 )
                {
                    printf("Error, ingrese un rodado valido (Solo se admite 20, 26, 27.5 y 29)\n");
                    scanf("%f", &auxBicicleta.rodado);
                }


                listarColores(colores, tamColores);
                printf("Elija un color por su ID: \n");
                fflush(stdin);
                scanf("%d", &auxBicicleta.idColor);
                while(auxBicicleta.idColor <5000 || auxBicicleta.idColor>50004)
                {
                    printf("Error, ingrese id valido: \n");
                    listarColores(colores, tamColores);
                    fflush(stdin);
                    scanf("%d", &auxBicicleta.idColor);
                }

                mostrarClientes(clientes, tamCliente);
                printf("Elija un cliente por su ID: \n");
                fflush(stdin);
                scanf("%d", &auxBicicleta.idCliente);
                while(buscarCliente(auxBicicleta.idCliente, clientes, tamCliente) == -1)
                {
                    mostrarClientes(clientes, tamCliente);
                    printf("Error, ingrese ID valido: \n");
                    fflush(stdin);
                    scanf("%d", &auxBicicleta.idCliente);
                }


                auxBicicleta.isEmpty = 0;
                bicicletas[indiceBici] = auxBicicleta;

                todoOk = 1;

        }

    return todoOk;

}


//---------------------------------------------------------------------------
int buscarBicicleta(int id, eBicicleta bicicletas[], int tam){

  int indice= -1;

    for(int i=0; i<tam; i++)
    {
        if(bicicletas[i].id == id)
        {
            indice= i;
            break;
        }
    }
  return indice;
}



//------------------------------------------------------------
void mostrarBicicleta(eBicicleta bici, eTipo tipos[], int tamTipo, eColor colores[], int tamColores, eCliente clientes[], int tamCliente){

        char descripcionTipo[20];
        char nombreColor[20];
        char nombreCliente[20];

        cargarDescripcionTipo(descripcionTipo, bici.idTipo, tipos, tamTipo);
        cargarNombreColor(nombreColor, bici.idColor, colores, tamColores);
        cargarNombreCliente(nombreCliente, bici.idCliente, clientes, tamCliente);

        printf("%d 	%10s     %10s     %10s    %10s   %.2f\n", bici.id, nombreCliente ,bici.marca, nombreColor, descripcionTipo, bici.rodado);


}

//-----------------------------------------------------------------
void mostrarBicicletas(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamTipo, eColor colores[], int tamColores, eCliente clientes[], int tamCliente){

 int flag=0;
 system("cls");
 printf("****** LISTA BICICLETAS ******\n");
 printf("ID	  CLIENTE      MARCA       COLOR	        TIPO	  RODADO\n");

    for(int i=0; i<tam; i++)
    {
        if(bicicletas[i].isEmpty == 0)
        {
            mostrarBicicleta(bicicletas[i], tipos, tamTipo, colores, tamColores, clientes, tamCliente);
            flag=1;
        }

    }

    if(flag==0)
    {
        printf("No hay bicicletas que mostrar\n");
    }

}

//--------------------------------------------------------
void modificarBicicletas(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamTipo, eColor colores[], int tamColores, eCliente clientes[], int tamCliente){

    int id;
    char confirma;


    system("cls");
    printf("*** Modificar bicicleta ***\n");
    mostrarBicicletas(bicicletas, tam, tipos, tamTipo, colores, tamColores, clientes, tamCliente);
    printf("Ingrese id de la bicicleta a modificar: \n");
    scanf("%d", &id);

    id = buscarBicicleta(id, bicicletas, tam);

    if(id == -1)
    {
        printf("No hay registro de una bicicleta con el id %d\n", id);
        system("pause");
    }else{
        mostrarBicicleta(bicicletas[id], tipos, tamTipo, colores, tamColores, clientes, tamCliente);

        printf("Modifica bicicleta? Ingrese s o n \n");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's'){

           switch(menuModificar()){

            case 1:
                printf("Ingrese nuevo rodado: (Solo se admite 20, 26, 27.5 y 29)\n");
                scanf("%f", &bicicletas[id].rodado);
                while(bicicletas[id].rodado < 20 && bicicletas[id].rodado > 21 || bicicletas[id].rodado < 26 && bicicletas[id].rodado > 27 || bicicletas[id].rodado < 27.5 && bicicletas[id].rodado >                        27.6 || bicicletas[id].rodado < 29 && bicicletas[id].rodado > 30)
                    {
                        printf("Error, ingrese rodado \n");
                        scanf("%f", &bicicletas[id].rodado);
                    }
                    printf("Se modifico el rodado\n");
                    system("pause");
                break;

            case 2:
                listarTipos(tipos, tamTipo);
                printf("Ingrese el id del nuevo tipo: \n");
                scanf("%d", &bicicletas[id].idTipo);
                while(bicicletas[id].idTipo<1000|| bicicletas[id].idTipo>1003)
                    {
                        listarTipos(tipos, tamTipo);
                        printf("Error, el id no es valido. Reingrese: \n");
                        scanf("%d", &bicicletas[id].idTipo);
                    }
                printf("Se modifico el tipo\n");
                system("pause");
                break;

            case 3:
                printf("Salio\n");
                break;
            }//fin switch

        }else{
            printf("Se ha cancelado la operacion\n");
            system("pause");
        }
    }
}

void inicializarBicicletas(eBicicleta bicicletas[], int tam){
    for (int i=0; i<tam; i++)
    {
        bicicletas[i].isEmpty = 1;
    }
}

//------------------------------------------------------------
int menuModificar(){
    int opcion;

    system("cls");
    printf("Opciones a modificar: \n");
    printf("1) Rodado\n");
    printf("2) Tipo\n");
    printf("3) Salir\n");


    printf("Ingrese el numero de la opcion que desee: \n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void ordenarBicicletas(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamTipo, eColor colores[], int tamColor, eCliente clientes[], int tamCliente){

 eBicicleta aux;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(bicicletas[i].idTipo > bicicletas[j].idTipo)
            {
                aux = bicicletas[i];
                bicicletas[i] = bicicletas[j];
                bicicletas[j] = aux;
            }else if(bicicletas[i].idTipo == bicicletas[j].idTipo && bicicletas[i].rodado > bicicletas[j].rodado)
            {
                aux = bicicletas[i];
                bicicletas[i] = bicicletas[j];
                bicicletas[j] = aux;
            }
        }//fin for j
    }//fin for i

    mostrarBicicletas(bicicletas,tam, tipos, tamTipo, colores, tamColor, clientes, tamCliente);
}


//------------------------------------------------------------

//-------------------------------------------------
void bajaBicicleta(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamTipo, eColor colores[], int tamColor, eCliente clientes[], int tamCliente){

    int id;
    int indice;
    char confirma;
    system("cls");
    printf("*** Baja bicicleta ***\n");
    mostrarBicicletas(bicicletas, tam, tipos, tamTipo, colores, tamColor, clientes, tamCliente);
    printf("Ingrese el id de la bicicleta: \n");
    scanf("%d", &id);

    indice = buscarBicicleta(id, bicicletas, tam);

    if(indice == -1)
    {
        printf("No hay registro de una bicicleta con el id %d\n", id);
    }else{
        mostrarBicicleta(bicicletas[indice], tipos, tamTipo, colores, tamColor, clientes, tamCliente);
        printf("Confima baja? Ingrese s o n \n");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's'){
            bicicletas[indice].isEmpty = 1;
            printf("Se ha realizado la baja con exito\n");
        }else{
            printf("Se ha cancelado la operacion\n");
        }
    }
}



