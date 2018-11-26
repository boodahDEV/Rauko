#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DATO_IN 50

struct com_in_sys {
	char com_name [3];
	char cod_asc[8];
	struct com_in_sys *liga;
};

typedef struct com_in_sys nod;
nod * memoria (nod *); 
nod * creainicio (nod*, FILE *,FILE *);
void imprimir(nod *);
nod * busca(nod *, char *);
void openDocument(char *, FILE *);

void main (){
		nod *p;
		FILE *archivo1,*archivo2,*archivo;
		char texto[50];

		scanf("%[^\n]",texto);
		openDocument(texto,archivo);
	//	p=creainicio(p,archivo1,archivo2);
	//	imprimir(p);
	//	printf("\n\nDame el comando: ");scanf("%[^\n]",texto);
	//	busca(p,texto);
		printf("Listo...\n");
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

nod * busca(nod *p, char *texto){
	nod *q;
	q=p;
	int band = 0;
		/*	while(q!=NULL && q->com_name!=texto){
				q=q->liga;
			}
			if(q==NULL){
				printf("EL elemento no se encuentra en la lista!\n");
			}else{
				printf("Encontrado en la lista!.\n");
			}
			*/
 while(q != NULL && !band){
    if (strcmp(q->com_name,texto)==0) {
        band = 1; // si esta en la lista el texto 
    } else {
        q=q->liga;// si no esta pasa al siguiente nodo
    }
 }//end while
	if(band){
   		 printf("\n\n Numero %s esta en la lista", texto);
	} else {
   		 printf("\n\n El numero %s no esta en la lista", texto);
	}
}//termina la funcion busca


void openDocument(char *texto, FILE *archivo){
	char temp[MAX_DATO_IN];
	char delim[] = " "; // se que esto podria ser un simple char sin arreglo pero el strtok requiere que el delimitador sea un arreglo
    char *texto_divido = NULL;
	//char []
	archivo = fopen(texto,"r");
if (archivo== NULL){
            printf("\nError en el analicis. \n\n");
        }else{
          while (feof(archivo) == 0){
			  fgets(temp,MAX_DATO_IN,archivo);
		  }
		}

    texto_divido = strtok( temp, delim);	// strtok divide una cadena de texto de acuerdo a un delimitador, en este caso le dije el delimitador 32 y lo guarde en separador

    while( texto_divido != NULL ) {
        printf( "Trozo : %s \n", texto_divido);
        texto_divido = strtok( NULL, delim); //la funcion strtok devuelve un puntero al primer token encontrado en la cadena.
										     // Se devuelve un puntero nulo si no quedan tokens para recuperar.
    }
	//printf("[ %s ]",temp);
}