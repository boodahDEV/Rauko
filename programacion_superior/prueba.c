#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
 
void main(){
    pid_t pid;
    pthread_t h;
    int test = 5;

    switch(pid=fork()){
        case 0: {
         printf("Soy el hijo (%d, hijo de %d)\n", getpid(),getppid());
         for(int i=1;i<10;i++){
             if(i%2!=0)
             printf("%i\n",i);
         }
         printf("\n#-> %d\n",++test);
        }
        case -1: {
            printf("*#*\n");
            break;
        }
        default:
            printf("Soy el padre (%d, hijo de %d)\n", getpid(),getppid());
             for(int i=0;i<10;i+=2){
                 printf("%i\n",i);
            }
            printf("\n#-> %d\n",--test);
    }//end switch

    /* if ( (pid=fork()) == 0 ){ 
        printf("Soy el hijo (%d, hijo de %d)\n", getpid(),getppid());

        pid_t p;
         if((pid=fork())==0){
             printf("Soy el hijo2 (%d, hijo de %d)\n", getpid(),
         getppid());
         for(int i=0;i<5;i++){
             printf("%i\n",i+1);
         }
         }else{
             printf("Soy el padre2 (%d, hijo de %d)\n", getpid(),
             getppid());
         }
    } 
    else{ 
        printf("Soy el padre (%d, hijo de %d)\n", getpid(),getppid());
    } */
}