
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>

int main(int argc, const char *argv[])
{
    if(argc != 2){
        printf("usage: cd argument need\n");
        exit(1);
    }
    chdir(argv[1]);
}

