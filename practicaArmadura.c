#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "practicaArmadura.h" //cambiar por nombre entidad
#define SIZE_LLAMADA 5
#define SIZE_ABONADOS 5
#define SIZE_ESTADOS_LLAMADA 2








int cliente_alta(EmpresasClientes array[], int size, int* contadorID)                          //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(cliente_buscarEmpty(array,size,&posicion)==-1)                          //cambiar fantasma
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idCliente=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getTexto("Nombre","Error",1,CHAR_SIZE,2,array[posicion].nombre);
            utn_getTexto("Direccion","Error",1,CHAR_SIZE,2,array[posicion].direccion);
            utn_getTexto("Localidad","Error",1,CHAR_SIZE,2,array[posicion].localidad);
            utn_getTexto("CUIT","Error",1,CHAR_SIZE,2,array[posicion].CUIT);

            printf("ID: %d \n Nombre: %s ",array[posicion].idCliente, array[posicion].nombre);

            retorno=0;
        }
    }


    return retorno;
}
















int cliente_init(EmpresasClientes array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
            {
                array[size-1].isEmpty=1;
            }
                retorno=0;
    }
    return retorno;

}









int cliente_buscarEmpty(EmpresasClientes array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}


int cliente_listar(EmpresasClientes array[], int size)                      //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int sumatoriaKilos=0;


    if(array!=NULL && size>=0 )
    {
        for(posicion=0;posicion<size;posicion++)
        {
            if(array[posicion].isEmpty==1)
                continue;
            else


                   printf("Alta correcta.\n"
                   "1-ID: %d \n"
                   "2-Nombre de la empresa: %s \n "
                   "3- CUIT: %s \n "
                   "4-Direccion %s",
                    array[posicion].idCliente,
                    array[posicion].nombre,
                    array[posicion].CUIT,
                    array[posicion].direccion);
        }
        retorno=0;
    }
    return retorno;
}


int cliente_baja(EmpresasClientes array[], int sizeArray)                                      //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(cliente_buscarPorID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idCliente=0;                                                                   //cambiar campo id
            strcpy(array[posicion].CUIT,"");
            strcpy(array[posicion].direccion,"");
            strcpy(array[posicion].localidad,"");                                                  //cambiar campo varString
            strcpy(array[posicion].nombre,"");                                               //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}

int cliente_buscarPorID(EmpresasClientes array[], int size, int valorBuscado, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idCliente==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}



int cliente_modificar(EmpresasClientes array[], int sizeArray)                                //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(cliente_buscarPorID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("Alta correcta.\n"
                   "1-ID: %d \n"
                   "2-Nombre de la empresa: %s \n "
                   "3- CUIT: %s \n "
                   "4-Direccion %s",
                    array[posicion].idCliente,
                    array[posicion].nombre,
                    array[posicion].CUIT,
                    array[posicion].direccion);

                utn_getChar("\nModificar: \nA-Direccion \nB-Localidad \nS(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getTexto("Ingrese la nueva direccion","Error",1,CHAR_SIZE,2,array[posicion].direccion);
                        break;
                    case 'B':
                        utn_getName("Ingrese la nueca localidad","Error",1,CHAR_SIZE,2,array[posicion].localidad);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}




int Recoleccion_alta(Recoleccion array[], int size, int* contadorID)                          //cambiar fantasma
{
    int retorno=-1;
    int posicion;

    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(recoleccion_buscarEmpty(array,size,&posicion)==-1)                          //cambiar fantasma
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {

            (*contadorID)++;
            array[posicion].idCliente=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            array[posicion].estado=0;
            utn_getUnsignedInt("Id de cliente: ","Error",1,sizeof(int),1,1000,2,&array[posicion].idCliente);
            //utn_getUnsignedInt("Id de cliente: ","Error",1,sizeof(int),1,1000,&array[posicion].idCliente);
            utn_getUnsignedInt("Cantidad de Kilos: ","Error",1,sizeof(int),1,10000,2,&array[posicion].kilos);
            utn_getUnsignedInt("Tipo de plastico a retirar:\n1-HDPE \n2-LDPE \n3-PP ","Error",1,sizeof(int),1,3,2,array[posicion].tipo);



            retorno=0;
        }
    }


    return retorno;
}



int recoleccion_buscarEmpty(Recoleccion array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}


int recoleccion_init(Recoleccion array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
            {
                array[size-1].isEmpty=1;
            }
                retorno=0;
    }
    return retorno;

}


/*

int recolecion_modificar(Recoleccion array[], int sizeArray)                                //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
      char aux[CHAR_SIZE];
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(recolecion_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                if(array[posicion].estado==0)
                {
                    strcpy(aux,"Pendiente");
                }
                else if(array[posicion].estado==1)
                {
                    strcpy(aux,"Cumplido");
                }



                   printf("1-ID de recoleccion: %d \n"
                   "2-Id de la empresa: %s \n "
                   "3-Estado: ",

                    array[posicion].idRecoleccion,
                    array[posicion].idCliente,
                    aux);
/*
                utn_getChar("\nModificar: \nA-Direccion \nB-Localidad \nS(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getTexto("Ingrese la nueva direccion","Error",1,CHAR_SIZE,2,array[posicion].direccion);
                        break;
                    case 'B':
                        utn_getName("Ingrese la nueca localidad","Error",1,CHAR_SIZE,2,array[posicion].localidad);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");



                        array[posicion].estado=1;
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

*/
int recolecion_buscarID(Recoleccion array[], int size,int valorBuscado, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idRecoleccion==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}



int recoleccion_listar(Recoleccion array[], int size)                      //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    char aux[CHAR_SIZE];
    if(array!=NULL && size>=0)
    {
        for(posicion=0;posicion<size;posicion++)
        {
            if(array[posicion].isEmpty==1)
                continue;
            else
               // printf("\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                //       array[i].idUnico,array[i].varInt,array[i].varFloat,array[i].varString,array[i].varLongString);      //cambiar todos


                if(array[posicion].estado==0)
                {
                    strcpy(aux,"Pendiente");
                }
                else if(array[posicion].estado==1)
                {
                    strcpy(aux,"Cumplido");
                }



                   printf("1-ID de recoleccion: %d \n"
                   "2-Id de la empresa: %s \n "
                   "3-Estado: ",

                    array[posicion].idRecoleccion,
                    array[posicion].idCliente,
                    aux);

        }
        retorno=0;
    }
    return retorno;
}



