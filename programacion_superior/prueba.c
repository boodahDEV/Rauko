#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/wait.h>
#include  <sys/mman.h>

void main(){
    pid_t pid;
    int test = 5;
    int *number = (int*)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, 
               MAP_SHARED | MAP_ANONYMOUS, -1, 0);
     *number = 5;


    switch(pid=fork()){
        case 0: {
         printf("Soy el hijo (%d, hijo de %d)\n", getpid(),getppid());
         for(int i=0;i<10;++i){
            usleep(70000);
            printf ("CHILD -- Number: %d\n", *number);
            *number=i;
         }
        }//end case 0
        case -1: {
            printf("*#*\n");
            break;
        }
        default:
            printf("Soy el padre (%d, hijo de %d)\n", getpid(),getppid());
             for(int i=20;i<30;++i){
                 usleep(70000);
                printf ("*****MAIN -- Number: %d\n", *number);
                *number=i;
            }

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
      wait(NULL);
      munmap(number, sizeof(int));
}