#include<stdio.h>
#include<unistd.h>
#include<dirent.h>//for file related

int main(){

    DIR *d;
    struct dirent *de;
    d=opendir(".");
    while(de=readdir(d))
    {
        printf("%s\n",de->d_name);
    }
    return 0;

}