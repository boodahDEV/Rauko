#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

void *saludo(void * args){
char *cadena="hilo1";
char * cadena2= (char *)args;
 /*   for(int i = 0; i < strlen(cadena); i++)
    {
        fflush(stdout);
        printf("%c",cadena[i]);
        sleep(1);
    }*/
    printf("\n");
    for(int i = 0; i < strlen(cadena2); i++)
    {
        fflush(stdout);
        printf("%c",cadena2[i]);
        sleep(1);
    }
    
    printf("\n");
}
main(int argc, char const *argv[])
{
    char *cadena = "hola mundo";
   // pthread_t hilo1;
    pthread_t hilo2;
   // pthread_create(&hilo1,NULL,saludo,NULL); // La Funcion pthread_create tiene 4 argumentos, el primero es la referencia(&) del hilo, el segundo lo pongo nulo
                                             // el tercero es la funcion que ejecutara ese hilo, y finalmente el 4 le paso valor NULL 
    pthread_create(&hilo2,NULL,saludo,(void *)cadena);
    //printf("Hola mundo\n");
   // pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);
    return 0;
}
