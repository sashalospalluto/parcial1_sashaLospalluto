#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h" //cambiar por nombre entidad
#include "informes.h"
#include"utn.h"
#define QTY_ORQUESTA 50
#define QTY_MUSICO 1000
#define QTY_INSTRUMENTO 20

int main()
{
    int opcion;
    int contadorIdOrquesta=4;                   //cambiar
    int contadorIdMusico=6;
    int contadorIdInstrumento=5;

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
        utn_getUnsignedInt("\n\t\tMENU\n\n1) Agregar orquesta \n2) Eliminar orquesta \n3) Imprimir orquestas \n4) Agregar musico\n"
                               "5) Modificar musico \n6) Elimminar musico \n7) Imprimir musicos \n8) Agregar instrumento\n"
                               "9) Imprimir instrumentos \n10) Informes \n11) Salir\n \n\tIngrese una opcion: ",                //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                orquesta_alta(arrayOrquesta,QTY_ORQUESTA,&contadorIdOrquesta);
                break;
            case 2: //Baja
                orquesta_listar(arrayOrquesta,QTY_ORQUESTA);
                musico_bajaConOrquesta(arrayMusico,QTY_MUSICO,arrayOrquesta,QTY_ORQUESTA);
                break;
            case 3: //Mostrar
                orquesta_listar(arrayOrquesta,QTY_ORQUESTA);
                break;
            case 4://Listar
                musico_alta(arrayMusico,QTY_MUSICO,&contadorIdMusico,arrayOrquesta,QTY_ORQUESTA, arrayInstrumento, QTY_INSTRUMENTO);
                break;
            case 5:
                musico_listar(arrayMusico,QTY_MUSICO,3,arrayInstrumento,QTY_INSTRUMENTO);
                musico_modificar(arrayMusico,QTY_MUSICO,arrayOrquesta,QTY_ORQUESTA);
                break;
            case 6:
                musico_listar(arrayMusico,QTY_MUSICO,3,arrayInstrumento,QTY_INSTRUMENTO);
                musico_baja(arrayMusico,QTY_MUSICO);
                break;
            case 7:
                musico_listar(arrayMusico,QTY_MUSICO,5,arrayInstrumento,QTY_INSTRUMENTO);
                break;
            case 8:
                instrumento_alta(arrayInstrumento,QTY_INSTRUMENTO,&contadorIdInstrumento);
                break;
            case 9:
                instrumento_listar(arrayInstrumento,QTY_INSTRUMENTO);
                break;
            case 10:
                informe_menu(arrayMusico,arrayOrquesta,arrayInstrumento,QTY_MUSICO,QTY_ORQUESTA,QTY_INSTRUMENTO);
                break;
            case 11://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=11);
    return 0;
}
