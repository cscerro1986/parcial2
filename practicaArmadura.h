#ifndef ARMADURA_H_INCLUDED
#define ARMADURA_H_INCLUDED

#define TEXT_SIZE 20
#define CHAR_SIZE 51
#define SIZE_TELEFONO 21





typedef struct
{
    char nombre[TEXT_SIZE];
    char CUIT [TEXT_SIZE];
    char direccion[TEXT_SIZE];
    char localidad[TEXT_SIZE];
    int idCliente;
    int isEmpty;

}EmpresasClientes;


typedef struct
{
    int kilos;
    int idCliente;
    int idRecoleccion;
    int estado;
    int tipo;
    int isEmpty;




}Recoleccion;





#endif


