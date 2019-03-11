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
#endif
void *lexan(void *);

        struct ALPHABETIC_STRUCTURE
        {
            char reserved_words[3]; //PALABRAS RESERVADAS
            char cod_asc_words[8];  //CODIGO ASCII DE LAS PALABRAS RESERVADAS
            //struct ALPHABETIC_STRUCTURE *liga;
        }AS;

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
        //typedef struct ALPHABETIC_STRUCTURE *AS;
        //AS = (AS *) malloc(sizeof(struct ALPHABETIC_STRUCTURE));
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
{ 
    struct ALPHABETIC_STRUCTURE *A; 
    A = (struct ALPHABETIC_STRUCTURE *)args;
    FILE *archivo;

    char  **MCOM = (char **)malloc(10*sizeof(char *));
        for (int i = 0; i < 10;i++)
            MCOM[i] = (char *)malloc(2*sizeof(char));
    char **ALPHABET_M = (char **) malloc (6*sizeof(char *));
        for(int i = 0; i < 6; i++)
            ALPHABET_M[i]=(char *) malloc ( 20 *sizeof(char));

        /*--CARGA DE LOS ALFABETOS--*/
        strcpy(*(ALPHABET_M),   "../dll/data_pr.dll"); //THIS_NRM(0);THIS_OK();THIS_NRM(1); printf(" Correcta carga del pr.\n");
        strcpy(*(ALPHABET_M+1), "../dll/data_op.dll"); //THIS_NRM(0);THIS_ERROR();THIS_NRM(1); printf(" Correcta carga del pr.\n");
        strcpy(*(ALPHABET_M+2), "../dll/data_se.dll");
        /*--CARGA DE LOS ALFABETOS--*/

    int x = 0; //CONTADOR POR ARCHIVO
    while( x != 1){ // EL 1 INDICA LA CANTIDAD DE ARCHIVOS A LEER
        archivo = fopen(*(ALPHABET_M + x), "r"); 

        if(archivo == NULL){
            THIS_NRM(0);THIS_ERROR();THIS_NRM(1); printf(" Archivo '%s' en conflicto.\n",*(ALPHABET_M  + x));
            exit(EXIT_FAILURE);
        } else {
            char temp[2], temp_f1[2], *devf; int j = 0;
            /*  for(int j = 0; j < 2 && !feof(archivo); j++){
               //fgets(*(MCOM + i),2,archivo);
                fscanf(archivo, "%[^\n]" ,temp_f1);
                //temp_f1[1] = fgetc(archivo);

                   // strncat(temp,temp_f1,3);
                    strcpy(*(MCOM+x),temp_f1);
                    THIS_NRM(0);THIS_OK();THIS_NRM(1);printf("Recerved Word: %s\n",*(MCOM + x));
                    strcpy(temp_f1, "");

            }//fin del for 
            */
                //THIS_NRM(0);THIS_OK();THIS_NRM(1);printf("Recerved Word: %s\n",*(MCOM + 1));
            do{
                devf = fgets(temp_f1,5,archivo);
                    strcpy(*(MCOM+j),temp_f1); printf("%s\n",temp_f1);
                THIS_NRM(0);THIS_OK();THIS_NRM(1);printf("Recerved Word: %s, j=[%d]\n",*(MCOM + j),j);
                    j++;
             }while (devf!=NULL && j<2);
        }
                   
                    //THIS_NRM(0);THIS_OK();THIS_NRM(1);printf("Recerved Word: %c\n",MCOM[0][1]);
                    //THIS_NRM(0);THIS_OK();THIS_NRM(1);printf("Recerved Word: %c\n",MCOM[1][0]);
                    //THIS_NRM(0);THIS_OK();THIS_NRM(1);printf("Recerved Word: %c\n",MCOM[1][1]);
        x++;
    }//fin del whihle encargado de tomar cada archivo
        fclose(archivo);
        free(ALPHABET_M);ALPHABET_M = NULL; //libero la memoria utilizada para esta matriz
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

