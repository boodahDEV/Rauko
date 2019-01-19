#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#if UNIX
    #include <unistd.h>
    #include <sys/wait.h>
    #define sys "UNIX"
    #define TYPE_SYSTEM_EXEC(sys) ((sys == "UNIX") ? printf("Ejecutando en sistema basado en GNU/LINUX.\n\n\n") : printf("Ejecuntando en sistema basado en Windows/Microsoft.\n\n\n"))
#else
    #define sys "WIN"
    #define TYPE_SYSTEM_EXEC(sys) ((sys == "UNIX") ? printf("Ejecutando en sistema basado en GNU/LINUX.\n\n\n") : printf("Ejecuntando en sistema basado en Windows/Microsoft.\n\n\n"))
#endif
void *lexan(void *);

int main(int argc, char const *argv[])
{
    char texto_entrada[50];
    static pid_t RESULT_FORK;
    pthread_t LEX_THREAD_MAIN; // hilo de ejecucion del analicis lexico!
    TYPE_SYSTEM_EXEC(sys);     // tipo de sistema en ejecucion.
    //======= TODO APARTIR DE AQUI SE DUPLICARA EN EL PROCESO HIJO, TOMAR EN CUENTA AL TRATAR DE MAXIMIZAR EL CODIGO =======//
    switch (RESULT_FORK = fork())
    {
    case -1:
    {
        exit(EXIT_FAILURE);
    }
    case 0:
    {
        printf("Hola hijo! %d\n",getpid());
        pthread_create(&LEX_THREAD_MAIN, NULL, lexan, (void *)sys);
        pthread_join(LEX_THREAD_MAIN, NULL); //ESTE PROCESOS ESPERA A QUE EL HILO CULMINE
        //pthread_detach(LEX_THREAD_MAIN);
        exit(EXIT_SUCCESS);
    }
    default:
    {
        printf("Hola papa! %d\n",getpid());
     //  pthread_join(LEX_THREAD_MAIN, NULL);
     //   exit(EXIT_SUCCESS);
    }
    } //end switch
    //======= NO COLOCAR NADA DESPUES DE AQUI, SI CONSIDERAS QUE EL PROCESO PADRE EJECUTE ALGO INDEPENDIENTE, DEBE SER DENTRO DEL IF, Y LO MISMO EN EL HIJO. ======/

} //end main

void *lexan(void *args)
{ // para pasar multiples parametros a esta funciones de hilo, debe ser por estructuras!
    char *t_sys = (char *)args;
    int i = 0;
    while (i != 15)
    { //CICLO DE PRUEBA
        printf("--#%s#--\n", t_sys);
        usleep(500000);
        i++;
    }
    printf("\nFin del hilo lexan!\n");
}//fin analicis lexico