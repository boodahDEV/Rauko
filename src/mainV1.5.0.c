#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

#ifdef UNIX
    #define sys "UNIX"
    #define TYPE_SYSTEM_EXEC(sys) ((sys == "UNIX") ? printf("Ejecutando en sistema basado en GNU/LINUX.\n") : printf("Ejecuntando en sistema basado en Windows/Microsoft.\n"))
#else
    #define sys "WIN"
    #define TYPE_SYSTEM_EXEC(sys) ((sys == "UNIX") ? printf("Ejecutando en sistema basado en GNU/LINUX.\n") : printf("Ejecuntando en sistema basado en Windows/Microsoft.\n"))
#endif

void main(int argc, char const *argv[])
{
    char texto_entrada[50];
    static pid_t RESULT_FORK;
    // static pthread_t LEX_THREAD_MAIN; // hilo de ejecucion del analicis lexico!
    TYPE_SYSTEM_EXEC(sys);

    //======= TODO APARTIR DE AQUI SE DUPLICARA EN EL PROCESO HIJO, TOMAR EN CUENTA AL TRATAR DE MAXIMIZAR EL CODIGO =======//
    RESULT_FORK = fork();
    if (RESULT_FORK == -1)
    {
        printf("Error al crear procesos!"); //IDEAR UNA LIBRERIA PARA LA MANIPULACION DE ERRORES!
    }
    else if (RESULT_FORK == 0)
    {
        // pthread_create(&LEX_THREAD_MAIN,NULL,lexan,(void *)cadena);
        printf("\n\tID del HIJO: %d y el papa es: %d\n", getpid(), getppid());
    }
    else
    {
        printf("\n\tID del PADRE: %d y el padre es: %d\n", getpid(), getppid());
    } // end else del padre!
    //======= NO COLOCAR NADA DESPUES DE AQUI, SI CONSIDERAS QUE EL PROCESO PADRE EJECUTE ALGO INDEPENDIENTE, DEBE SER DENTRO DEL IF, Y LO MISMO EN EL HIJO. ======/
} //end main
