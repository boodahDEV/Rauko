#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

//---=== prototipos===---
void open(char *,char *);


//---=== MAIN ===---
void main(){
	char texto[10]; //---=== DATA DEL ARCHIVO!
    char url[]= "./dll/data_1.dll";
    int num;
 open(url,texto);// busca en el archivo!
 
 for(int i = 0; i < 10; i++)
 {
     printf("%c",texto[i]);
 }

 sscanf(texto, "%d", &num);
 printf("\nnumero: %d\n",num);
 
}
//---=== END MAIN ===---


void open(char *url,char *texto){
    FILE *archivo;
    int num;
	archivo = fopen(url,"r");
	
	if (archivo == NULL){
            printf("\nError de apertura del archivo. \n\n");
        }else{
            //texto = fgets(mucho, 10, archivo);
     
            for(int i = 0; i < 10; i++)
            {

                fscanf(archivo,"%c", &texto[i]);
                
              //  fgetc(archivo);
            }      
        }
        fclose(archivo);

} //---=== END BUSCA ===---