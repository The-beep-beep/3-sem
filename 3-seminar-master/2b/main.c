#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            printf("Error\n");
            exit(1);
        }
        else if (pid == 0) {
            printf("Created child process %d with PID = %d, PPID = %d\n", i, getpid(), getppid());
        }
        else {
            int status = 0;
            wait(&status);
            printf("Child process %d with PID= %d is complete. Exit from current process PID = %d\n",
                           i, pid, getpid());
            exit(0);
        }
    }
}
