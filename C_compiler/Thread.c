#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

void *saludo(void * args){
char *cadena="hilo1";
    
    for(int i = 0; i < strlen(cadena); i++)
    {
        fflush(stdout);
        printf("%c",cadena[i]);
        sleep(1);
    }
    printf("\n");
}
main(int argc, char const *argv[])
{
    pthread_t hilo1;
    pthread_create(&hilo1,NULL,saludo,NULL); // La Funcion pthread_create tiene 4 argumentos, el primero es la referencia(&) del hilo, el segundo lo pongo nulo
                                                         // el tercero es la funcion que ejecutara ese hilo, y finalmente el 4 le paso valor NULL
    printf("Hola mundo\n");
    pthread_join(hilo1, NULL);
    return 0;
}
