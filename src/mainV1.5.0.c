#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>


void main(int argc, char const *argv[]){
static pid_t RESULT_FORK;
static pthread_t LEX_THREAD_MAIN; // hilo de ejecucion del analicis lexico!
RESULT_FORK = fork();


  if (RESULT_FORK==-1){
      printf("Error al crear procesos!"); //Salgo del sistema!
    } else if (RESULT_FORK==0){ 
            
            printf("\n\tID del HIJO: %d y el papa es: %d\n",getpid(),getppid());
        }else{
            printf("\n\tID del PADRE: %d y el padre es: %d\n",getpid(),getppid());
         }
 //   printf("\n\n\tID del PADRE: %d y el padre es: %d\n",getpid(),getppid());

}//end main

