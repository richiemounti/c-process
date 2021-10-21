#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>


int main(){
    void sig_chld(int signo) {
        pid_t pid;
        int stat;

        // while ((pid = wait(&stat)) > 0)
        while ((pid = waitpid(-1, &stat, WNOHANG)) > 0)
        {
            printf("child %d terminated\n", pid);
        }
    }
}