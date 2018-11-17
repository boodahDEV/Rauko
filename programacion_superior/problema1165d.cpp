/*problema 11.65d
AUHTOR: Prof. Alvaro Pino N.
FECHA: 10/XI/2004
Actualizado: 7/XI/2018
1. Crea una estructura en desorden.
2. La ordena en forma ascendente por nombre con qsort.
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
  	char *direccion;
  }vida;
  

int main()
{
	vida personas[MAX];
	
	int i,n;
	int ord_arreglo_d_struct_por_nombre(vida *a, vida *b);
	
	void captura_estructura(vida personas[MAX], int n);
	void desplegar(vida personas[MAX], int n);
	
	printf("\nCuantos nombres va a introducir: ");
	scanf("%d",&n);
	fflush(stdin);
	
	/* Leer la lista de nombres y direcciones */
	
	captura_estructura(personas,n);
	
	/*ordena las estructuras en orden alfabetico.
	El cast de (int (*) (const void *,const void *))
	es necesario para evitar el error de tipo en tiempo 
	de compilacion.
	*/
	
qsort((void *)personas, n,sizeof(personas[MAX]),
	(int (*)(const void *, const void *))ord_arreglo_d_struct_por_nombre);
	
	printf("\n La estructura reordenada: \n ");
	desplegar(personas,n);
	
	return 0;
	
}

void captura_estructura(vida personas[MAX], int n)
{
	int i;
	
	for( i = 0; i < n; i++)
	{
	personas[i].nombre = (char *)malloc(30*sizeof(char));
	personas[i].direccion = (char *)malloc(30*sizeof(char));
    printf("\nNombre No. %d: ",i+1);
    gets(personas[i].nombre);
    fflush(stdin);
    printf("\nDireccion No. %d: ",i+1);
    gets(personas[i].direccion);
    fflush(stdin);
	}

return;
}

int ord_arreglo_d_struct_por_nombre(vida *a, vida *b)
{
	return( strcmp(a->nombre,b->nombre));
}

void desplegar(vida personas[MAX], int n)
{
	int i;
	
	for( i = 0; i < n; i++)
	{
printf("\nNombre No. %d:  %s  ",i+1,personas[i].nombre);
printf("Direccion No. %d: %s\n",i+1,personas[i].direccion);
	}
	
return;
}
