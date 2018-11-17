/*problema 11.65

Escribir un programa en C que lea varios nombres 
y direcciones,reordene los nombres alfabeticamente
y escriba la lista alfabetica. (ver ejemplos 9.20
y 10.26.) Hacer uso de la variable estructura  en 
el programa.
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
 
void reordenar(vida personas[MAX], int n); 

int main()
{
	vida personas[MAX];
	
	int i,n;
	void reodenar(vida personas[MAX], int n);
	
	printf("\nCuantos nombres va a introducir: ");
	scanf("%d",&n);
	fflush(stdin);
	
	/* Leer la lista de nombres y direcciones */
	
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
	
	reordenar(personas,n);
	printf("\n La estructura reodenada: \n ");
	for( i = 0; i < n; i++)
	{
printf("\nNombre No. %d:  %s  ",i+1,personas[i].nombre);
printf("Direccion No. %d: %s\n",i+1,personas[i].direccion);
	}
	
}
void reordenar(vida personas[MAX], int n)
{
 vida temp;
 int i, elem;
 
 for(elem = 0; elem < n -1; elem ++)
 {
 	for( i = elem + 1; i < n; i++)
 	  if(strcmpi(personas[elem].nombre,personas[i].nombre ) > 0)
 	    {
 	    	temp = personas[elem];
 	    	personas[elem] = personas[i];
 	    	personas[i] = temp;
		 }
   }
  return;
  		
}
