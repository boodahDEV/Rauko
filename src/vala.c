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
        #define THIS_OK() (printf("\x1B[32m O K "))
        #define THIS_ERROR() (printf("\x1B[31mERROR"))
        #define THIS_NRM(a) ((a == 0)? printf("\x1B[0m ["): printf("\x1B[0m] "))
#else
    #define sys "WIN"
#endif
void *lexan(void *);

        struct TOKEN_LEX
        {
            char comp_lex[2]; //PALABRAS RESERVADAS
            char cod_asc_words[8];  //CODIGO ASCII DE LAS PALABRAS RESERVADAS
        }TOK;

        /*MATRIZ DE COMANDOS O ALFABETOS GLOBAL*/
        char  **MCOM;
        /*MATRIZ DE COMANDOS O ALFABETOS GLOBAL*/
int main(int argc, char const *argv[])
{
    int STATUS;
    static pid_t RESULT_FORK, PID_SON, PID_DAD;
    PID_DAD = getpid();


    //======= TODO APARTIR DE AQUI SE DUPLICARA EN EL PROCESO HIJO, TOMAR EN CUENTA AL TRATAR DE MAXIMIZAR EL CODIGO =======//
    switch (RESULT_FORK = fork())
    {
    case -1: /*PREMATURO*/
    {
        exit(EXIT_FAILURE);
    }
    case 0: /*HIJO*/
    {
       // pthread_t LEX_THREAD_LOAD; // HILO QUE EJECUTA LA CARGA DE LOS ALFABETOS!.
        pthread_t LEX_THREAD_ANALICE; // HILO QUE EJECUTA EL ANALICIS LEXICO.
        PID_SON = getpid();

        pthread_create(&LEX_THREAD_ANALICE, NULL, lexan, (void *)&TOK);
        pthread_join(LEX_THREAD_ANALICE, NULL); //ESTE PROCESOS ESPERA A QUE EL HILO CULMINE
        //pthread_detach(LEX_THREAD_MAIN);
        exit(getpid() > PID_DAD);
    }
    default: /*PADRE*/
    {
        /* more code here for process father */


        waitpid (PID_SON, &STATUS, 0); //ESPERA A LA FINALIZACION DEL PROCESO HIJO!
        exit(EXIT_SUCCESS);
    }
    } //end switch
    //======= NO COLOCAR NADA DESPUES DE AQUI, SI CONSIDERAS QUE EL PROCESO PADRE EJECUTE ALGO INDEPENDIENTE, DEBE SER DENTRO DEL IF, Y LO MISMO EN EL HIJO. ======/
} //end main

void *lexan(void *args) // lexan V1.0 
{ 
    struct TOKEN_LEX *TOK; 
    TOK = (struct TOKEN_LEX *)args;

    /*DEFINO A MCOM */
    MCOM = (char **)malloc(10*sizeof(char *));
        for (int i = 0; i < 11;i++)
            MCOM[i] = (char *)malloc(2*sizeof(char));
    /*DEFINO A MCOM */  
    
    /*#*/MCOM = LOAD_ALPHABET(MCOM); // HACE LA CARGA DE LOS ALFABETOS.
    THIS_NRM(0);THIS_OK();THIS_NRM(1);printf("Successfully\n");

}//fin analicis lexico

