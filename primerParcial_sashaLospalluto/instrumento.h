#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    int tipo;
}Instrumento;


#endif // INSTRUMENTO_H_INCLUDED
int instrumento_todoVacio(Instrumento array[], int size);
void instrumento_hardcodeo(Instrumento arrayInstrumento[]);
int instrumento_Inicializar(Instrumento array[], int size);
int instrumento_buscarEmpty(Instrumento array[], int size, int* posicion);
int instrumento_buscarID(Instrumento array[], int size, int valorBuscado, int* posicion);
int instrumento_buscarInt(Instrumento array[], int size, int valorBuscado, int* posicion);
int instrumento_buscarString(Instrumento array[], int size, char* valorBuscado, int* indice);
int instrumento_alta(Instrumento array[], int size, int* contadorID);
int instrumento_baja(Instrumento array[], int sizeArray);
int instrumento_bajaValorRepetidoInt(Instrumento array[], int sizeArray, int valorBuscado);
int instrumento_modificar(Instrumento array[], int sizeArray);
void instrumento_ordenarPorString(Instrumento array[],int size);
int instrumento_listar(Instrumento array[], int size);
int instrumento_ordenarPorStringInsercion(Instrumento array[],int size);
int instrumento_tipoInstrumento (int* instrumento);
void instrumento_mostrarTipo(int tipo);
void instrumento_listarUnoParticular(Instrumento array[], int size,int idBuscado);
