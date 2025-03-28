#include <iostream>
#include <cstdio>
#include <unistd.h>
using namespace std;
int main()
{
    pid_t c_pid = fork();
    if (c_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (c_pid > 0)
    {
        cout << "Goodbye" << endl;
    }
    else
    {
        close(STDOUT_FILENO);
        printf("Hello");
    }
    return 0;
}