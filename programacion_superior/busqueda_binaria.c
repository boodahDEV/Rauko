#include <stdio.h>
#include <stdlib.h>

main(int argc, char const *argv[])
{
    int num[5]={1,2,3,4,5};
    int inf, sup,mitad, dato;
    char band = 'F';

    dato = 4;
    //algoritmo de la busqueda binaria
    inf = 0;// se inicia en 0
    sup = 5; // el numero de elementos del arreglo

    while(inf<=sup){
        mitad = (inf+sup)/2;
    if(num[mitad]==dato){
        band='V';
        break;
    }
    if(num[mitad] > dato){
        sup= mitad;
        mitad = (inf+sup)/2;
    }
    if(num[mitad]<dato){
        inf=mitad;
        mitad =(inf+sup)/2; 
    }
    }//end while
if(band=='V')
    printf("\nNumero encontrado en la posicion: %d \n\n",mitad);
else
    printf ("EL NUMERO NO FUE ENCONTRADO!");


    
    return 0;
}
