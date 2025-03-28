#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;
fstream file;
string filename = "hello.txt";
int main()
{
    file.open(filename, ios::out | ios::in);
    if (!file)
    {
        file.open(filename, ios::out);
        file.close();
        file.open(filename, ios::in | ios::out);
    }
    pid_t c_pid = fork();
    if (c_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (c_pid > 0)
    {
        cout << "This is the parent process: " << getpid() << endl;
        file.write("Parent: Hello World ", 20);
    }
    else
    {
        cout << "This is the child process: " << getpid() << endl;
        file.write("Child: Hello World ", 19);
    }
    file.close();
    return 0;
}
