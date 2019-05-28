#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "orquesta.h"
#include "musico.h"

void informe_menu(Musico arrayMusico[], Orquesta arrayOrquesta[], Instrumento arrayInstrumento[],int sizeMusico, int sizeOrquesta, int sizeInstrumento);
void informe_listarMusicoConOrquesta(Musico arrayMusico[], int sizeMusico, Orquesta arrayOrquesta[], int sizeOrquesta, char opcion,Instrumento arrayInstrumento[], int sizeInstrumento, char mostrarInstrumento, int id);
void informe_contarMusicos(Musico arrayMusico[], int sizeMusico, Orquesta arrayOrquesta[], int sizeOrquesta);
void informe_imprimirMusicosPorTipoDeInstrumentoParticular(Musico arrayMusico[],int sizeMusico,Instrumento arrayInstrumento[], int sizeInstrumento, int tipo);
void informe_imprimirMusicoSegunEdad(Musico arrayMusico[], Orquesta arrayOrquesta[], Instrumento arrayInstrumento[],int sizeMusico, int sizeOrquesta, int sizeInstrumento);
void informe_listarOrquestaPorLugarParticular(Orquesta array[], int size);
void informe_listarOrquestasCompletas(Musico arrayMusico[], Orquesta arrayOrquesta[], Instrumento arrayInstrumento[],int sizeMusico, int sizeOrquesta, int sizeInstrumento);
void informe_orquestaConMasMusicos(Musico arrayMusico[], Orquesta arrayOrquesta[], int sizeMusico, int sizeOrquesta);
void informe_promedioDeMusicosPorOrquesta(Musico arrayMusico[], Orquesta arrayOrquesta[], int sizeMusico, int sizeOrquesta);
#endif // INFORMES_H_INCLUDED
