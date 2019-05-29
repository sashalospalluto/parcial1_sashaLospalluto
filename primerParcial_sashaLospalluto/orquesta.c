#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h> //linux
#include "utn.h"
#include "orquesta.h" //cambiar por nombre entidad
#include "musico.h"

//strcmpi=strcasecmp windows=linux

/** \brief Carga datos hardcodeados de orquesta
 *
 * \param arrayOrquesta[] Orquesta array de orquesta
 * \return void
 *
 */
void orquesta_hardcodeo(Orquesta arrayOrquesta[])
{
    strcpy(arrayOrquesta[0].nombre,"Orquesta1");
    strcpy(arrayOrquesta[0].lugar,"Lugar1");
    arrayOrquesta[0].isEmpty=0;
    arrayOrquesta[0].idUnico=1;
    arrayOrquesta[0].tipo=1;

    strcpy(arrayOrquesta[1].nombre,"Orquesta2");
    strcpy(arrayOrquesta[1].lugar,"Lugar1");
    arrayOrquesta[1].isEmpty=0;
    arrayOrquesta[1].idUnico=2;
    arrayOrquesta[1].tipo=2;

    strcpy(arrayOrquesta[2].nombre,"Orquesta3");
    strcpy(arrayOrquesta[2].lugar,"Lugar2");
    arrayOrquesta[2].isEmpty=0;
    arrayOrquesta[2].idUnico=3;
    arrayOrquesta[2].tipo=3;

    strcpy(arrayOrquesta[3].nombre,"Orquesta4");
    strcpy(arrayOrquesta[3].lugar,"Lugar3");
    arrayOrquesta[3].isEmpty=0;
    arrayOrquesta[3].idUnico=4;
    arrayOrquesta[3].tipo=3;
}

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array orquesta Array of orquesta
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int orquesta_Inicializar(Orquesta array[], int size)
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion)
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion)
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarInt(Orquesta array[], int size, int valorBuscado, int* posicion)
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarString(Orquesta array[], int size, char* valorBuscado, int* indice)
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int orquesta_alta(Orquesta array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(orquesta_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            if(utn_getName("\nNombre: ","\nError al ingresar el nombre de la orquesta",1,TEXT_SIZE,2,array[posicion].nombre)==0 &&
               utn_getTexto("\nLugar: ","\nError al ingresar el lugar",1,TEXT_SIZE,2,array[posicion].lugar)==0)
               {
                    if((orquesta_tipoOrquesta(&array[posicion].tipo))==0)
                    {
                        (*contadorID)++;
                        array[posicion].idUnico=*contadorID;
                        array[posicion].isEmpty=0;
                        printf("\n ID GENERADO: %d",array[posicion].idUnico);
                        retorno=0;
                    }
               }
               else
               {
                   printf("\nNo ingreso un nombre\n");
               }
        }

    }
    utn_pausa();
    return retorno;
}

/** \brief Borra un elemento del array por ID
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_baja(Orquesta array[], int sizeArray, int* idBuscado)
{
    int retorno=-1;
    int posicion;
    int id;
    int opcion;
    if (orquesta_todoVacio(array,sizeArray)==0)
    {
        printf("\nNo ingreso ningun orquesta\n");
    }
    else
    {
        if(array!=NULL && sizeArray>0)
        {
            utn_getUnsignedInt("\n\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
            if(orquesta_buscarID(array,sizeArray,id,&posicion)==-1)
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
                    *(idBuscado)=id;
                    retorno=0;
                }
            }
        }
    }
    utn_pausa();
    return retorno;
}

/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_bajaValorRepetidoInt(Orquesta array[], int sizeArray, int valorBuscado)
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
                strcpy(array[i].lugar,"");
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Busca un elemento por ID y modifica sus campos
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int orquesta_modificar(Orquesta array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    int opcion;
    Orquesta auxArray;//auxiliares
    if (orquesta_todoVacio(array,sizeArray)==0)
    {
        printf("\nNo ingreso ningun orquesta\n");
    }
    else
    {
        if(array!=NULL && sizeArray>0)
        {
            utn_getUnsignedInt("\nIngrese el codigo del orquesta: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
            if(orquesta_buscarID(array,sizeArray,id,&posicion)==-1)
            {
                printf("\nNo existe este ID");
            }
            else
            {
                do
                {
                    printf("\n 1-nombre: %s\n 2-lugar: %s \n6-SALIR\n",
                           array[posicion].nombre,array[posicion].lugar);
                    utn_getUnsignedInt("\nIngrese opcion: ","error",1,7,1,6,3,&opcion);
                    switch(opcion)
                    {
                        case 1: //modifica nombre
                            if (utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,auxArray.nombre)==0)
                            {
                                strcpy(array[posicion].nombre,auxArray.nombre);
                            }
                            else
                            {
                                printf("\nError al cargar el dato");
                            }
                            break;
                        case 2: //modifica lugar
                            if(utn_getTexto("\nApellido: ","\nError",1,TEXT_SIZE,1,auxArray.lugar)==0)
                            {
                                strcpy(array[posicion].lugar,auxArray.lugar);
                            }
                            else
                            {
                                printf("\nError al cargar el dato");
                            }
                            break;

                        case 6:
                            break;
                        default:
                            printf("\nOpcion no valida");
                    }
                }while(opcion!=6);
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief Ordena por campo XXXXX los elementos de un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/

void orquesta_ordenarPorString(Orquesta array[],int size)
{
    int i;
    Orquesta auxiliar;
    int j;

    for(i=0 ; i<size-1 ; i++)
    {
        for(j=i+1; j<size ; j++)
        {
            if((array[i].isEmpty==0) && (array[j].isEmpty==0))
            {
                if ((strcasecmp(array[j].nombre,array[i].nombre)<0))
                {
                    auxiliar=array[i];
                    array[i]=array[j];
                    array[j]=auxiliar;
                }else if((strcasecmp(array[j].lugar,array[i].lugar)==0) && (strcasecmp(array[j].nombre,array[i].nombre)<0))
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int orquesta_listar(Orquesta array[], int size)
{
    int retorno=-1;
    int i;
    if (orquesta_todoVacio(array,size)==0)
    {
        printf("\nNo ingreso ningun orquesta\n");
    }
    else
    {
        if(array!=NULL && size>=0)
        {
            for(i=0;i<size;i++)
            {
                if(array[i].isEmpty==1)
                {
                    continue;
                }
                else
                {
                    printf("\n\n ID: %d\n nombre: %s\n lugar: %s \n tipo: ",
                           array[i].idUnico,array[i].nombre,array[i].lugar);
                    orquesta_mostrarTipo(array[i].tipo);
                }

            }
            retorno=0;
        }
    }
    utn_pausa();
    return retorno;
}

/** \brief Verifica que todo el array este vacio, sin orquestas cargadas
 *
 * \param array[] Orquesta array de orquesta
 * \param size int tamaño del array
 * \return int devuelve -1 si esta vacio el array, devuelve 0 si encontro al menos un array
 *
 */
int orquesta_todoVacio(Orquesta array[], int size)
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int orquesta_ordenarPorStringInsercion(Orquesta array[],int size)
{
    int retorno=-1;
    int i, j;
    char bufferNombre[TEXT_SIZE];
    char bufferLugar[TEXT_SIZE];
    int bufferId;
    int bufferIsEmpty;

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferNombre,array[i].nombre);
            strcpy(bufferLugar,array[i].lugar);
            bufferId=array[i].idUnico;
            bufferIsEmpty=array[i].isEmpty;

            j = i - 1;
            while ((j >= 0) && strcasecmp(bufferNombre,array[j].nombre)<0)
            {
                strcpy(array[j + 1].nombre,array[j].nombre);
                array[j + 1].idUnico=array[j].idUnico;
                array[j + 1].isEmpty=array[j].isEmpty;
                strcpy(array[j + 1].lugar,array[j].lugar);
                j--;
            }
            strcpy(array[j + 1].nombre,bufferNombre);
            strcpy(array[j + 1].lugar,bufferLugar);
            array[j + 1].idUnico=bufferId;
            array[j + 1].isEmpty=bufferIsEmpty;
        }
        retorno=0;
    }
    return retorno;
}

/** \brief pregunta y asigna el tipo de orquesta
 *
 * \param int* orquesta puntero que devuelve el tipo de la orquesta ya validada
 * \return devuelve -1 si no existe el tipo de orquesta, 0 si se cargo correctamente el tipo
 *
 */
int orquesta_tipoOrquesta (int* orquesta)
{
    int opOrquesta;
    int ret=-1;

    if(utn_getUnsignedInt("\n\tTIPOS DE ORQUESTAS\n1-Sinfonica\n2-Filarmonica\n3-Camara\n\tElija un tipo de orquesta: ","\ntipo de orquesta no valido\n",0,3,0,3,2,&opOrquesta)==0)
    {
        switch(opOrquesta)
        {
            case 1: //sinfonica
                *orquesta=opOrquesta;
                ret=0;
                break;
            case 2: //filarmonica
                *orquesta=opOrquesta;
                ret=0;
                break;
            case 3: //camara
                *orquesta=opOrquesta;
                ret=0;
                break;
            default:
                printf("\nNo existe la orquesta\n");
                break;
        }
    }
    return ret;
}

/** \brief muestra el tipo de orquesta en forma de cadena de caracteres
 *
 * \param tipo int tipo de orquesta
 * \return void
 *
 */
void orquesta_mostrarTipo(int tipo)
{
    switch(tipo)
    {
        case 1:
            printf("Sinfonica\n");
            break;
        case 2:
            printf("Filarmonica\n");
            break;
        case 3:
            printf("Camara\n");
            break;
    }
}
