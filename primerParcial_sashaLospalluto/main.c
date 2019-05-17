#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h" //cambiar por nombre entidad
#include"utn.h"
#define QTY_ORQUESTA 50
#define QTY_MUSICO 1000
#define QTY_INSTRUMENTO 20

int main()
{
    int opcion;
    int contadorIdOrquesta=4;                   //cambiar
    int contadorIdMusico=4;
    int contadorIdInstrumento=4;

    Orquesta arrayOrquesta[QTY_ORQUESTA];
    Musico arrayMusico[QTY_MUSICO];
    Instrumento arrayInstrumento[QTY_INSTRUMENTO];

    orquesta_Inicializar(arrayOrquesta,QTY_ORQUESTA);
    musico_Inicializar(arrayMusico,QTY_MUSICO);
    instrumento_Inicializar(arrayInstrumento,QTY_INSTRUMENTO);

    orquesta_hardcodeo(arrayOrquesta);
    musico_hardcodeo(arrayMusico);
    instrumento_hardcodeo(arrayInstrumento);

    do
    {
        utn_getUnsignedInt("\n\t\tMENU\n1) Alta orquesta \n2) Modificar orquesta \n3) Baja orquesta \n4) Listar orquesta\n"
                               "\n1) Alta musico \n2) Modificar musico \n3) Baja musico \n4) Listar musico\n"
                               "5) Salir\n \tIngrese una opcion: ",                //cambiar
                      "\nError",1,sizeof(int),1,6,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                //orquesta_alta(arrayOrquesta,QTY_ORQUESTA,&contadorIdOrquesta);
                musico_alta(arrayMusico,QTY_MUSICO,&contadorIdMusico,arrayOrquesta,QTY_ORQUESTA, arrayInstrumento, QTY_INSTRUMENTO);
                musico_alta(arrayMusico,QTY_MUSICO,&contadorIdMusico,arrayOrquesta,QTY_ORQUESTA, arrayInstrumento, QTY_INSTRUMENTO);
                //instrumento_alta(arrayInstrumento,QTY_INSTRUMENTO,&contadorIdInstrumento);
                break;
            case 2: //Modificar
                //orquesta_modificar(arrayOrquesta,QTY_ORQUESTA);
                musico_modificar(arrayMusico,QTY_MUSICO);
                break;
            case 3: //Baja
                //orquesta_baja(arrayOrquesta,QTY_ORQUESTA);
                musico_baja(arrayMusico,QTY_MUSICO);
                break;
            case 4://Listar
                //orquesta_listar(arrayOrquesta,QTY_ORQUESTA);
                musico_listar(arrayMusico,QTY_MUSICO);
                //instrumento_listar(arrayInstrumento,QTY_INSTRUMENTO);

                break;
            case 5://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=5);
    return 0;
}
