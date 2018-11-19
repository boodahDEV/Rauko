#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <regex.h>

#define MAX_COMANDOS 2
#define TAM_COMANDO 3
#define CANT_COM_CAP 10
//---=== prototipos===---
void open(char *,char *);
void cargaComandos(char *,char [][TAM_COMANDO]);

//---=== MAIN ===---
void main(){
	char t_comando[CANT_COM_CAP]; //---=== DATA DEL ARCHIVO!
    char url[]= "./dll/data_1.dll";
   static char m_comando[MAX_COMANDOS][TAM_COMANDO]={{'\0'}};

 open(url,t_comando);// busca en el archivo!
 cargaComandos(t_comando,m_comando);
 
 /*for(int i = 0; i < 10; i++)
 {
     printf("%c [%d]\n",texto[i],i);
 }
*/

printf("\n\n");
for(int i = 0;i<MAX_COMANDOS; i++)
{    

    for(int j = 0;j<TAM_COMANDO; j++)
    {
        printf("%c",m_comando[i][j]);
    }
    printf("\n");
}


}
//---=== END MAIN ===---


void open(char *url,char *t_comando){
    FILE *archivo;
    int comando[2];
	archivo = fopen(url,"r");
	
	if (archivo == NULL){
            printf("\nError de apertura del archivo. \n\n");
        }else{
            //texto = fgets(mucho, 10, archivo)
            for(int i = 0; i < CANT_COM_CAP; i++)
            {
                fscanf(archivo,"%c", &t_comando[i]);
            }      
        }
        fclose(archivo);

    sscanf(t_comando, "%d %d", &comando[0],&comando[1]);    //---=== ESTA FORMA DE DETERMINAR EL COMANDO QUEDARA OBSOLETA AL TENER MAS COMANDOS DEFINIDOS EN EL DLL 
    printf("El numero: %c%c\n",comando[0],comando[1]);      //
} //---=== END BUSCA ===---


//---=== CARGA LOS COMANDOS A UNA MATRIZ ESTATICA PARA TENERLO EN MEMORIA ===---
void cargaComandos(char *t_comando,char m_comando[][TAM_COMANDO]){
    int p_rescom = 0;
    int p_cancom = 0;

    for(int i = 0; i<CANT_COM_CAP; i++){
        if(t_comando[i] != '\n'&& t_comando[i] ){
            m_comando[p_cancom][p_rescom] = t_comando[i];
            p_rescom++;
        }
        else
        {
            m_comando[p_cancom][p_rescom]= '\0';
            p_rescom =0;
            p_cancom++;
        }
    }
}// END METODO CARGACOMANDOS

