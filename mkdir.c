#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int argc, const char *argv[])
{
    mode_t mode;
    mode = 16877;
    if(argc != 2) {
        printf("usage: mkdir\n");
        exit(1);
    }
    if(mkdir(argv[1], mode) < 0) {
        printf("can't make directory\n"); } 
}
