#include<stdio.h>
#include<unistd.h>
void main()
{
    execl("/usr/bin/ls","ls","-l",NULL); //print files in the current directory
}
