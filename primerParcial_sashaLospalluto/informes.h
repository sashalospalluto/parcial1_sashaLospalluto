#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "orquesta.h"
#include "musico.h"

void informe_menu(Musico arrayMusico[], Orquesta arrayOrquesta[], Instrumento arrayInstrumento[],int sizeMusico, int sizeOrquesta, int sizeInstrumento);
void informe_listarMusicoConOrquesta(Musico arrayMusico[], int sizeMusico, Orquesta arrayOrquesta[], int sizeOrquesta, char opcion,Instrumento arrayInstrumento[], int sizeInstrumento, char mostrarInstrumento, int id);
void informe_listarOrquestaConInstrumentos(Musico arrayMusico[], int sizeMusico, Orquesta arrayOrquesta[], int sizeOrquesta,char opcion,Instrumento arrayInstrumento[], int sizeInstrumento);
void informe_contarMusicos(Musico arrayMusico[], int sizeMusico, Orquesta arrayOrquesta[], int sizeOrquesta,char opcion);
void informe_ordenarOrquestaporCantMusicos(Orquesta array[],int size, int arrayContador[],char opcion);                              //cambiar autor
void informe_contarInstrumentos(Instrumento array[], int size);
void informe_contarMusicosQueTocanInstrumentos(Musico arrayMusico[], int sizeMusico,Instrumento arrayInstrumento[], int sizeInstrumento,char opcion);
void informe_contarMusicosPorTipoDeInstrumento(Musico arrayMusico[], int sizeMusico,Instrumento arrayInstrumento[], int sizeInstrumento,char opcion);
void informe_imprimirMusicosPorTipoDeInstrumentoParticular(Musico arrayMusico[],int sizeMusico,Instrumento arrayInstrumento[], int sizeInstrumento, int tipo);
void informe_contarOrquestaSegunSuTipo(Orquesta array[], int size, char opcion);
void informe_imprimirMusicosSegunPromedioEdad(Musico array[], int size);
void informe_imprimirMusicoSegunEdad(Musico arrayMusico[], Orquesta arrayOrquesta[], Instrumento arrayInstrumento[],int sizeMusico, int sizeOrquesta, int sizeInstrumento);
void informe_listarOrquestaPorLugarParticular(Orquesta array[], int size);
void informe_listarOrquestasCompletas(Musico arrayMusico[], Orquesta arrayOrquesta[], Instrumento arrayInstrumento[],int sizeMusico, int sizeOrquesta, int sizeInstrumento);
#endif // INFORMES_H_INCLUDED
