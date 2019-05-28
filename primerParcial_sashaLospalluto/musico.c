#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h> //linux
#include "utn.h"
#include "musico.h"
#include "orquesta.h"

//strcmpi=strcasecmp windows=linux

/** \brief Carga datos hardcodeados de musico
 *
 * \param arrayMusico[] Musico array de musico
 * \return void
 *
 */
void musico_hardcodeo(Musico arrayMusico[])
{
    strcpy(arrayMusico[0].nombre,"Mus1");
    strcpy(arrayMusico[0].apellido,"Amus1");
    arrayMusico[0].edad=30;
    arrayMusico[0].isEmpty=0;
    arrayMusico[0].idUnico=1;
    arrayMusico[0].idOrquesta=1;
    arrayMusico[0].idInstrumento=1;

    strcpy(arrayMusico[1].nombre,"Mus2");
    strcpy(arrayMusico[1].apellido,"Amus2");
    arrayMusico[1].edad=20;
    arrayMusico[1].isEmpty=0;
    arrayMusico[1].idUnico=2;
    arrayMusico[1].idOrquesta=2;
    arrayMusico[1].idInstrumento=5;

    strcpy(arrayMusico[2].nombre,"Mus3");
    strcpy(arrayMusico[2].apellido,"Amus3");
    arrayMusico[2].edad=25;
    arrayMusico[2].isEmpty=0;
    arrayMusico[2].idUnico=3;
    arrayMusico[2].idOrquesta=4;
    arrayMusico[2].idInstrumento=2;

    strcpy(arrayMusico[3].nombre,"Mus4");
    strcpy(arrayMusico[3].apellido,"Amus4");
    arrayMusico[3].edad=27;
    arrayMusico[3].isEmpty=0;
    arrayMusico[3].idUnico=4;
    arrayMusico[3].idOrquesta=4;
    arrayMusico[3].idInstrumento=1;

    strcpy(arrayMusico[4].nombre,"Mus5");
    strcpy(arrayMusico[4].apellido,"Amus5");
    arrayMusico[4].edad=22;
    arrayMusico[4].isEmpty=0;
    arrayMusico[4].idUnico=5;
    arrayMusico[4].idOrquesta=1;
    arrayMusico[4].idInstrumento=3;

    strcpy(arrayMusico[5].nombre,"Mus6");
    strcpy(arrayMusico[5].apellido,"Amus6");
    arrayMusico[5].edad=35;
    arrayMusico[5].isEmpty=0;
    arrayMusico[5].idUnico=6;
    arrayMusico[5].idOrquesta=3;
    arrayMusico[5].idInstrumento=4;
}

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array musico Array of musico
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int musico_Inicializar(Musico array[], int size)
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

/** \brief Busca el primer lugar vacio en un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int musico_buscarEmpty(Musico array[], int size, int* posicion)
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

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            else if(array[i].idUnico==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarInt(Musico array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
        }
    }
    return retorno;
}

/** \brief Busca un string en un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarString(Musico array[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            else if(strcasecmp(array[i].nombre,valorBuscado)==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int musico_alta(Musico array[], int size, int* contadorID, Orquesta arrayOrquesta[], int sizeOrquesta, Instrumento arrayInstrumento[],int sizeInstrumento)                          //cambiar musico
{
    int retorno=-1;
    int posicion;
    int idOrquesta;
    int idInstrumento;
    int pos;

    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(musico_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else if(utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre)==0 &&
               utn_getName("\nApellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido)==0 &&
               utn_getUnsignedInt("\nEdad: ","\nError",1,sizeof(int),12,99,3,&array[posicion].edad)==0)
               {
                    if(utn_getUnsignedInt("\nId de la orquesta: ","\nError",1,sizeof(int),1,10000,3,&idOrquesta)==0 &&
                       orquesta_buscarID(arrayOrquesta,sizeOrquesta,idOrquesta,&pos)==0)
                    {
                        if(utn_getUnsignedInt("\nId del instrumento: ","\nError",1,sizeof(int),1,10000,3,&idInstrumento)==0 &&
                            instrumento_buscarID(arrayInstrumento,sizeInstrumento,idInstrumento,&pos)==0)
                        {
                            array[posicion].idOrquesta=idOrquesta;
                            array[posicion].idInstrumento=idInstrumento;
                            (*contadorID)++;
                            array[posicion].idUnico=*contadorID;
                            array[posicion].isEmpty=0;
                            printf("\n Posicion: %d\n ID: %d\n nombre: %s\n apellido: %s\n Edad: %d\n id orquesta: %d \n id instrumento: %d",
                            posicion, array[posicion].idUnico,array[posicion].nombre,array[posicion].apellido, array[posicion].edad, array[posicion].idOrquesta, array[posicion].idInstrumento);
                        }
                        else
                        {
                            printf("\nNo se encontro el id del instrumento\n");
                        }
                    }
                    else
                    {
                        printf("\nNo se encontro el id de la orquesta\n");
                    }
               }
               else
               {
                   printf("\nError\n");
               }
        retorno=0;
    }
    return retorno;
}

/** \brief Borra un elemento del array por ID
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_baja(Musico array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    int opcion;
    if (musico_todoVacio(array,sizeArray)==0)
    {
        printf("\nNo ingreso ningun musico\n");
    }
    else
    {
        if(array!=NULL && sizeArray>0)
        {
            utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
            if(musico_buscarID(array,sizeArray,id,&posicion)==-1)
            {
                printf("\nNo existe este ID");
            }
            else
            {
                utn_getUnsignedInt("\n\tOPCIONES\n1-Si\n2-No\nSeguro que lo desea eliminar?: ","\nError",1,sizeof(int),1,sizeArray,3,&opcion);
                if(opcion==1)
                {
                    printf("\nBORRADO CON EXITO\n");
                    array[posicion].isEmpty=1;
                    retorno=0;
                }
            }
        }
    }
    return retorno;
}

/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array musico Array de musico
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;

                strcpy(array[i].nombre,"");
                strcpy(array[i].apellido,"");
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Busca un elemento por ID y modifica sus campos
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int musico_modificar(Musico array[], int sizeArray, Orquesta arrayOrquesta[], int sizeOrquesta)
{
    int retorno=-1;
    int posicion;
    int id;
    int opcion;
    int pos;
    int idOrquesta;
    Musico auxArray;//auxiliar
    if (musico_todoVacio(array,sizeArray)==0)
    {
        printf("\nNo ingreso ningun musico\n");
    }
    else
    {
        if(array!=NULL && sizeArray>0)
        {
            utn_getUnsignedInt("\nIngrese el codigo del musico: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
            if(musico_buscarID(array,sizeArray,id,&posicion)==-1)
            {
                printf("\nNo existe este ID");
            }
            else
            {
                do
                {
                    printf("\n 1-Edad: %d\n 2-ID orquesta: %d \n 3-SALIR\n",
                           array[posicion].edad,array[posicion].idOrquesta);
                    utn_getUnsignedInt("\nIngrese opcion: ","error",1,3,1,3,3,&opcion);
                    switch(opcion)
                    {
                        case 1: //modifica edad
                            if (utn_getUnsignedInt("\nEdad: ","\nError",1,sizeof(int),12,99,3,&auxArray.edad)==0)
                            {
                                array[posicion].edad=auxArray.edad;
                            }
                            else
                            {
                                printf("\nError al cargar el dato");
                            }
                            break;
                        case 2: //modifica id
                             if(utn_getUnsignedInt("\nId de la orquesta: ","\nError",1,sizeof(int),1,10000,3,&idOrquesta)==0 &&
                             orquesta_buscarID(arrayOrquesta,sizeOrquesta,idOrquesta,&pos)==0)
                            {
                                array[posicion].idOrquesta=idOrquesta;
                            }
                            else
                            {
                                printf("\nError al cargar el dato");
                            }
                            break;
                        case 3: //salir
                            break;
                        default:
                            printf("\nOpcion no valida");
                    }
                }while(opcion!=3);
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief Ordena por campo XXXXX los elementos de un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/

void musico_ordenarPorString(Musico array[],int size)
{
    int i;
    Musico auxiliar;
    int j;

      for(i=0 ; i<size-1 ; i++)
        {
            for(j=i+1; j<size ; j++)
            {
                if((array[i].isEmpty==0) && (array[j].isEmpty==0))
                {
                    if ((strcasecmp(array[j].apellido,array[i].apellido)<0))
                    {
                        auxiliar=array[i];
                        array[i]=array[j];
                        array[j]=auxiliar;
                    }else if((strcasecmp(array[j].apellido,array[i].apellido)==0) && (strcasecmp(array[j].nombre,array[i].nombre)<0))
                        {
                            auxiliar=array[i];
                            array[i]=array[j];
                            array[j]=auxiliar;
                        }
                }
            }
        }
}

/** \brief Lista los elementos de un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int musico_listar(Musico array[], int size, int opcion, Instrumento arrayInstrumento[], int sizeInstrumento)                      //cambiar musico
{
    int retorno=-1;
    int i;
    if (musico_todoVacio(array,size)==0)
    {
        printf("\nNo ingreso ningun musico\n");
    }
    else
    {
        if(array!=NULL && size>=0)
        {
            musico_ordenarPorStringInsercion(array,size);
            for(i=0;i<size;i++)
            {
                if(array[i].isEmpty==1)
                {
                    continue;
                }
                else if (opcion==5)
                {
                    printf("\n ID: %d\n Nombre: %s\n Apellido: %s ",
                    array[i].idUnico,array[i].nombre,array[i].apellido);
                    instrumento_listarUnoParticular(arrayInstrumento,sizeInstrumento,array[i].idInstrumento);
                }
                else
                {
                    printf("\n ID: %d\n Nombre: %s\n Apellido: %s \n",
                    array[i].idUnico,array[i].nombre,array[i].apellido);
                }
            }
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Verifica que todo el array este vacio, sin musicos cargados
 *
 * \param array[] Musico array de musico
 * \param size int tamaño del array
 * \return int int devuelve -1 si esta vacio,0 si hay al menos un musico
 *
 */
int musico_todoVacio(Musico array[], int size)
{
    int ret=-1;
    int contador=0;
    int i;
    for(i=0;i<size;i++)
    {
        if(array[i].isEmpty==1)
        {
            contador++;
            if(contador==size)
            {
               ret=0;
            }
        }
    }
    return ret;
}

/** \brief Ordena por campo XXXXX los elementos de un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int musico_ordenarPorStringInsercion(Musico array[],int size)
{
    int i;
    int j;
    Musico auxiliar;
    char auxNombre[TEXT_SIZE];

    for (i=1; i<size; i++)
    {
        if(array[i].isEmpty==0)
        {
            auxiliar = array[i];
            strcpy(auxNombre , array[i].nombre);
            j = i - 1;
            while ( (strcmp(array[j].nombre , auxNombre) > 0) && (j >= 0))
            {
                array[j+1] = array[j];
                j--;
            }
            array[j+1] = auxiliar;
        }
    }
    return 0;
}

/** \brief da de baja una orquesta junto con todos sus musicos
 *
 * \param array[] Musico array de musico
 * \param size int tamaño del array de musico
 * \param arrayOrquesta[] Orquesta array de orquesta
 * \param sizeOrquesta int tamaño de la orquesta
 * \return void
 *
 */
void musico_bajaConOrquesta(Musico array[], int size, Orquesta arrayOrquesta[], int sizeOrquesta)
{
    int i;
    int id;
    if (orquesta_baja(arrayOrquesta,sizeOrquesta,&id)==0)
    {
       if(array!= NULL && size>=0)
        {
            for(i=0;i<size;i++)
            {
                if(array[i].isEmpty==1)
                {
                    continue;
                }
                else if(array[i].idOrquesta==id)
                {
                    array[i].isEmpty=1;
                }
            }
        }
    }
}


