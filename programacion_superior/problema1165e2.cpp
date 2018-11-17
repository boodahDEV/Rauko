/*problema 11.65d
AUHTOR: Prof. Alvaro Pino N.
FECHA: 10/XI/2004
Actualizado: 7/XI/2018
1. Crea una estructura en desorden.
2. La ordena en forma ascendente por nombre con qsort.
3. Hace una busqueda binaria por nombre con bsearch.

Escribir un programa en C que lea varios nombres 
y direcciones,reordene los nombres alfabeticamente
y escriba la lista alfabetica. (ver ejemplos 9.20
y 10.26.) Hacer uso de la variable estructura  en 
el programa. Ordena con punteros a estructura.en des
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAX 10

typedef struct
  {
  	char *nombre;
  	char *ncelular;
  }vida;
  

int main()
{
	vida personas[MAX];
	
	int n;
	char nombre[30];
	vida *enc=NULL;
	
int comp_arreglo_d_struct_por_nombre(vida *a,vida *b);
vida *buscar_clave_en_personas(const void *key, vida personas[MAX],int n);

void captura_estructura(vida personas[MAX], int n);
void desplegar(vida personas[MAX], int n);
	
	printf("\nCuantos nombres va a introducir: ");
	scanf("%d",&n);
	fflush(stdin);
	
/* Leer la lista de nombres y direcciones */
	
   captura_estructura(personas,n);
	
/* ordena las estructuras en orden alfabetico.
   El cast de (int (*) (const void *,const void *))
   es necesario para evitar el error de tipo en tiempo 
   de compilacion.
*/
	
qsort((void *)personas, n,sizeof(personas[0]),(int (*)(const void *, const void *))comp_arreglo_d_struct_por_nombre);
	
	printf("\n La estructura reordenada: \n ");
	desplegar(personas,n);

printf("\n\n\n\t Busque un nombre: ");
gets(nombre);
fflush(stdin);
    
enc = (vida *)buscar_clave_en_personas((const void *)nombre, personas,n);

	
	if ( enc != NULL)
	{
	printf("\n\n\t Lo encontre !");
	printf("\n\n\t NOMBRE:  %s ", enc->nombre);
	printf("\n\n\t CELULAR: %s",enc->ncelular);
	}
	else
	    printf("\n\n\t %s no esta en la lista", nombre);
		  	
	return 0;
	
}

void captura_estructura(vida personas[MAX], int n)
{
	int i;
	
	for( i = 0; i < n; i++)
	{
	personas[i].nombre = (char *)malloc(30*sizeof(char));
	personas[i].ncelular = (char *)malloc(9*sizeof(char));
    printf("\nNombre No. %d: ",i+1);
    gets(personas[i].nombre);
    fflush(stdin);
    printf("\nCelular No. %d: ",i+1);
    gets(personas[i].ncelular);
    fflush(stdin);
	}

return;
}

/*compara el campo nombre de la estructura
 persona que  se utiliza con qsort*/

int comp_arreglo_d_struct_por_nombre(vida *a, vida *b)
{
	return( strcmp(a->nombre,b->nombre));
}

/* Se utiliza con bsearch */

/* se invova dentro de la funcion
   buscar_clave_en_personas
*/

int compara_clave_con_personas(const void *a, const void *b)
{
	int ptr;
	/* La clave buscada esta en *a sin tipo
	   se hace un casting de *a hacia (char *)
	   un elemento de la estructura personas esta en
	   *b sin tipo se hace casting de *b hacia
	   (vida *) y luego apunta a nombre; para
	   comparar dos cadenas de caracteres.
	*/
	   
 ptr = strcmp( (char *)a, ( (vida *)b)->nombre);
 
 if (ptr == 0)
	return (0);
 else
	if ( ptr > 0)
	  return(1);
	else 
	    return(-1);
}

/* Utiliza bsearch para encontrar 
   la clave en la estructura personas
*/ 

vida *buscar_clave_en_personas(const void *key,vida personas[MAX], int n)
{
/* itemptr es el puntero a la estructura vida
 que almacena la direccion de memoria del primer 
 elemento de la estructura personas que tiene la
 clave. Si no la encuentra se le asigna NULL.
*/
 
 vida *itemptr = NULL;
	   
int compara_clave_con_personas(const void *a, const void *b);
	   
itemptr = (vida *)bsearch(key,(void *)personas,n,sizeof(personas[0]),
(int (*) (const void *, const void *))compara_clave_con_personas);
	 
return(itemptr);
	   
}

void desplegar(vida personas[MAX], int n)
{
	int i;
	
	for( i = 0; i < n; i++)
	{
printf("\nNombre No. %d:  %s  ",i+1,personas[i].nombre);
printf("Celular No. %d: %s\n",i+1,personas[i].ncelular);
	}
	
return;
}


