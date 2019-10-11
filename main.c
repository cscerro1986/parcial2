#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "practicaArmadura.h" //cambiar por nombre entidad
#define SIZE_CHAR 20
#define SIZE_PANTALLAS 3
#define SIZE_PUBLICACIONES 3
#define QTY_TIPO 3
#define CANT_EMPLE 5
#define SIZE_LLAMADA 5
#define SIZE_ABONADOS 5
#define SIZE_ESTADOS_LLAMADA 2
#define SIZE_USUARIOS 3
#define SIZE_OPERACIONES 5
#define SIZE_CLIENTES 1000
#define SIZE_ALQUILERES 5
#define SIZE_FECHA 365
#define SIZE_JUEGOS 3
#define SIZE_RECOLECCION 1000

//PROGRAMA DE EMPLEADOS




int main()
{

    int opcion;
    int contadorClientes=0;
    int contadorRecoleccion=0;

    EmpresasClientes eCliente[SIZE_CLIENTES];
    cliente_init(eCliente,SIZE_CLIENTES);

    Recoleccion recoleccion[SIZE_RECOLECCION];
    recoleccion_init(recoleccion,SIZE_RECOLECCION);

    do
    {
        utn_getUnsignedInt("\n\n1) Alta de cliente"
                           "\n2) Modificar datos del cliente"
                           "\n3) Baja de cliente"
                           "\n4) Crear pedido de recoleccion "
                           "\n5) Procesar pedido de recoleccion "
                           "\n6) procesar Reciduos "
                           "\n7) Imprimir clientes "
                           "\n8  Imprimir pedidos pendientes"
                           "\n9) Imprimir pedidos procesados"
                           ,"\nError",1,sizeof(int),1,11,1,&opcion);


        switch(opcion)
        {
            case 1: //Alta USUARIO
                cliente_alta(eCliente,SIZE_CLIENTES,&contadorClientes);
                break;

            case 2: //MODIFICAR USUARIO
                cliente_modificar(eCliente,SIZE_CLIENTES);

                break;

            case 3: //BAJA USUARIO
                cliente_baja(eCliente,SIZE_CLIENTES);
                //usuario_baja(usuarios,SIZE_USUARIOS);

                break;

            case 4://ALTA PUBLICACION
                Recoleccion_alta(recoleccion,SIZE_RECOLECCION,&contadorRecoleccion);




                break;

            case 5://MODIFICAR PUBLICACION
                recoleccion_listar(recoleccion,SIZE_RECOLECCION);


                break;

            case 6://BAJA PUBLICACION
                 cliente_listar(eCliente,SIZE_CLIENTES);
                break;

            case 7:// ALTA OPERACION
                //operacion_alta(operaiones,SIZE_OPERACIONES,&contadorOperaciones,publicacionesML,SIZE_PUBLICACIONES);
                break;

            case 8:// LITAR PUBLICACIONES POR USUARIO
                break;

            case 9:// LISTAR PUBLICACIONES
              //  publicacionML_listar(publicacionesML,SIZE_PUBLICACIONES);
                break;

            case 10://LISTAR USUARIOS
               // usuario_listar(usuarios,SIZE_USUARIOS,operaiones,SIZE_OPERACIONES);
                break;

            case 11:
                break;

            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=11);
    return 0;
}

