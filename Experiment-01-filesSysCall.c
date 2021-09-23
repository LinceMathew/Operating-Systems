#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
int main(){
    int fd;
    char wbuf[123]="hello";
    char rbuf[128];
    fd =open("file.txt",O_RDWR);
    // write(fd,wbuf,strlen(wbuf));
    read(fd,rbuf,100);
    printf("%s\n",rbuf);
    close(fd);



    return 0;
}