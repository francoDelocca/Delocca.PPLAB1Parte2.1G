#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct {
    int id;
    char nombre[20];
    char sexo;
    int isEmpty;
}eCliente;

#endif // CLIENTES_H_INCLUDED
//------------------------------------------------------------------------------------------------------------------------


void mostrarCliente(eCliente cliente, int tamCliente);
//------------------------------------------------------------------------------------------------------------------------


void mostrarClientes(eCliente clientes[], int tamCliente);
//------------------------------------------------------------------------------------------------------------------------


int buscarCliente(int id, eCliente clientes[], int tamCliente);
//------------------------------------------------------------------------------------------------------------------------



int cargarNombreCliente(char nombre[], int id, eCliente clientes[], int tamCliente);


