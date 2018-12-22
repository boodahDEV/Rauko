#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
 
int main(){
    pid_t pid;
 
    if ( (pid=fork()) == 0 ){ /* hijo */
        printf("Soy el hijo (%d, hijo de %d)\n", getpid(),getppid());

/*         pid_t p;
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
    } */
    else{ /* padre */
        printf("Soy el padre (%d, hijo de %d)\n", getpid(),
        getppid());
    }
 
    return 0;
}