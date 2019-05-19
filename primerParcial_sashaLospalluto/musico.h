#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED
#include "orquesta.h"
#include "instrumento.h"
#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE];
    int edad;
    int idOrquesta;
    int idInstrumento;
}Musico;


#endif // MUSICO_H_INCLUDED
int musico_todoVacio(Musico array[], int size);
void musico_hardcodeo(Musico arrayMusico[]);
int musico_Inicializar(Musico array[], int size);                                    //cambiar musico
int musico_buscarEmpty(Musico array[], int size, int* posicion);                    //cambiar musico
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion);                    //cambiar musico
int musico_buscarInt(Musico array[], int size, int valorBuscado, int* posicion);                    //cambiar musico
int musico_buscarString(Musico array[], int size, char* valorBuscado, int* indice);                    //cambiar musico
int musico_alta(Musico array[], int size, int* contadorID, Orquesta arrayOrquesta[], int sizeOrquesta, Instrumento arrayInstrumento[],int sizeInstrumento);
int musico_baja(Musico array[], int sizeArray);                                      //cambiar musico
int musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado);
int musico_modificar(Musico array[], int sizeArray, Orquesta arrayOrquesta[], int sizeOrquesta);
void musico_ordenarPorString(Musico array[],int size);                              //cambiar musico
int musico_listar(Musico array[], int size, int opcion);                      //cambiar musico
int musico_ordenarPorStringInsercion(Musico array[],int size);                              //cambiar musico
void musico_bajaConOrquesta(Musico array[], int size, Orquesta arrayOrquesta[], int sizeOrquesta);
