#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#ifdef UNIX
    #include <unistd.h>
#endif

void *unido(void *args){
    char * cadena= (char *)args;
    for(int i = 0; i < strlen(cadena); i++)
    {
        fflush(stdout);
        printf("%c",cadena[i]); //-- el \a le da un sonido animado
        usleep(20000);
    }
    printf("\n");
}//end unido

void *saludo(void * args){
char *cadena="\nAdemas, esta anidado a traves de un metodo!";
char * cadena2= (char *)args;
pthread_t hilo3;
    printf("\n");
    for(int i = 0; i < strlen(cadena2); i++)
    {
        fflush(stdout);
        printf("%c",cadena2[i]);
        usleep(20000);
        if(cadena2[i]== '\n'){
             pthread_create(&hilo3,NULL,unido,(void *)cadena);
             pthread_join(hilo3, NULL);
        }
    }
    
    printf("\n");
}// fin saludo

void *ejecuta(void *x){
    char *a = (char *)x;
    printf("%c.",a[0]);
}



void main(int argc, char const *argv[])
{
    char *cadena = "hola mundo, esto es una prueba de la velocidad de ejecucion a base de directivas!";
   // pthread_t hilo1;
   const int tam =(int) strlen(cadena);
   pthread_t hilos[tam];
    pthread_t hilo2;
   // pthread_create(&hilo1,NULL,saludo,NULL); // La Funcion pthread_create tiene 4 argumentos, el primero es la referencia(&) del hilo, el segundo lo pongo nulo
                                             // el tercero es la funcion que ejecutara ese hilo, y finalmente el 4 le paso valor NULL 
  //  pthread_create(&hilo2,NULL,saludo,(void *)cadena);
   printf("tengo t: %d\n",tam);
    printf("tengo a: %d\n",(int)sizeof(hilos));

    for(int i = 0; i < (int)sizeof(hilos); i++){
      pthread_create(&hilos[i],NULL,ejecuta,&cadena[i]);
       // pthread_join(hilos[i], NULL);
    }
    
   // pthread_join(hilo1, NULL); obligatorio poner el join ya que el hilo main siempre muere antes que se ejecuta
    //pthread_join(hilo2, NULL);
}
