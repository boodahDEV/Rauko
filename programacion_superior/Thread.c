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
        printf("%c\a",cadena[i]); //-- el \a le da un sonido animado
        usleep(50000);
    }
    printf("\n");
}//end unido

void *saludo(void * args){
char *cadena="\nAdemas, esta anidado atravez de un metodo!";
char * cadena2= (char *)args;
pthread_t hilo3;
    printf("\n");
    for(int i = 0; i < strlen(cadena2); i++)
    {
        fflush(stdout);
        printf("%c\a",cadena2[i]);
        usleep(50000);
        if(cadena2[i]== '\n'){
             pthread_create(&hilo3,NULL,unido,(void *)cadena);
             pthread_join(hilo3, NULL);
        }
    }
    
    printf("\n");
}// fin saludo


void main(int argc, char const *argv[])
{
    char *cadena = "hola mundo, esto es una prueva de la velocidad de ejecucion a base de directivas!\n";
   // pthread_t hilo1;
    pthread_t hilo2;
   // pthread_create(&hilo1,NULL,saludo,NULL); // La Funcion pthread_create tiene 4 argumentos, el primero es la referencia(&) del hilo, el segundo lo pongo nulo
                                             // el tercero es la funcion que ejecutara ese hilo, y finalmente el 4 le paso valor NULL 
    pthread_create(&hilo2,NULL,saludo,(void *)cadena);
   // pthread_join(hilo1, NULL); obligatorio poner el join ya que el hilo main siempre muere antes que se ejecuta
    pthread_join(hilo2, NULL);
}
