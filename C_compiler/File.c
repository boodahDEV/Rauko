#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <regex.h>

void main(int argc, char const *argv[])
{
        FILE *archivo;
        char t_comando[30]; //---=== DATA DEL ARCHIVO!
        int comando[30];  //---=== ESTA ENTRADA QUEDARA OBSOLETA EN FUTURAS VERSIONES
	archivo = fopen("./dll/data_2.dll","r");
	
	if (archivo == NULL){
            printf("\nError de apertura del archivo. \n\n");
        }else{
            //texto = fgets(mucho, 10, archivo)
            for(int i = 0; i < 30; i++)
            {
                fscanf(archivo,"%c", &t_comando[i]);
            }      
        }
        fclose(archivo);

    sscanf(t_comando, "%d%d%d %d%d%d %d%d %d%d", &comando[0],&comando[1],&comando[2],&comando[3], &comando[4],&comando[5],&comando[6],&comando[7], &comando[8],&comando[9]);    //---=== ESTA FORMA DE DETERMINAR EL COMANDO QUEDARA OBSOLETA AL TENER MAS COMANDOS DEFINIDOS EN EL DLL 
   // printf("El numero: %c%c\n",comando[0],comando[1]);  
   for(int i = 0; i < 4; i++)
   {
       printf("%c ",comando[i]);  
   }
   
    


}
