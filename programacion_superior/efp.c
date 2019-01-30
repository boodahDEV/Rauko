
//estructfunpunt.cpp

#include<stdio.h>
#include<math.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct 
{
	double x;
	double raiz;
	double (*pf)(double);
}mysqrt;

void *creamemoria(int n);
mysqrt *creanodo();

int main()
{
	mysqrt *p;
	
	p = creanodo();
	p->x = 4.0;
	p->pf = sqrt;
	p->raiz = p->pf(p->x);
	printf("\nLa raiz de %0.2lf es: %0.2lf",p->x,p->raiz);
	p->raiz = sqrt(p->x);
	printf("\nLa raiz de %0.2lf es: %0.2lf\n",p->x,p->raiz);
	
	return 0;
}

void *creamemoria(int n)
{
	void *p = (int *)malloc(n);
	if (p == NULL)
	 {
	 	puts("LO siento no hay memoria disponible");
	 	getchar();
	   exit(1);
	}
	
  return (p);	
}

mysqrt *creanodo()
{
	return( mysqrt *)creamemoria(sizeof(mysqrt));
}