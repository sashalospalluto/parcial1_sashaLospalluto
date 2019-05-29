#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h> //linux
#include "utn.h"
#include "instrumento.h"

//strcmpi=strcasecmp windows=linux

/** \brief Carga datos hardcodeados de instrumentos
 *
 * \param arrayInstrumento[] Instrumento array de estructura
 * \return void
 *
 */
void instrumento_hardcodeo(Instrumento arrayInstrumento[])
{
    strcpy(arrayInstrumento[0].nombre,"Inst1");
    arrayInstrumento[0].tipo=1;
    arrayInstrumento[0].isEmpty=0;
    arrayInstrumento[0].idUnico=1;

    strcpy(arrayInstrumento[1].nombre,"Inst2");
    arrayInstrumento[1].tipo=2;
    arrayInstrumento[1].isEmpty=0;
    arrayInstrumento[1].idUnico=2;

    strcpy(arrayInstrumento[2].nombre,"Inst3");
    arrayInstrumento[2].tipo=2;
    arrayInstrumento[2].isEmpty=0;
    arrayInstrumento[2].idUnico=3;

    strcpy(arrayInstrumento[3].nombre,"Inst4");
    arrayInstrumento[3].tipo=3;
    arrayInstrumento[3].isEmpty=0;
    arrayInstrumento[3].idUnico=4;

    strcpy(arrayInstrumento[4].nombre,"Inst5");
    arrayInstrumento[4].tipo=4;
    arrayInstrumento[4].isEmpty=0;
    arrayInstrumento[4].idUnico=5;
}

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array instrumento Array of instrumento
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int instrumento_Inicializar(Instrumento array[], int size)
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
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int instrumento_buscarEmpty(Instrumento array[], int size, int* posicion)
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
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarID(Instrumento array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
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
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarInt(Instrumento array[], int size, int valorBuscado, int* posicion)
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
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarString(Instrumento array[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
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
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int instrumento_alta(Instrumento array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(instrumento_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else if(utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre)==0 &&
               (instrumento_tipoInstrumento(&array[posicion].tipo))==0)
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;
            array[posicion].isEmpty=0;
            printf("\n ID GENERADO: %d",array[posicion].idUnico);
        }
    retorno=0;
    }
    utn_pausa();
    return retorno;
}

/** \brief Borra un elemento del array por ID
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int instrumento_baja(Instrumento array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    int opcion;
    if (instrumento_todoVacio(array,sizeArray)==0)
    {
        printf("\nNo ingreso ningun instrumento\n");
    }
    else if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(instrumento_buscarID(array,sizeArray,id,&posicion)==-1)
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
    utn_pausa();
    return retorno;
}

/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int instrumento_bajaValorRepetidoInt(Instrumento array[], int sizeArray, int valorBuscado)
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
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Busca un elemento por ID y modifica sus campos
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int instrumento_modificar(Instrumento array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    int opcion;
    Instrumento auxArray;//auxiliar
    if (instrumento_todoVacio(array,sizeArray)==0)
    {
        printf("\nNo ingreso ningun instrumento\n");
    }
    else if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nIngrese el codigo del instrumento: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(instrumento_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                printf("\n 1-nombre: %s\n 2-tipo: %d\n6-SALIR\n",
                       array[posicion].nombre,array[posicion].tipo);
                utn_getUnsignedInt("\nIngrese opcion: ","error",1,7,1,6,3,&opcion);
                switch(opcion)
                {
                    case 1:
                        if (utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,auxArray.nombre)==0)
                        {
                            strcpy(array[posicion].nombre,auxArray.nombre);
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
                        break;
                }
            }while(opcion!=6);
            retorno=0;
        }
    }
    utn_pausa();
    return retorno;
}

/** \brief Ordena por campo XXXXX los elementos de un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
void instrumento_ordenarPorString(Instrumento array[],int size)
{
    printf("\nORDENADO POR APELLIDO Y NOMBRE\n");
    int i;
    Instrumento auxiliar;
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
                    }
                }
            }
        }
}

/** \brief Lista los elementos de un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int instrumento_listar(Instrumento array[], int size)
{
    int retorno=-1;
    int i;
    if (instrumento_todoVacio(array,size)==0)
    {
        printf("\nNo ingreso ningun instrumento\n");
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
                     printf("\n\n  ID: %d\n  nombre: %s\n ",
                     array[i].idUnico,array[i].nombre);
                     instrumento_mostrarTipo(array[i].tipo);
                }
            }
            retorno=0;
        }
    }
    utn_pausa();
    return retorno;
}

/** \brief Verifica que todo el array este vacio, sin instrumentos cargados
 *
 * \param array[] Instrumento array de instrumento
 * \param size int tamaño del array
 * \return int devuelve -1 si esta vacio,0 si hay al menos un instrumento
 *
 */
int instrumento_todoVacio(Instrumento array[], int size)
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
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int instrumento_ordenarPorStringInsercion(Instrumento array[],int size)
{
    int retorno=-1;
    int i, j;
    char bufferNombre[TEXT_SIZE];
    int bufferId;
    int bufferIsEmpty;
    int bufferTipo;

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferNombre,array[i].nombre);
            bufferId=array[i].idUnico;
            bufferIsEmpty=array[i].isEmpty;
            bufferTipo=array[i].tipo;
            j = i - 1;
            while ((j >= 0) && strcasecmp(bufferNombre,array[j].nombre)<0)
            {
                strcpy(array[j + 1].nombre,array[j].nombre);
                array[j + 1].idUnico=array[j].idUnico;
                array[j + 1].isEmpty=array[j].isEmpty;
                array[j + 1].tipo=array[j].tipo;
                j--;
            }
            strcpy(array[j + 1].nombre,bufferNombre);
            array[j + 1].idUnico=bufferId;
            array[j + 1].isEmpty=bufferIsEmpty;
            array[j + 1].tipo=bufferTipo;
        }
        retorno=0;
    }
    return retorno;
}

/** \brief pregunta y asigna el tipo de instrumento
 *
 * \param int* instrumento puntero que devuelve el tipo de instrumento ya validado
 * \return -1 si no existe el tipo de instrumento,0 si se guardo correctamente
 *
 */
int instrumento_tipoInstrumento (int* instrumento)
{
    int opInstrumento;
    int ret=-1;

    if(utn_getUnsignedInt("\n\tTIPOS DE INSTRUMENTOS\n1-Cuerdas\n2-Viento-madera\n3-Viento-metal\n4-Percusion\n\tElija un tipo de instrumento: ","Error",0,4,0,4,3,&opInstrumento)==0)
    {
        switch(opInstrumento)
        {
            case 1:
                *instrumento=opInstrumento;
                ret=0;
                break;
            case 2:
                *instrumento=opInstrumento;
                ret=0;
                break;
            case 3:
                *instrumento=opInstrumento;
                ret=0;
                break;
            case 4:
                *instrumento=opInstrumento;
                ret=0;
                break;
            default:
                printf("\nNo existe el instrumento\n");
                break;
        }
    }
    return ret;
}

/** \brief muestra el tipo de instrumento de tipo int en forma de cadena de caracteres
 *
 * \param tipo int el tipo de instrumento que desea mostrar
 * \return void
 *
 */
void instrumento_mostrarTipo(int tipo)
{
    switch(tipo)
    {
        case 1:
            printf(" Tipo de instrumento: Cuerdas\n");
            break;
        case 2:
            printf(" Tipo de instrumento: Viento-madera\n");
            break;
        case 3:
            printf(" Tipo de instrumento: Viento-metal\n");
            break;
        case 4:
            printf(" Tipo de instrumento: Percusion\n");
            break;
    }
}

/** \brief lista un nombre de instrumento y tipo de instrumento particular, elegido por el usuario
 *
 * \param array[] Instrumento array de instrumento
 * \param size int tamaño del array
 * \param idBuscado int ID del instrumento pasado como valor
 * \return void
 *
 */
void instrumento_listarUnoParticular(Instrumento array[], int size,int idBuscado)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(array[i].isEmpty==0)
        {
            if(array[i].idUnico==idBuscado)
            {
                printf("\n Nombre Instrumento: %s\n",array[i].nombre);
                instrumento_mostrarTipo(array[i].tipo);
            }
        }
    }
}
