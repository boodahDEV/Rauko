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
        #define THIS_NRM(a) ((a == 0)? printf("\x1B[0m ["): printf("\x1B[0m]"))
#else
    #define sys "WIN"
  //  #define TYPE_SYSTEM_EXEC(sys) ((sys == "WIN") ? printf("Ejecutando en sistema basado en Windows/Microsoft.\n\n\n") : printf("Ejecuntando en sistema basado en GNU/LINUX..\n\n\n"))
#endif
void *lexan(void *);

        struct ALPHABETIC_STRUCTURE
        {
            char reserved_words[3]; //PALABRAS RESERVADAS
            char cod_asc_words[8];  //CODIGO ASCII DE LAS PALABRAS RESERVADAS
            struct ALPHABETIC_STRUCTURE *liga;
        };

int main(int argc, char const *argv[])
{
    //char TEXT[50];
    int STATUS;
    static pid_t RESULT_FORK, PID_SON, PID_DAD;
    //TYPE_SYSTEM_EXEC(sys);     // tipo de sistema en ejecucion.
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
        typedef struct ALPHABETIC_STRUCTURE *nodo;
        nodo *AS = (nodo *)malloc(sizeof(struct ALPHABETIC_STRUCTURE));
        PID_SON = getpid(); //DEVUELVE EL ID DEL PROCESO HIJO

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
    struct ALPHABETIC_STRUCTURE *A, *B; 
    A = (struct ALPHABETIC_STRUCTURE *)args;
    B = A;
    char  MCOM[12][2]={0}; //TEMPORALMENTE, SE ELIMINARA EN PROXIMA VERSIONES
    B = (A *)malloc(struct A);
    FILE *archivo;
    


    char **ALPHABET_M = (char **) malloc (6*sizeof(char *));
        for(int i = 0; i < 6; i++)
            ALPHABET_M[i]=(char *) malloc ( 20 *sizeof(char));
            //strcpy(ALPHABET_M[1], "mundo");
        strcpy(*(ALPHABET_M),   "../dll/data_pr.dll"); //THIS_NRM(0);THIS_OK();THIS_NRM(1); printf(" Correcta carga del pr.\n");
        strcpy(*(ALPHABET_M+1), "../dll/data_op.dll"); //THIS_NRM(0);THIS_ERROR();THIS_NRM(1); printf(" Correcta carga del pr.\n");
        strcpy(*(ALPHABET_M+2), "../dll/data_se.dll");
        
    int i = 0;
    while( i != 1){
        archivo = fopen(*(ALPHABET_M + i), "r");

        if(archivo == NULL)
            exit(EXIT_FAILURE);
        else {
            while(feof(archivo)==0){
               fgets(A->reserved_words,2,archivo);
            }
        }

        i++;
    }

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
       // ALPHABET_M = NULL;//--


       //LOAD_ALPHABET(ALPHABET_M,MCOM, AS);//pthread_exit(AS->LEX_THREAD_MAIN); //recordar trate de cerrar el hilo de ejecucion
}//fin analicis lexico

