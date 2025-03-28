#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
fstream file;
string filename;
int main()
{
    do 
    {
        int processes;
        char exType;
        string filename;
        cout << "Enter -1 to exit" << endl;
        cout << "closh> ";
        cin >> filename;
        cout << "count> ";
        cin >> processes;
        while (processes <= 0 && processes >= 10)
        {
            cout << "please enter a number from 1 to 9> ";
            cin >> processes;
        }
        cout << "[p]arallel or [s]equential> ";
        cout << exType;
        while (exType != 'p' && exType != 's')
        {
            cout << "please enter p or s> ";
            cin >> exType;
        }
        for (int i = 0; i < processes; i++)
        {
            pid_t c_pid = fork();
            if (c_pid == 0)
            {
                char myArgs[3];
                myArgs[0] = strdup(filename);
                myArgs[1] = strdup("closh.cpp");
                myArgs[2] = NULL;
                if (exType == 's')
                {
                    wait(NULL);
                }
                execvp(myArgs[0], myArgs);
            }
        }
    } while (filename != "-1");
    return 0;
}