#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "include/lexan.h"
#include <pthread.h>

#if UNIX
    #include <unistd.h>
    #include <sys/wait.h>
    #define sys "UNIX"
    #define TYPE_SYSTEM_EXEC(sys) ((sys == "UNIX") ? printf("Ejecutando en sistema basado en GNU/LINUX.\n\n\n") : printf("Ejecuntando en sistema basado en Windows/Microsoft.\n\n\n"))
#else
    #define sys "WIN"
    #define TYPE_SYSTEM_EXEC(sys) ((sys == "WIN") ? printf("Ejecutando en sistema basado en Windows/Microsoft.\n\n\n") : printf("Ejecuntando en sistema basado en GNU/LINUX..\n\n\n"))
#endif
void *lexan(void *);

int main(int argc, char const *argv[])
{
    char TEXT[50];
    int STATUS;
    static pid_t RESULT_FORK, PID_SON, PID_DAD;
    TYPE_SYSTEM_EXEC(sys);     // tipo de sistema en ejecucion.
    PID_DAD = getpid();
    //======= TODO APARTIR DE AQUI SE DUPLICARA EN EL PROCESO HIJO, TOMAR EN CUENTA AL TRATAR DE MAXIMIZAR EL CODIGO =======//
    switch (RESULT_FORK = fork())
    {
    case -1:
    {
        exit(EXIT_FAILURE);
    }
    case 0:
    {
        pthread_t LEX_THREAD_MAIN; // hilo de ejecucion del analicis lexico!
        struct ALPHABETIC_STRUCTURE
        {
            char reserved_words[3]; //PALABRAS RESERVADAS
            char cod_asc_words[8];  //CODIGO ASCII DE LAS PALABRAS RESERVADAS
            struct ALPHABETIC_STRUCTURE *liga;
        }AS;
        PID_SON = getpid();
        pthread_create(&LEX_THREAD_MAIN, NULL, lexan, (void *)&AS);
        pthread_join(LEX_THREAD_MAIN, NULL); //ESTE PROCESOS ESPERA A QUE EL HILO CULMINE
        //pthread_detach(LEX_THREAD_MAIN);
        exit(getpid() > PID_DAD);
    }
    default:
    {
        waitpid (PID_SON, &STATUS, 0); //ESPERA A LA FINALIZACION DEL PROCESO HIJO!
        exit(EXIT_SUCCESS);

        /* more code here for process father */
    }
    } //end switch
    //======= NO COLOCAR NADA DESPUES DE AQUI, SI CONSIDERAS QUE EL PROCESO PADRE EJECUTE ALGO INDEPENDIENTE, DEBE SER DENTRO DEL IF, Y LO MISMO EN EL HIJO. ======/
} //end main

void *lexan(void *args)
{ // para pasar multiples parametros a esta funciones de hilo, debe ser por estructuras!
    struct ALPHABETIC_STRUCTURE *AS;
    AS = (struct ALPHABETIC_STRUCTURE *)args;
    char  MCOM[12][2]={0};


    char **ALPHABET_M = (char **) malloc (6*sizeof(char *));
        for(int i = 0; i < 6; i++)
            ALPHABET_M[i]=(char *) malloc ( 20 *sizeof(char));
            //strcpy(ALPHABET_M[1], "mundo");
        strcpy(*(ALPHABET_M),   "../dll/data_pr.dll"); printf("[");printf("\x1B[32m Ok \x1B[0m"); printf("]\n");
        strcpy(*(ALPHABET_M+1), "../dll/data_op.dll");
        strcpy(*(ALPHABET_M+2), "../dll/data_se.dll");


        //strcpy(*(ALPHABET_M+2), "Hola mundo");
        //**(ALPHABET_M ) = "Hola mundo";
        //printf("Contenido de la matriz dinamica: %s\n",*(ALPHABET_M));
      /*for(int i = 0; i < 6; i++)
        {
            for(int j = 0; j < 20; j++)
            {

              if(ALPHABET_M[i][j]!='\0'){
                printf("%c [ %d ][ %d ][ %p ]\n",ALPHABET_M[i][j],i,j,(ALPHABET_M[i]+j));}
            }
            printf("\n\n");
        }*/


       // free(ALPHABET_M); //--
                          //---- Estas dos son para liberar la memoria de manera correcta, deberia ser luego de su procesado!
       // ALPHABET_M = NULL;//-
       
    //se comento LOAD_ALPHABET porque la matriz de alfabetos se encuentra bajo pruebas.
    //LOAD_ALPHABET(ALPHABET_M,MCOM);//pthread_exit(AS->LEX_THREAD_MAIN); //recordar trate de cerrar el hilo de ejecucion
}//fin analicis lexico
