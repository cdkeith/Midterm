#include <iostream>
//#include <fstream>
//#include <string>
#include <sys/wait.h>
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
        wait(NULL);
        cout << "Goodbye" << endl;
    }
    else
    {
        cout << "Hello" << endl;
    }
    return 0;
}
