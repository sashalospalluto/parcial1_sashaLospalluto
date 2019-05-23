#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h> //linux
#include "utn.h"
#include "orquesta.h" //cambiar por nombre entidad
#include "instrumento.h"
#include "musico.h"
#include "informes.h"

/*void informe_menu(Musico arrayMusico[], Orquesta arrayOrquesta[], Instrumento arrayInstrumento[],int sizeMusico, int sizeOrquesta, int sizeInstrumento)
{
    int opcion;
    do
    {
        utn_getUnsignedInt("\n\t\tMENU\n"
                           "\n1) Listar todos los musicos que pertenecen a una orquesta determinada"
                           "\n2) Listar todos los musicos que pertenecen a cada orquesta"
                           "\n3) Listar todos los musicos que pertenecen a cada orquesta con sus respectivos instrumentos"
                           "\n4) Listar todos los musicos que pertenecen a una orquesta determinada con sus respectivos instrumentos"
                           "\n5) Listar todas las orquestas con sus respectivos instrumentos"
                           "\n6) informar de menor a mayor segun la cantidad de musicos que tiene una orquesta"
                           "\n7) Ordenar alfabeticamente las orquestas"
                           "\n8) Ordenar alfabeticamente los instrumentos"
                           "\n9) Ordenar alfabeticamente los musicos"
                           "\n10) Indicar la cantidad de instrumentos que tienen los tipos de instrumentos"
                           "\n11) Enumerar la cantidad de musicos que tocan un instrumento en particular"
                           "\n12) Contabilizar los musicos segun el tipo de instrumento que utilicen, mostrar los resultados en orden ascendente"
                           "\n13) Imprimir todos los musicos que utilizan instrumentos a cuerdas"
                           "\n14) Imprimir todos los musicos que utilizan instrumentos de percusion"
                           "\n15) Contabilizar la cantidad de orquestas según su tipo"
                           "\n16) Imprimir todos los musicos los cuales su edad no supere el promedio de TODOS los musicos"
                           "\n17) Salir\n \n\tIngrese una opcion: ",                //cambiar
                           "\nError",1,sizeof(int),1,17,1,&opcion);
        switch(opcion)
        {
        case 1:
            informe_listarMusicoConOrquesta(arrayMusico,sizeMusico,arrayOrquesta,sizeOrquesta,'p',arrayInstrumento,sizeInstrumento,'n');
            break;
        case 2:
            informe_listarMusicoConOrquesta(arrayMusico,sizeMusico,arrayOrquesta,sizeOrquesta,'g',arrayInstrumento,sizeInstrumento,'n');
            break;
        case 3:
            informe_listarMusicoConOrquesta(arrayMusico,sizeMusico,arrayOrquesta,sizeOrquesta,'g',arrayInstrumento,sizeInstrumento,'s');
            break;
        case 4:
            informe_listarMusicoConOrquesta(arrayMusico,sizeMusico,arrayOrquesta,sizeOrquesta,'p',arrayInstrumento,sizeInstrumento,'s');
            break;
        case 5:
            informe_listarOrquestaConInstrumentos(arrayMusico,sizeMusico,arrayOrquesta,sizeOrquesta,'g',arrayInstrumento,sizeInstrumento);
            break;
        case 6:
            informe_contarMusicos(arrayMusico,sizeMusico,arrayOrquesta,sizeOrquesta,'m');
            break;
        case 7:
            orquesta_ordenarPorString(arrayOrquesta,sizeOrquesta);
            orquesta_listar(arrayOrquesta,sizeOrquesta);
            break;
        case 8:
            instrumento_ordenarPorString(arrayInstrumento,sizeInstrumento);
            instrumento_listar(arrayInstrumento,sizeInstrumento);
            break;
        case 9:
            musico_ordenarPorString(arrayMusico,sizeMusico);
            musico_listar(arrayMusico,sizeMusico,2,arrayInstrumento,sizeInstrumento);
            break;
        case 10:
            informe_contarInstrumentos(arrayInstrumento,sizeInstrumento);
            break;
        case 11:
            informe_contarMusicosQueTocanInstrumentos(arrayMusico,sizeMusico,arrayInstrumento,sizeInstrumento,'p');
            break;
        case 12:
            informe_contarMusicosPorTipoDeInstrumento(arrayMusico,sizeMusico,arrayInstrumento,sizeInstrumento,'m');
            break;
        case 13:
            informe_imprimirMusicosPorTipoDeInstrumentoParticular(arrayMusico,sizeMusico,arrayInstrumento,sizeInstrumento,1);
            break;
        case 14:
            informe_imprimirMusicosPorTipoDeInstrumentoParticular(arrayMusico,sizeMusico,arrayInstrumento,sizeInstrumento,4);
            break;
        case 15:
            informe_contarOrquestaSegunSuTipo(arrayOrquesta,sizeOrquesta,'g');
            break;
        case 16:
            informe_imprimirMusicosSegunPromedioEdad(arrayMusico,sizeMusico);
            break;
        case 17: //salir
            break;
        }

    }while(opcion!=17);

}*/

void informe_menu(Musico arrayMusico[], Orquesta arrayOrquesta[], Instrumento arrayInstrumento[],int sizeMusico, int sizeOrquesta, int sizeInstrumento)
{
    int opcion;
    do
    {
        utn_getUnsignedInt("\n\t\tMENU\n"
                            "\n1) Listar las orquestas con mas de 5 musicos, indicando ID de orquesta, nombre, tipo y lugar"
                            "\n2) Listar los musicos de mas de 30 años, indicando ID de musico, nombre,apellido,edad, nombre del instrumento y nombre de la orquesta"
                            "\n3) Listar las orquestas de un lugar en particular ingresado por el usuario.Imprimir ID de orquesta, nombre, tipo y lugar"
                            "\n4) Listar orquestas completas"
                            "\n5) Listar todos los musicos de una orquesta dererminada"
                            //"\n6) imprimir la orquesta con mas musicos"
                            "\n7) Listar los musicos que toquen instrumentos de cuerdas"
                            "\n17) Salir\n \n\tIngrese una opcion: ",                //cambiar
                           "\nError",1,sizeof(int),1,17,1,&opcion);
        switch(opcion)
        {
        case 1:
            informe_contarMusicos(arrayMusico,sizeMusico,arrayOrquesta,sizeOrquesta,'m');
            break;
        case 2:
            informe_imprimirMusicoSegunEdad(arrayMusico,arrayOrquesta, arrayInstrumento,sizeMusico,sizeOrquesta,sizeInstrumento);
            break;
        case 3:
            informe_listarOrquestaPorLugarParticular( arrayOrquesta, sizeOrquesta);
            break;
        case 4:
            informe_listarOrquestasCompletas(arrayMusico,arrayOrquesta, arrayInstrumento,sizeMusico,sizeOrquesta,sizeInstrumento);
            break;
        case 5:
            informe_listarMusicoConOrquesta(arrayMusico,sizeMusico,arrayOrquesta,sizeOrquesta,'p',arrayInstrumento,sizeInstrumento,'s',-1);
            break;
        case 6:
            break;
        case 7:
            informe_imprimirMusicosPorTipoDeInstrumentoParticular(arrayMusico,sizeMusico,arrayInstrumento,sizeInstrumento,1);
            break;
        case 17: //salir
            break;
        }

    }while(opcion!=17);
}

void informe_listarMusicoConOrquesta(Musico arrayMusico[], int sizeMusico, Orquesta arrayOrquesta[], int sizeOrquesta, char opcion,Instrumento arrayInstrumento[], int sizeInstrumento, char mostrarInstrumento, int id)
{
    int i,j,posicion;
    int bandera=-1;
    if (orquesta_todoVacio(arrayOrquesta,sizeOrquesta)==0 && musico_todoVacio(arrayMusico,sizeMusico)==0)
    {
        printf("\nDebe ingresar al menos una orquesta y un musico\n");
    }
    else
    {
        if(arrayMusico!=NULL && sizeMusico>=0 && arrayOrquesta!=NULL && sizeOrquesta>=0)
        {
            if (opcion=='g') //todas las posibilidades
            {
                for (i=0;i<sizeOrquesta;i++)
                {
                    if(arrayOrquesta[i].isEmpty==0)
                    {
                        printf("\n\n\tOrquesta: %s\n",arrayOrquesta[i].nombre);
                        for (j=0;j<sizeMusico;j++)
                        {
                            if(arrayOrquesta[i].idUnico==arrayMusico[j].idOrquesta && arrayMusico[j].isEmpty==0)
                            {
                                printf("\n Musico: %s %s",arrayMusico[j].nombre,arrayMusico[j].apellido);
                                if(mostrarInstrumento=='s')
                                {
                                    instrumento_listarUnoParticular(arrayInstrumento,sizeInstrumento,arrayMusico[j].idInstrumento);
                                }
                                bandera=0;
                            }
                        }
                        if(bandera==-1)
                        {
                            printf("\nNo posee musicos");
                        }
                        bandera=-1;
                    }
                }
            }
            else
            {
                if(id==-1)
                {
                    utn_getUnsignedInt("\nIngrese el codigo de la orquesta: ","\nError",1,sizeof(int),1,sizeOrquesta,1,&id);
                }

                if(orquesta_buscarID(arrayOrquesta,sizeOrquesta,id,&posicion)==-1)                                   //cambiar si no se busca por ID
                {
                    printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
                }
                else
                {
                    printf("\n\n\tOrquesta %s\n",arrayOrquesta[posicion].nombre);
                    for(i=0;i<sizeMusico;i++)
                    {
                        if(arrayOrquesta[posicion].idUnico==arrayMusico[i].idOrquesta)
                        {
                            printf("\n Musico: %s %s",arrayMusico[i].nombre,arrayMusico[i].apellido);
                            if(mostrarInstrumento=='s')
                            {
                                instrumento_listarUnoParticular(arrayInstrumento,sizeInstrumento,arrayMusico[i].idInstrumento);
                            }
                            bandera=0;
                        }
                    }
                    if(bandera==-1)
                    {
                        printf("\nNo posee musicos");
                    }
                }
            }
        }
    }
}
void informe_listarOrquestaConInstrumentos(Musico arrayMusico[], int sizeMusico, Orquesta arrayOrquesta[], int sizeOrquesta,char opcion,Instrumento arrayInstrumento[], int sizeInstrumento)
{
    int i,j,id,posicion;
    int bandera=-1;
    if (orquesta_todoVacio(arrayOrquesta,sizeOrquesta)==0 && musico_todoVacio(arrayMusico,sizeMusico)==0)
    {
        printf("\nDebe ingresar al menos una orquesta y un musico\n");
    }
    else
    {
        if(arrayMusico!=NULL && sizeMusico>=0 && arrayOrquesta!=NULL && sizeOrquesta>=0)
        {
            if (opcion=='g') //todas las posibilidades
            {
                for (i=0;i<sizeOrquesta;i++)
                {
                    if(arrayOrquesta[i].isEmpty==0)
                    {
                        printf("\n\n\tOrquesta: %s\n",arrayOrquesta[i].nombre);
                        for (j=0;j<sizeMusico;j++)
                        {
                            if(arrayOrquesta[i].idUnico==arrayMusico[j].idOrquesta && arrayMusico[j].isEmpty==0)
                            {
                                instrumento_listarUnoParticular(arrayInstrumento,sizeInstrumento,arrayMusico[j].idInstrumento);
                                bandera=0;
                            }
                        }
                        if(bandera==-1)
                        {
                            printf("\nNo posee musicos");
                        }
                        bandera=-1;
                    }
                }
            }
            else
            {
                utn_getUnsignedInt("\nIngrese el codigo de la orquesta: ","\nError",1,sizeof(int),1,sizeOrquesta,1,&id);
                if(orquesta_buscarID(arrayOrquesta,sizeOrquesta,id,&posicion)==-1)                                   //cambiar si no se busca por ID
                {
                    printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
                }
                else
                {
                    printf("\n\n\tOrquesta %s\n",arrayOrquesta[posicion].nombre);
                    for(i=0;i<sizeMusico;i++)
                    {
                        if(arrayOrquesta[posicion].idUnico==arrayMusico[i].idOrquesta)
                        {
                            instrumento_listarUnoParticular(arrayInstrumento,sizeInstrumento,arrayMusico[i].idInstrumento);
                            bandera=0;
                        }
                    }
                    if(bandera==-1)
                    {
                        printf("\nNo posee musicos");
                    }
                }
            }
        }
    }
}

void informe_contarMusicos(Musico arrayMusico[], int sizeMusico, Orquesta arrayOrquesta[], int sizeOrquesta,char opcion)
{
    int i,j;
    int arrayContador[sizeOrquesta];
    for(i=0;i<sizeOrquesta;i++)
    {
        arrayContador[i]=0;
    }
    if (orquesta_todoVacio(arrayOrquesta,sizeOrquesta)==0 && musico_todoVacio(arrayMusico,sizeMusico)==0)
    {
        printf("\nDebe ingresar al menos una orquesta y un musico\n");
    }
    else
    {
        if(arrayMusico!=NULL && sizeMusico>=0 && arrayOrquesta!=NULL && sizeOrquesta>=0)
        {

                for (i=0;i<sizeOrquesta;i++)
                {
                    if(arrayOrquesta[i].isEmpty==0)
                    {
                        //printf("\n\n\tOrquesta: %s\n",arrayOrquesta[i].nombre);
                        for (j=0;j<sizeMusico;j++)
                        {
                            if(arrayOrquesta[i].idUnico==arrayMusico[j].idOrquesta && arrayMusico[j].isEmpty==0)
                            {
                                arrayContador[i]++;
                            }
                        }
                    }

                }
                //informe_ordenarOrquestaporCantMusicos(arrayOrquesta,sizeOrquesta,arrayContador,opcion);
                for(i=0;i<sizeOrquesta;i++)
                {
                    if(arrayOrquesta[i].isEmpty==0 && arrayContador[i]>=5)
                    {
                        printf("\n\nID: %d",arrayOrquesta[i].idUnico);
                        printf("\nOrquesta: %s",arrayOrquesta[i].nombre);
                        printf("\nLugar: %s\n",arrayOrquesta[i].lugar);
                        orquesta_mostrarTipo(arrayOrquesta[i].tipo);
                    }
                }
        }
    }
}

void informe_ordenarOrquestaporCantMusicos(Orquesta array[],int size, int arrayContador[],char opcion)                              //cambiar autor
{
    //printf("\nORDENADO POR APELLIDO Y NOMBRE\n");
    int i;
    Orquesta auxiliar;
    int auxContador;
    int j;

      for(i=0 ; i<size-1 ; i++)
        {
            for(j=i+1; j<size ; j++)
            {
                if((array[i].isEmpty==0) && (array[j].isEmpty==0))
                {
                    if(opcion=='m')
                    {
                        if (arrayContador[j]<arrayContador[i])
                        {
                            auxiliar=array[i];
                            array[i]=array[j];
                            array[j]=auxiliar;

                            auxContador=arrayContador[i];
                            arrayContador[i]=arrayContador[j];
                            arrayContador[j]=auxContador;
                        }
                    }
                    else
                    {
                        if (arrayContador[j]>arrayContador[i])
                        {
                            auxiliar=array[j];
                            array[j]=array[i];
                            array[i]=auxiliar;

                            auxContador=arrayContador[j];
                            arrayContador[j]=arrayContador[i];
                            arrayContador[i]=auxContador;
                        }
                    }

                }
            }
        }
}

void informe_contarInstrumentos(Instrumento array[], int size)
{
    int arrayContador[5];
    int i,j;

    for(i=1;i<5;i++)//inicializa
    {
        arrayContador[i]=0;
    }
    for(j=1;j<=4;j++)//recorre los tipos de instrumentos
    {
        for(i=0;i<size;i++) //recorre todo el array instrumento
        {
            if(array[i].isEmpty==0)
            {
                if(array[i].tipo==j)
                {
                    arrayContador[j]++;
                }
            }
        }
    }
    printf("\nCantidad de instrumentos de Cuerdas: %d",arrayContador[1]);
    printf("\nCantidad de instrumentos de viento-madera: %d",arrayContador[2]);
    printf("\nCantidad de instrumentos de viento-metal: %d",arrayContador[3]);
    printf("\nCantidad de instrumentos de percusion: %d",arrayContador[4]);
}

void informe_contarMusicosQueTocanInstrumentos(Musico arrayMusico[], int sizeMusico,Instrumento arrayInstrumento[], int sizeInstrumento, char opcion)
{
    int i,j;
    int arrayContador[sizeInstrumento];
    int idInstrumento;
    int pos;
    for(i=0;i<sizeInstrumento;i++)
    {
        arrayContador[i]=0;
    }
    if(opcion=='g')
    {
        for(i=0;i<sizeInstrumento;i++)
        {
            for (j=0;j<sizeMusico;j++)
            {
                if (arrayInstrumento[i].isEmpty==0 && arrayMusico[j].isEmpty==0)
                {
                    if(arrayInstrumento[i].idUnico==arrayMusico[j].idInstrumento)
                    {
                        arrayContador[i]++;
                    }
                }
            }
        }
        for (i=0;i<sizeInstrumento;i++)
        {
            if (arrayInstrumento[i].isEmpty==0)
            {
                if(arrayContador[i]==1)
                {
                    printf("\nInstrumento %s: %d musico toca este instrumento",arrayInstrumento[i].nombre,arrayContador[i]);
                }
                else
                {
                     printf("\nInstrumento %s: %d musicos tocan este instrumento",arrayInstrumento[i].nombre,arrayContador[i]);
                }
            }
        }
    }
    else
    {
        if(utn_getUnsignedInt("\nIngrese ID del instrumento: ","\nError",1,sizeof(int),1,10000,3,&idInstrumento)==0 &&
                                instrumento_buscarID(arrayInstrumento,sizeInstrumento,idInstrumento,&pos)==0)
            {
                for(i=0;i<sizeMusico;i++)
                {
                    if(arrayMusico[i].isEmpty==0 && idInstrumento==arrayMusico[i].idInstrumento)
                    {
                        arrayContador[pos]++;
                    }
                }
                if(arrayContador[pos]==1)
                {
                    printf("\nInstrumento %s: %d musico toca el instrumento\n",arrayInstrumento[pos].nombre,arrayContador[pos]);
                }
                else
                {
                    printf("\nInstrumento %s: %d musicos tocan el instrumento\n",arrayInstrumento[pos].nombre,arrayContador[pos]);
                }
            }
    }
}

void informe_contarMusicosPorTipoDeInstrumento(Musico arrayMusico[], int sizeMusico,Instrumento arrayInstrumento[], int sizeInstrumento,char opcion)
{
    int i,j,k;
    int arrayContador[6];
    int arrayTipo[6];
    int auxiliarContador;
    int auxTipo;

    arrayTipo[1]=1;
    arrayTipo[2]=2;
    arrayTipo[3]=3;
    arrayTipo[4]=4;

    for (i=0;i<6;i++)
    {
        arrayContador[i]=0;
    }
    for(i=0;i<sizeInstrumento;i++)
    {
        for (j=0;j<sizeMusico;j++)
        {
            for(k=1;k<=5;k++)
            {
               if (arrayInstrumento[i].isEmpty==0 && arrayMusico[j].isEmpty==0)
                {
                    if(arrayInstrumento[i].idUnico==arrayMusico[j].idInstrumento && arrayInstrumento[i].tipo==k)
                    {
                        arrayContador[k]++;
                    }
                }
            }
        }
    }
    if(opcion=='m')
    {
        for(i=0;i<4;i++)
        {
            for(j=i+1;j<5;j++)
            {
                if(arrayContador[j]<arrayContador[i])
               {
                    auxiliarContador=arrayContador[i];
                    arrayContador[i]=arrayContador[j];
                    arrayContador[j]=auxiliarContador;

                    auxTipo=arrayTipo[i];
                    arrayTipo[i]=arrayTipo[j];
                    arrayTipo[j]=auxTipo;
               }
            }
        }
    }
    else
    {
        for(i=1;i<5;i++)
        {
            for(j=i+1;j<6;j++)
            {
                if(arrayContador[j]>arrayContador[i])
               {
                    auxiliarContador=arrayContador[j];
                    arrayContador[j]=arrayContador[i];
                    arrayContador[i]=auxiliarContador;

                    auxTipo=arrayTipo[j];
                    arrayTipo[j]=arrayTipo[i];
                    arrayTipo[i]=auxTipo;
               }
            }
        }
    }
    for(int i=1;i<=4;i++)
    {
        switch (arrayTipo[i])
        {
            case 1:
                printf("\nCuerdas: %d" ,arrayContador[i]);
                break;
            case 2:
                printf("\nViento-madera: %d", arrayContador[i]);
                break;
            case 3:
                 printf("\nViento-metal: %d", arrayContador[i]);
                 break;
            case 4:
                 printf("\nPercusion: %d" ,arrayContador[i]);
                 break;
        }
    }

}

void informe_imprimirMusicosPorTipoDeInstrumentoParticular(Musico arrayMusico[],int sizeMusico,Instrumento arrayInstrumento[], int sizeInstrumento, int tipo)
{
    int i,j;
    int pos;
    switch (tipo)
    {
    case 1: //cuerdas
        printf("\n\tPersonas que tocan un instrumento de cuerdas\n");
        for(i=0;i<sizeMusico;i++)
        {
            for(j=0;j<sizeInstrumento;j++)
            {
               if(arrayMusico[i].isEmpty==0 && arrayInstrumento[j].isEmpty==0)
               {
                   if(arrayMusico[i].idInstrumento==arrayInstrumento[j].idUnico)
                   {
                       if(arrayInstrumento[j].tipo==1)
                       {
                           printf("\n\nNombre %s %s", arrayMusico[i].nombre, arrayMusico[i].apellido);
                           printf("\nEdad: %d",arrayMusico[i].edad);
                           if(instrumento_buscarID( arrayInstrumento, sizeInstrumento, arrayMusico[i].idInstrumento, &pos)==0)
                           {
                               printf("\n instrumento: %s\n", arrayInstrumento[i].nombre);
                               instrumento_mostrarTipo(arrayInstrumento[i].tipo);
                           }
                       }
                   }
               }
            }
        }
        break;
    case 2: // Viento-madera
        printf("\n\tPersonas que tocan un instrumento de viento-madera\n");
        for(i=0;i<sizeMusico;i++)
        {
            for(j=0;j<sizeInstrumento;j++)
            {
               if(arrayMusico[i].isEmpty==0 && arrayInstrumento[j].isEmpty==0)
               {
                   if(arrayMusico[i].idInstrumento==arrayInstrumento[j].idUnico)
                   {
                       if(arrayInstrumento[j].tipo==2)
                       {
                           printf("\n %s %s", arrayMusico[i].nombre, arrayMusico[i].apellido);
                       }
                   }
               }
            }
        }
        break;
    case 3: //viento-metal
        printf("\n\tPersonas que tocan un instrumento de viento-metal\n");
        for(i=0;i<sizeMusico;i++)
        {
            for(j=0;j<sizeInstrumento;j++)
            {
               if(arrayMusico[i].isEmpty==0 && arrayInstrumento[j].isEmpty==0)
               {
                   if(arrayMusico[i].idInstrumento==arrayInstrumento[j].idUnico)
                   {
                       if(arrayInstrumento[j].tipo==3)
                       {
                           printf("\n %s %s", arrayMusico[i].nombre, arrayMusico[i].apellido);
                       }
                   }
               }
            }
        }
        break;
    case 4: //percusion
        printf("\n\tPersonas que tocan un instrumento de percusion\n");
        for(i=0;i<sizeMusico;i++)
        {
            for(j=0;j<sizeInstrumento;j++)
            {
               if(arrayMusico[i].isEmpty==0 && arrayInstrumento[j].isEmpty==0)
               {
                   if(arrayMusico[i].idInstrumento==arrayInstrumento[j].idUnico)
                   {
                       if(arrayInstrumento[j].tipo==4)
                       {
                           printf("\n %s %s", arrayMusico[i].nombre, arrayMusico[i].apellido);
                       }
                   }
               }
            }
        }
        break;
    }
}

void informe_contarOrquestaSegunSuTipo(Orquesta array[], int size, char opcion)
{
    int i;
    int contadorS=0; //sinfonica
    int contadorF=0; //filarmonica
    int contadorC=0; //camara
    for(i=0;i<size;i++)
    {
        if(array[i].isEmpty==0)
        {
            if(array[i].tipo==1)//sinfonica
            {
               contadorS++;
            }
            else if(array[i].tipo==2)//filarmonica
            {
               contadorF++;
            }
            else //camara
            {
                contadorC++;
            }
        }
    }


    switch (opcion)
    {
    case 'g':
        printf("\nOrquestas sinfonicas: %d",contadorS);
        printf("\nOrquestas filarmonicas: %d",contadorF);
        printf("\nOrquestas Camara: %d",contadorC);
        break;
    case 's':
        printf("\nOrquestas sinfonicas: %d",contadorS);
        break;
    case 'f':
        printf("\nOrquestas filarmonicas: %d",contadorF);
        break;
    case 'c':
        printf("\nOrquestas Camara: %d",contadorC);
        break;
    }
}

void informe_imprimirMusicosSegunPromedioEdad(Musico array[], int size)
{
    int i;
    int contador=0;
    int acumulador=0;
    int promedio;
    for(i=0;i<size;i++)
    {
        if(array[i].isEmpty==0)
        {
            acumulador=acumulador+(array[i].edad);
            contador++;
        }
        promedio=acumulador/contador;
    }
    printf("\n\tMusicos que no superan el promedio");
    for (i=0;i<size;i++)
    {
        if(array[i].isEmpty==0)
        {
            if(array[i].edad<promedio)
            {
                printf("\n %s %s",array[i].nombre,array[i].apellido);
            }
        }
    }
}

void informe_imprimirMusicoSegunEdad(Musico arrayMusico[], Orquesta arrayOrquesta[], Instrumento arrayInstrumento[],int sizeMusico, int sizeOrquesta, int sizeInstrumento)
{
    int i,posI,posO;
    for (i=0;i<sizeMusico;i++)
    {
        if(arrayMusico[i].isEmpty==0)
        {
            if(arrayMusico[i].edad>30)
            {
                printf("\n\nID: %d",arrayMusico[i].idUnico);
                printf("\nNombre y apellido %s %s",arrayMusico[i].nombre,arrayMusico[i].apellido);
                if(instrumento_buscarID(arrayInstrumento, sizeInstrumento, arrayMusico[i].idInstrumento,&posI)==0)
                {
                    printf("\nInstrumento: %s ",arrayInstrumento[posI].nombre);
                }
                if(orquesta_buscarID( arrayOrquesta, sizeOrquesta, arrayMusico[i].idOrquesta,&posO)==0)
                {
                    printf("\nOrquesta: %s",arrayOrquesta[posO].nombre);
                }

            }
        }
    }
}
void informe_listarOrquestaPorLugarParticular(Orquesta array[], int size)
{
    int i;
    int bandera=1;
    char valorBuscado[TEXT_SIZE];
    if(utn_getTexto("\nIngrese el lugar: ", "error, vuelva a intentar", 0, TEXT_SIZE, 3, valorBuscado)==0)
    {
        if(array!=NULL && size>=0)
        {
            for(i=0;i<size;i++)
            {
                if(array[i].isEmpty==1)
                {
                    continue;
                }
                else if(strcasecmp(array[i].lugar,valorBuscado)==0)                                        //cambiar campo nombre
                {
                    printf("\n\nID: %d",array[i].idUnico);
                    printf("\nNombre: %s",array[i].nombre);
                    printf("\nTipo: ");
                    orquesta_mostrarTipo(array[i].tipo);
                    printf("Lugar: %s", array[i].lugar);
                    bandera=0;
                }
            }
        }
    }
    else
    {
        printf("\nEl lugar no existe");
    }

    if(bandera==1)
        {
            printf("\nEl lugar no existe");
        }
}

void informe_listarOrquestasCompletas(Musico arrayMusico[], Orquesta arrayOrquesta[], Instrumento arrayInstrumento[],int sizeMusico, int sizeOrquesta, int sizeInstrumento)
{
    int i,j;
    int contadorC=0;
    int contadorV=0;
    int contadorP=0;
    int pos,id;

    for (i=0; i<sizeOrquesta;i++)
    {
        for (j=0; j<sizeMusico;j++)
        {
            if(arrayMusico[j].isEmpty==0 && arrayOrquesta[i].isEmpty==0)
            {
                if(arrayMusico[j].idOrquesta==arrayOrquesta[i].idUnico)
                {
                    if(instrumento_buscarID(arrayInstrumento, sizeInstrumento, arrayMusico[j].idInstrumento,&pos)==0)
                    {
                        if(arrayInstrumento[pos].tipo==1)//cuerdas
                        {
                            contadorC++;
                        }
                        if(arrayInstrumento[pos].tipo==2 || arrayInstrumento[pos].tipo==3)//viento
                        {
                            contadorV++;
                        }
                        if(arrayInstrumento[pos].tipo==4)//percusion
                        {
                            contadorP++;
                        }
                    }
                }
            }
        }
        id=i;
        if(contadorC>=5 && contadorV>=3 && contadorP>=2)//532
        {
            informe_listarMusicoConOrquesta(arrayMusico,sizeMusico,arrayOrquesta,sizeOrquesta,'p',arrayInstrumento,sizeInstrumento,'s',id);
        }
        contadorC=0;
        contadorV=0;
        contadorP=0;
    }
}
