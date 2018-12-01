#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>


#define MAX_DATO_IN 80

struct com_in_sys {
	char com_name [3];
	char cod_asc[8];
	struct com_in_sys *liga;
};

typedef struct com_in_sys nod;
nod * memoria (nod *); 
nod * creainicio (nod*, FILE *,FILE *);
void imprimir(nod *);
int busca(nod *, char *);
void openDocument(char *, FILE *, nod*);

void main (){
		nod *p;
		FILE *archivo1,*archivo2,*archivo;
		char texto_entrada[MAX_DATO_IN];

    system("clear");
	scanf("%[^\n]",texto_entrada);
	p=creainicio(p,archivo1,archivo2);
	openDocument(texto_entrada,archivo,p);
	//imprimir(p);
	//printf("\n\nDame el comando: ");scanf("%[^\n]",entrada_secm);
	//busca(p,entrada_secm);
}//---=== END MAIN()

nod * memoria (nod * x){
	x=(nod*)malloc(sizeof(struct com_in_sys)); // libera espacio en memoria a un nodo
	return (x); 
}//---=== EN LIBERA MEMORIA

void imprimir(nod * p){
	nod *q;
	q=p;
	while (q!=NULL){
		printf("--------------------------------------\n");
		printf("%s --- %s\n",q->com_name, q->cod_asc);
		q=q->liga;
	}
		printf("--------------------------------------\n");
}

nod * creainicio (nod *p, FILE *archivo1,FILE *archivo2){
	int i=0;
	nod *q;
	archivo1 = fopen("./dll/data_1.dll","r");
	archivo2 = fopen("./dll/data_2.dll","r");
	p =memoria (p);

	if (archivo1 == NULL && archivo2 == NULL){
            printf("\nError en el analicis. \n\n");
        }else{
          while (feof(archivo1) == 0 && feof(archivo2)==0){  // el while se ejecuta hasta que encuentre el final del archivo
			  if(i==1){
				//printf("Dentro de q->liga = p\n");
				q=memoria (q);
				fgets(q->com_name,3,archivo1);
				fgets(q->cod_asc,8,archivo2);
				q->liga=p;
				p=q;
			  }else{
				//printf("Dentro de p->liga = null\n");
				fgets(p->com_name,3,archivo1);
			  	fgets(p->cod_asc,8,archivo2);
				  p->liga=NULL;
				  i=1;
			  }
			}
		}
        fclose(archivo1);
		fclose(archivo2);
	return (p);	
}

int busca(nod *p, char *texto){
	nod *q;
	q=p;
	int band = 0;

 while(q != NULL && !band){
    if (strcmp(q->com_name,texto)==0) {
        band = 1; // si esta en la lista el texto 
    	} else {
      	 	 q=q->liga;// si no esta pasa al siguiente nodo
    	}
 }//end while
	return band;
}//termina la funcion busca


void openDocument(char *texto, FILE *archivo,nod *p){
	char temp[MAX_DATO_IN]; //---===  RECUPERA EL TEXTO DEL ARCHIVO DE COMPILACION
	char palabra[1];	//almacena temporalmente el comando definido en las  primeras lineas del comando.
	int bandera;
	archivo = fopen(texto,"r"); //---=== abre el documento de la linea de comando

 if (archivo== NULL){
            printf("\nError en el analicis. \n\n");
        }else{
          while (feof(archivo) == 0){
			  fgets(temp,MAX_DATO_IN,archivo);//---=== TEMP[] TIENE LA DATA DEL ARCHIVO
		  }
		  for(int i = 0; i < 50; i++){
			   if(temp[i]=='l' && temp[i+1]=='m'){
				   //i=i-1;
					//strncpy(palabra,temp,2);	este copiaba la cadena entera osea todo temp, por eso lo comente
					strncat(palabra,temp,2);
					printf("\t\t[%s][%d]",palabra,i);
					bandera = busca(p,palabra);
					if(bandera){
						// si el comando fue exitoso! paso a analizar el resto sde texto
						printf("Exito!");
						//DEBO LLAMAR A OTRO METODO 
					}
					//break;
				}
				
				printf("Que?[%d]\n",i);
				if(temp[i]=='.' && temp[i+1]=='\n' ){
					//if(busca(p,temp[i]))

					printf("Encontre el . /n[%d][%c]\n",i,temp[i]);
					///("Pase el IF:[%d]\n",i);
				}
			}//end for
		}
}