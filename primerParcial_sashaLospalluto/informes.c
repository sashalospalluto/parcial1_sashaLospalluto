#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h> //linux
#include "utn.h"
#include "orquesta.h"
#include "instrumento.h"
#include "musico.h"
#include "informes.h"

/** \brief funcion que realiza el listado de los informes
 *
 * \param arrayMusico[] Musico array de musico
 * \param arrayOrquesta[] Orquesta array de orquesta
 * \param arrayInstrumento[] Instrumento array de instrumento
 * \param sizeMusico int tamaño del array de musico
 * \param sizeOrquesta int tamaño del array de orquesta
 * \param sizeInstrumento int tamaño del array de instrumento
 * \return void
 *
 */
void informe_menu(Musico arrayMusico[], Orquesta arrayOrquesta[], Instrumento arrayInstrumento[],int sizeMusico, int sizeOrquesta, int sizeInstrumento)
{
    int opcion;
    do
    {
        utn_limpiarPantalla();
        utn_getUnsignedInt("\n\t\tMENU\n"
                            "\n1) Listar las orquestas con mas de 5 musicos, indicando ID de orquesta, nombre, tipo y lugar"
                            "\n2) Listar los musicos de mas de 30 agnos, indicando ID de musico, nombre,apellido,edad, nombre del instrumento y nombre de la orquesta"
                            "\n3) Listar las orquestas de un lugar en particular ingresado por el usuario.Imprimir ID de orquesta, nombre, tipo y lugar"
                            "\n4) Listar orquestas completas"
                            "\n5) Listar todos los musicos de una orquesta dererminada"
                            "\n6) imprimir la orquesta con mas musicos"
                            "\n7) Listar los musicos que toquen instrumentos de cuerdas,ordenado por apellido"
                            "\n8) Imprimir el promedio de musicos por orquesta"
                            "\n9) Salir\n \n\tIngrese una opcion: ",
                           "\nError",1,sizeof(int),1,9,1,&opcion);
        switch(opcion)
        {
        case 1:
            informe_contarMusicos(arrayMusico,sizeMusico,arrayOrquesta,sizeOrquesta);
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
            informe_orquestaConMasMusicos(arrayMusico,arrayOrquesta, sizeMusico, sizeOrquesta);
            break;
        case 7:
            informe_imprimirMusicosPorTipoDeInstrumentoParticular(arrayMusico,sizeMusico,arrayInstrumento,sizeInstrumento,1);
            break;
        case 8:
            informe_promedioDeMusicosPorOrquesta(arrayMusico,arrayOrquesta, sizeMusico, sizeOrquesta);
        case 9: //salir
            break;
        }
    }while(opcion!=9);
}

/** \brief lista todas las orquestas con sus respectivos musicos o todos los musicos de una orquesta particular
 *
 * \param arrayMusico[] Musico array de musico
 * \param sizeMusico int tamaño del array de musico
 * \param arrayOrquesta[] Orquesta array de orquesta
 * \param sizeOrquesta int tamaño del array de orquesta
 * \param opcion char opcion que determina si se muestran todas las orquestas (g) o una en particular (p)
 * \param arrayInstrumento[] Instrumento array de instrumento
 * \param sizeInstrumento int tamaño del array de instrumento
 * \param mostrarInstrumento char opcion que determina si se muestran los musicos con su respectivo instrumento (s) o si solo se muestra el musico solo (n)
 * \param id int opcion que determina si se pregunta el id (-1) o se pasa por parametro (id correspondiente)
 * \return void
 *
 */
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
            else //una orquesta en particular
            {
                if(id==-1) //si no se paso el id por parametro
                {
                    utn_getUnsignedInt("\nIngrese el codigo de la orquesta: ","\nError",1,sizeof(int),1,sizeOrquesta,1,&id);
                }

                if(orquesta_buscarID(arrayOrquesta,sizeOrquesta,id,&posicion)==-1)
                {
                    printf("\nNo existe este ID");
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
    utn_pausa();
}

/** \brief Lista las orquestas con mas de 5 musicos con sus datos (id de orquesta, nombre, tipo y lugar)
 *
 * \param arrayMusico[] Musico array de musico
 * \param sizeMusico int tamaño del array de musico
 * \param arrayOrquesta[] Orquesta array de orquesta
 * \param sizeOrquesta int tamaño del array de orquesta
 * \return void
 *
 */
void informe_contarMusicos(Musico arrayMusico[], int sizeMusico, Orquesta arrayOrquesta[], int sizeOrquesta)
{
    int i,j;
    int bandera=0;
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
                    for (j=0;j<sizeMusico;j++)
                    {
                        if(arrayOrquesta[i].idUnico==arrayMusico[j].idOrquesta && arrayMusico[j].isEmpty==0)
                        {
                            arrayContador[i]++;
                        }
                    }
                }
            }
            for(i=0;i<sizeOrquesta;i++)
            {
                if(arrayOrquesta[i].isEmpty==0 && arrayContador[i]>=5)
                {
                    printf("\n\nID: %d",arrayOrquesta[i].idUnico);
                    printf("\nOrquesta: %s",arrayOrquesta[i].nombre);
                    printf("\nLugar: %s\n",arrayOrquesta[i].lugar);
                    orquesta_mostrarTipo(arrayOrquesta[i].tipo);
                    bandera=1;
                }
            }
            if(bandera==0)
            {
                printf("\nNinguna orquesta cumple los requisitos\n");
            }
        }
    }
    utn_pausa();
}

/** \brief Lista los musicos que toquen un instrumento en particular,ordenado por apellido
 *
 * \param arrayMusico[] Musico array de musico
 * \param sizeMusico int tamaño del array de musico
 * \param arrayInstrumento[] Instrumento array de instrumento
 * \param sizeInstrumento int tamaño del array de instrumento
 * \param tipo int tipo de instrumento, cuerdas=1, viento-madera=2, viento-metal=3,percusion=4
 * \return void
 *
 */
void informe_imprimirMusicosPorTipoDeInstrumentoParticular(Musico arrayMusico[],int sizeMusico,Instrumento arrayInstrumento[], int sizeInstrumento, int tipo)
{
    int i,j;
    int pos;
    int posAuxiliar;
    Musico auxiliar[sizeMusico];
    musico_Inicializar(auxiliar,sizeMusico);
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
                           if(musico_buscarEmpty(auxiliar,sizeMusico,&posAuxiliar)==0)
                            {
                                strcpy(auxiliar[posAuxiliar].apellido,arrayMusico[i].apellido);
                                auxiliar[posAuxiliar].edad=arrayMusico[i].edad;
                                auxiliar[posAuxiliar].idInstrumento=arrayMusico[i].idInstrumento;
                                auxiliar[posAuxiliar].idOrquesta=arrayMusico[i].idOrquesta;
                                auxiliar[posAuxiliar].idUnico=arrayMusico[i].idUnico;
                                auxiliar[posAuxiliar].isEmpty=arrayMusico[i].isEmpty;
                                strcpy(auxiliar[posAuxiliar].nombre,arrayMusico[i].nombre);
                            }
                       }
                   }
               }
            }
        }
        musico_ordenarPorString(auxiliar,sizeMusico); //ordena por apellido
        for(i=0;i<sizeMusico;i++)
        {
            if(auxiliar[i].isEmpty==0)
            {
               printf("\n\n Nombre %s %s", auxiliar[i].nombre, auxiliar[i].apellido);
               printf("\n Edad: %d",auxiliar[i].edad);
               if(instrumento_buscarID( arrayInstrumento, sizeInstrumento, auxiliar[i].idInstrumento, &pos)==0)
               {
                   printf("\n instrumento: %s\n", arrayInstrumento[pos].nombre);
                   instrumento_mostrarTipo(arrayInstrumento[pos].tipo);
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
    utn_pausa();
}

/** \brief Lista los musicos de mas de 30 años, con sus respectivos datos y orquesta a la que pertenece
 *
 * \param arrayMusico[] Musico array de musico
 * \param arrayOrquesta[] Orquesta array de orquesta
 * \param arrayInstrumento[] Instrumento array de instrumento
 * \param sizeMusico int tamaño del array de musico
 * \param sizeOrquesta inttamaño del array de orquesta
 * \param sizeInstrumento int tamaño del array de instrumento
 * \return void
 *
 */
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
    utn_pausa();
}

/** \brief  Lista las orquestas de un lugar en particular ingresado por el usuario
 *
 * \param array[] Orquesta array de orquesta
 * \param size int tamaño del array
 * \return void
 *
 */
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
                else if(strcasecmp(array[i].lugar,valorBuscado)==0)
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
    utn_pausa();
}

/** \brief Lista las orquestas completas (tiene que tener al menos 5 instrumentos de cuerda, 3 de viento y 2 de percusion)
 *
 * \param arrayMusico[] Musico array de musico
 * \param arrayOrquesta[] Orquesta array de orquesta
 * \param arrayInstrumento[] Instrumento array de instrumento
 * \param sizeMusico int tamaño de array de Musico
 * \param sizeOrquesta int tamaño de array de orquesta
 * \param sizeInstrumento int tamaño de array de instrumento
 * \return void
 *
 */
void informe_listarOrquestasCompletas(Musico arrayMusico[], Orquesta arrayOrquesta[], Instrumento arrayInstrumento[],int sizeMusico, int sizeOrquesta, int sizeInstrumento)
{
    int i,j;
    int bandera=0;
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
            bandera=1;
        }
        contadorC=0;
        contadorV=0;
        contadorP=0;
    }
    if(bandera==0)
    {
        printf("\n Ninguna orquesta cumple los requisitos\n");
    }
    utn_pausa();
}

/** \brief Imprime la orquesta con mas musicos con sus respectivos datos y cantidad de musicos que lo integran
 *
 * \param arrayMusico[] Musico array de musico
 * \param arrayOrquesta[] Orquesta array de orquesta
 * \param sizeMusico int tamaño del array de musico
 * \param sizeOrquesta int tamaño del array de orquesta
 * \return void
 *
 */
void informe_orquestaConMasMusicos(Musico arrayMusico[], Orquesta arrayOrquesta[], int sizeMusico, int sizeOrquesta)
{
    int i,j;
    int cantMusicos[sizeOrquesta];
    int maximo=-1;
    int contador=0;
    int posOrquesta[sizeOrquesta];
    for(i=0;i<sizeOrquesta;i++)
    {
        cantMusicos[i]=0;
        posOrquesta[i]=0;
    }
    for(i=0;i<sizeOrquesta;i++)
    {
        if(arrayOrquesta[i].isEmpty==0)
        {
            for(j=0;j<sizeMusico;j++)
            {
                if(arrayMusico[j].isEmpty==0 && arrayMusico[j].idOrquesta==arrayOrquesta[i].idUnico)
                {
                    contador++;
                }
            }
            if(contador>maximo)
            {
                maximo=contador;
            }
            cantMusicos[i]=contador;
            posOrquesta[i]=i;
            contador=0;
        }
    }
    for(i=0;i<sizeOrquesta;i++)
    {
        if(arrayOrquesta[i].isEmpty==0)
        {
            if(cantMusicos[i]==maximo)
            {
                printf("\n\nORQUESTA: %s",arrayOrquesta[posOrquesta[i]].nombre);
                printf("\nId: %d",arrayOrquesta[posOrquesta[i]].idUnico);
                printf("\nLugar: %s",arrayOrquesta[posOrquesta[i]].lugar);
                printf("\nTipo: ");
                orquesta_mostrarTipo(arrayOrquesta[posOrquesta[i]].tipo);
                printf("Cantidad de musicos: %d",maximo);
            }
        }
    }
    utn_pausa();
}

/** \brief Imprime el promedio de musicos por orquesta
 *
 * \param arrayMusico[] Musico array de musico
 * \param arrayOrquesta[] Orquesta array de orquesta
 * \param sizeMusico int tamaño del array de musico
 * \param sizeOrquesta int tamaño del array de orquesta
 * \return void
 *
 */
void informe_promedioDeMusicosPorOrquesta(Musico arrayMusico[], Orquesta arrayOrquesta[], int sizeMusico, int sizeOrquesta)
{
    int i,j;
    float promedio;
    int contador=0;
    int cantidadOrquestas=0;

    if (orquesta_todoVacio(arrayOrquesta,sizeOrquesta)==0 && musico_todoVacio(arrayMusico,sizeMusico)==0)
    {
        printf("\nDebe ingresar al menos una orquesta y un musico\n");
    }
    else
    {
         for(i=0;i<sizeOrquesta;i++)
        {
            if(arrayOrquesta[i].isEmpty==0)
            {
                for(j=0;j<sizeMusico;j++)
                {
                    if(arrayMusico[j].isEmpty==0 && arrayMusico[j].idOrquesta==arrayOrquesta[i].idUnico)
                    {
                        contador++;
                    }
                }
                cantidadOrquestas++;
            }
        }
        promedio=(float)contador/(float)cantidadOrquestas;
        printf("\n El promedio es: %.2f",promedio);
    }
    utn_pausa();
}

