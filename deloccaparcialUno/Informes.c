#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Informes.h"
#include "Trabajos.h"
char menuInformes()
{
    char opcion;
    system("cls");
    printf("*********** Informes ***********\n");
    printf("a- Mostrar bicicletas del color seleccionado \n");
    printf("b- Mostrar bicicletas de un tipo seleccionado\n");
    printf("c- Informar la o las bicicletas de menor rodado\n");
    printf("d- Mostrar un listado de las bicicletas separadas por tipo\n");
    printf("e- Informar cuantas bicicletas hay de un tipo y color seleccionados\n");
    printf("f- Mostrar el o los colores mas elegidos\n");
    printf("g- Pedir una bicicleta y mostrar todos los trabajos que se le hicieron\n");
    printf("h- Pedir una bicicleta e informar la suma de los importes de los servicios que se le hicieron a la misma \n");
    printf("i- Pedir un servicio y mostrar las bicicletas a las que se le realizo ese servicio y la fecha \n");
    printf("j- Pedir una fecha y mostrar todos los servicios realizados en la misma \n");
    printf("x. Salir\n");


    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    return opcion;
}
//-----------------------------------------------------------------------------------------------------------------------
void informeBicicletas(eBicicleta bicicletas[], int tamB, eTipo tipos[], int tamTipo, eColor colores[], int tamColores, eTrabajo trabajos[], int tamTr, eServicio servicios[], int tamServ, eCliente clientes[], int tamCliente)
{

    char seguir = 's';
    char confirma = 's';

    do
    {
        switch(menuInformes())
        {
        case 'a':
            listarBicicletasDeColor(bicicletas, tamB, tipos, tamTipo, colores, tamColores, clientes, tamCliente);
            break;
        case 'b':
            listarBicicletasDeTipo(bicicletas, tamB, tipos, tamTipo, colores, tamColores, clientes, tamCliente);
            break;
        case 'c':
            informarMenorRodadoBicicleta(bicicletas, tamB, colores, tamColores, tipos, tamTipo, clientes, tamCliente);
            break;
        case 'd':
            informarBicicletasXTipo(bicicletas, tamB, colores, tamColores, tipos, tamTipo, clientes, tamCliente);
            break;
        case 'e':
            mostrarBicicletasPorColorYTipo(bicicletas, tamB, colores, tamColores, tipos, tamTipo);
            break;
        case 'f':
            informarMayorColor(bicicletas, tamB, colores, tamColores);
            break;
        case 'g':
            informarTrabajosDeBicicletas(trabajos, tamTr, bicicletas, tamB, tipos, tamTipo, servicios, tamServ, colores, tamColores, clientes, tamCliente);
            break;
        case 'h':
            preciosServiciosBicicletas(bicicletas, tamB, tipos, tamTipo, colores, tamColores, trabajos, tamTr, servicios, tamServ, clientes, tamCliente);
            break;
        case'i':
            informarBicicletasDeServicio(bicicletas, tamB, servicios, tamServ, trabajos, tamTr);
            break;
        case 'j':
            listarBicicletasPorFechaTrabajo(bicicletas, tamB, trabajos, tamTr, servicios, tamServ);
            break;

        case 'x':
            printf("Confirma salida? Ingrese s o n: \n");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma== 's')
            {
                seguir = 'n';
            }
            break;

        }
        system("pause");

    }
    while ( seguir == 's');

}


//------------------------------------------------------------------------------------------------------------------------

void listarBicicletasDeTipo(eBicicleta bicicletas[], int tamB, eTipo tipos[], int tamTipo, eColor colores[], int tamColores, eCliente clientes[], int tamCliente)
{
    int idTipo;
    int flag = 0;

    system("cls");

    listarTipos(tipos, tamTipo);
    printf("\n Ingrese el ID del tipo: ");
    scanf("%d", &idTipo);


    printf("**** Listado de bicicletas por tipo ****\n\n");
    printf("ID	     CLIENTE    MARCA	        COLOR     TIPO	     RODADO	\n");
    for (int i=0; i< tamB; i++)
    {
        if (bicicletas[i].isEmpty == 0 && bicicletas[i].idTipo == idTipo)
        {
            mostrarBicicleta(bicicletas[i], tipos, tamTipo, colores, tamColores, clientes, tamCliente);
            flag = 1;
        }
    }

    if ( flag == 0)
    {
        printf("\nNo hay bicicletas de ese tipo. \n");
    }

}
//--------------------------------------------------------------------------------------------------------------


void listarBicicletasDeColor(eBicicleta bicicletas[], int tamB, eTipo tipos[], int tamTipo, eColor colores[], int tamColores, eCliente clientes[], int tamCliente)
{
    int idColor;
    int flag = 0;

    system("cls");

    listarColores(colores, tamColores);
    printf("\n Ingrese el ID del color: ");
    scanf("%d", &idColor);
    while(idColor<5000 || idColor>5004){
       listarColores(colores, tamColores);
        printf("\nERROR, id invalido. Ingrese el ID del color: ");
        scanf("%d", &idColor);
    }


    printf("**** Listado de notebooks por color ****\n\n");
    printf("ID	     CLIENTE    MARCA	        COLOR     TIPO	     RODADO	\n");
    for (int i=0; i< tamB; i++)
    {
        if (bicicletas[i].isEmpty == 0 && bicicletas[i].idColor == idColor)
        {
            mostrarBicicleta(bicicletas[i], tipos, tamTipo, colores, tamColores, clientes, tamCliente);
            flag = 1;
        }
    }

    if ( flag == 0)
    {
        printf("\nNo hay bicicletas de ese color. \n");
    }

}
//------------------------------------------------------------------------------------------------------------------
void preciosServiciosBicicletas(eBicicleta bicicletas[], int tamB, eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eTrabajo trabajos[], int tamTrabajos, eServicio servicios[], int tamServicio, eCliente clientes[], int tamCliente){

	int idBici;
	int indiceBici;
	int idServicio;
	int indiceServicio;
	float totalPrecios = 0;

	system("cls");
	printf("**** Precio de servicios de una Bici ****\n");

	mostrarBicicletas(bicicletas, tamB, tipos, tamTipos, colores, tamColor, clientes, tamCliente);
	printf("Ingrese el ID de la bicicleta: ");
	scanf("%d", &idBici);
    printf("\n\n");

	indiceBici = buscarBicicleta(idBici, bicicletas, tamB);

	if(indiceBici == -1){
		printf("No se encontro la bicicleta con ese ID\n\n");
	}
	else{
		printf("ID	     CLIENTE    MARCA	        COLOR     TIPO	     RODADO	\n");

		mostrarBicicleta(bicicletas[indiceBici], tipos, tamTipos, colores, tamColor, clientes, tamCliente);

		for(int t = 0; t < tamTrabajos; t++){
			if(bicicletas[indiceBici].id == trabajos[t].idBicicleta && trabajos[t].id > 0)
            {
				idServicio = trabajos[t].idServicio;
				indiceServicio = buscarServicio(idServicio, servicios, tamServicio);
				totalPrecios += servicios[indiceServicio].precio;
			}
		}

		if(totalPrecios == 0){
			printf("No se le realizaron trabajos a esta bicicleta\n");
		}
		else{
			printf("\nTotal de precios de los servicios de la bicicleta: %.2f\n\n", totalPrecios);
		}
	}
}

void informarMenorRodadoBicicleta(eBicicleta bicicletas[], int tamB, eColor colores[], int tamColores, eTipo tipos[], int tamTipo, eCliente clientes[], int tamCliente)
{
    float menorRodado = 0;
    int flag=0;
    int hayBicicletas =0;
    char nombreColor[20];
    char nombreTipo[20];

    system("cls");



    for (int i=0; i< tamB; i++)
    {
        if (bicicletas[i].isEmpty == 0)
        {
            if(bicicletas[i].rodado < menorRodado || flag ==0 )
            {
                menorRodado = bicicletas[i].rodado;
                cargarNombreColor(nombreColor, bicicletas[i].idColor, colores, tamColores);
                cargarDescripcionTipo(nombreTipo, bicicletas[i].idTipo, tipos, tamTipo);
                flag = 1;
                hayBicicletas =1;
            }
        }
    }


    printf("El menor rodado es %.2f y corresponde a la/las bicicleta/s: \n\n", menorRodado);
    printf("ID	     CLIENTE    MARCA	        COLOR     TIPO	     RODADO	\n");
    for(int e=0; e<tamB; e++)
    {
        if(bicicletas[e].rodado == menorRodado && flag == 1 && hayBicicletas == 1)
        {
            mostrarBicicleta(bicicletas[e], tipos, tamTipo, colores, tamColores, clientes, tamCliente);
        }
    }


    if ( hayBicicletas == 0)
    {
        printf("\nNo hay bicicletas\n");
    }
}

//-----------------------------------------------------------------------------------------------------


void informarBicicletasXTipo(eBicicleta bicicletas[], int tamB, eColor colores[], int tamColores, eTipo tipos[], int tamTipo, eCliente clientes[], int tamCliente){
    int flag=0;
    system("cls");
    printf("****** Lista de bicicletas de todos los tipos *******\n\n");

    for (int s= 0; s<tamTipo; s++)
    {
        printf("\n\n****************************************************************************************\n\n");
        printf("Tipo: %s\n\n", tipos[s].descripcion);
        printf("ID	     CLIENTE    MARCA	        COLOR     TIPO	     RODADO	\n");

        for(int e=0; e<tamB; e++){
            if(bicicletas[e].isEmpty == 0 && bicicletas[e].idTipo == tipos[s].id)
            {
                mostrarBicicleta(bicicletas[e], tipos, tamTipo, colores, tamColores, clientes, tamCliente);
                flag =1;
            }

    }
        if (flag == 0)
        {
            printf("Sin bicicletas\n");
        }
    }
}

//-------------------------------------------------------------------------------------------------
void mostrarBicicletasPorColorYTipo(eBicicleta bicicletas[], int tamB, eColor colores[], int tamColor, eTipo tipos[], int tamTipo){

    int auxTipo;
    int auxColor;
    int contador=0;
    char nombreTipo[20];
    char nombreColor[20];
    int flag=0;

    listarTipos(tipos, tamTipo);
    printf("Selecione un tipo por su ID: ");
    fflush(stdin);
    scanf("%d", &auxTipo);
    while(auxTipo<1000 || auxTipo>1004){
        listarTipos(tipos, tamTipo);
        printf("ERROR, id invalido. Selecione un tipo por su ID: ");
        fflush(stdin);
        scanf("%d", &auxTipo);
    }

    listarColores(colores, tamColor);
    printf("Selecione un color por su ID: ");
    fflush(stdin);
    scanf("%d", &auxColor);
    while(auxColor<5000 || auxColor>5004){
        listarColores(colores, tamColor);
        printf("ERROR, id invalido. Selecione un color por su ID: ");
        fflush(stdin);
        scanf("%d", &auxColor);
    }

    for(int e=0; e<tamB; e++)
    {
        if(bicicletas[e].isEmpty == 0 && bicicletas[e].idTipo == auxTipo && bicicletas[e].idColor)
        {
            cargarNombreColor(nombreColor, bicicletas[e].idColor, colores, tamColor);
            cargarDescripcionTipo(nombreTipo, bicicletas[e].idTipo, tipos, tamTipo);
            contador++;
            flag=1;
        }

    }



    if(flag == 1 )
    {
        printf("La cantidad de bicicletas del tipo %s y el color %s es %d\n", nombreTipo, nombreColor, contador);
    }else if (flag == 0){
        printf("No hay bicicletas que tengan ese tipo y ese color simultaneamente\n");
    }


}

//----------------------------------------------------------------------------------------------------------------
int obtenerTotalColoresBicicletas(int idColor, eBicicleta bicicletas[], int tamB){

    int totalBicicletas=0;

    for (int i=0; i<tamB; i++)
    {
        if(bicicletas[i].isEmpty == 0 && bicicletas[i].idColor == idColor)
        {
            totalBicicletas = totalBicicletas + 1;
        }
    }

    return totalBicicletas;
}
//------------------------------------------------------------------------------------------------------------------

void informarMayorColor (eBicicleta bicicletas[], int tamB, eColor colores[], int tamColores){
    int totalColores[tamColores];
    int mayorTotal;
    int flag =0;

    system("cls");
    printf("***** Colores mas elegidos *****\n\n");

    for(int i=0; i< tamColores; i++)
    {
        totalColores[i] = obtenerTotalColoresBicicletas(colores[i].id, bicicletas, tamB);
    }

    for (int i=0; i<tamColores; i++)
    {
        if(totalColores[i] > mayorTotal || flag ==0)
        {
            mayorTotal = totalColores[i];
            flag =1;
        }
    }
    printf("Se eligio %d veces y el / los colores mas elegidos son: \n", mayorTotal);

    for (int i=0; i<tamColores; i++)
    {
        if( totalColores[i] == mayorTotal)
        {
            printf("%s\n", colores[i].nombreColor);
        }
    }
}

//-----------------------------------------------------------------------------------------------

void informarTrabajosDeBicicletas (eTrabajo trabajos[], int tamTr, eBicicleta bicicletas[], int tamBici, eTipo tipos[], int tamTipo, eServicio servicios[], int tamServ, eColor colores[], int tamColores, eCliente clientes[], int tamCliente){
 int flag=0;
 int idBici;
 char nombreBici[20];

 system("cls");
 printf("****** Lista de Trabajos de una bicicleta *******\n");

 mostrarBicicletas(bicicletas, tamBici, tipos, tamTipo, colores, tamColores,clientes ,tamCliente);

 printf("Ingrese ID de la bicicleta elegida: ");
 fflush(stdin);
 scanf("%d", &idBici);

    cargarMarcaBicicletaTrabajo(nombreBici, idBici, bicicletas, tamBici);

    printf("\n\nBicicleta: %s\n\n", nombreBici);

    printf(" Id         BICICLETA             SERVICIO       FECHA\n");
    for (int i=0; i< tamTr; i++)
    {
        if (trabajos[i].isEmpty == 0 && trabajos[i].idBicicleta == idBici)
        {
            mostrarTrabajo(trabajos[i], bicicletas, tamBici, servicios, tamServ);
            flag = 1;
        }
    }

    if ( flag == 0)
    {
        printf("\nNo hay trabajos en esa bicicleta \n");
    }
}

//---------------------------------------------------------------------------------------------------

void informarBicicletasDeServicio(eBicicleta bicicletas[], int tamB, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTr)
{
    int idServicio;
    int hayBicicletasEnServ = 0;
    char nombreServicio[20];

    system("cls");
    printf("** Listado de bicicletas por servicio **\n\n");

    mostrarServicios(servicios, tamS);
    printf("\n Ingrese ID del servicio: ");
    scanf("%d", &idServicio);
    while(idServicio<20000 || idServicio>20003){
        mostrarServicios(servicios, tamS);
        printf("\nERROR. Ingrese ID del servicio: ");
        scanf("%d", &idServicio);
    }

    cargarDescripcionServicioTrabajo(nombreServicio, idServicio, servicios, tamS);

    printf("\nBicicletas de servicio: %s \n\n ", nombreServicio);

    printf("ID       BICICLETAS               SERVICIO      FECHA\n");
    for (int i=0; i< tamTr; i++)
    {
        if (trabajos[i].isEmpty == 0 && trabajos[i].idServicio == idServicio)
        {
            mostrarTrabajo(trabajos[i], bicicletas, tamB, servicios, tamS);
            hayBicicletasEnServ = 1;
        }
    }

    if ( hayBicicletasEnServ == 0)
    {
        printf("\nNo hay notebooks en el servicio \n");
    }

}

//-----------------------------------------------------------------------------------

void listarBicicletasPorFechaTrabajo(eBicicleta bicicletas[], int tam, eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamServ)
{
    int dia;
    int mes;
    int anio;
    int flag = 0;

    system("cls");

    printf("\n Ingrese el dia: ");
    scanf("%d", &dia);

    printf("\n Ingrese el mes: ");
    scanf("%d", &mes);

    printf("\n Ingrese el anio: ");
    scanf("%d", &anio);


    printf("\n**** Listado de servicios de bicicletas por fecha ****\n\n");
    printf("   ID       BICICLETA     SERVICIO       FECHA\n");
    for (int i=0; i< tamTrab; i++)
    {
        if (trabajos[i].isEmpty == 0 && trabajos[i].fecha.dia == dia && trabajos[i].fecha.mes == mes && trabajos[i].fecha.anio == anio)
        {
            mostrarTrabajo(trabajos[i], bicicletas, tam, servicios, tamServ);
            flag = 1;
        }
    }

    if ( flag == 0)
    {
        printf("\nNo hay servicios hechos esa fecha \n");
    }

}
//---------------------------------------------------------------------------------------------------------

