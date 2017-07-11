#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/stat.h>
int main(int argc, const char *argv[])
{
    struct stat s;
    if (argc != 2) {
	printf("usage: rmdir\n");
	exit(1);
    }
    stat(argv[1], &s);
    if (S_ISDIR(s.st_mode)) {
	if (rmdir(argv[1]) < 0) {
	    printf("rmdir: is not empty\n");
	}
    } else {
	printf("rmdir: %s is not directory\n", argv[1]);
    }
}
