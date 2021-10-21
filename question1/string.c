#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

int main(){
    void* func(void* arg)
    {
        // detach the current thread
        // from the calling thread
        pthread_detach(pthread_self());
    
        printf("Inside the thread\n");
    
        // exit the current thread
        pthread_exit(NULL);
    }

    char fav;
    pid_t pid = fork();
    pthread_t ptid;

    printf("Enter command: ");
    scanf("%s", fav);

    if ("$(type -t %s)", fav == "builtin"){
        int status;
        waitpid(pid, &status, 0);
        printf("*** Succesfully exec %d\n", pid);
    } else
    {
        pthread_create(&ptid, NULL, &func, NULL);
        printf("This line may be printed"
           " before thread terminates\n");
    }
    

}