
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    if (fork() == 0) {
        execlp("gcc", "gcc", "HelloWorld.c", "-o", "HelloWorld", NULL);
    }
    int status = 0;
    wait(&status);
    execlp("./HelloWorld", "./HelloWorld", NULL);
    return 0;
}
