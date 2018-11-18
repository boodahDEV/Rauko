#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
//---=== prototipos===---
void Busca();

//---=== MAIN ===---
void main(){

Busca(); // busca en el archivo!
}
//---=== END MAIN ===---


void Busca(){
    FILE *archivo;
	char *texto;
    char mucho[10];
	archivo = fopen("data.dll","r");
	
	if (archivo == NULL){
            printf("\nError de apertura del archivo. \n\n");
        }else{
            texto = fgets(mucho, 10, archivo);
			printf("%s", mucho);
        }
        fclose(archivo);
} //---=== END BUSCA ===---