#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <utime.h>
int main(int argc, const char *argv[])
{
    int fd;
    if (argc < 2) {
	printf("usage: too few arguemrnts \n");
	exit(1);
    }
    if ((fd = open(argv[1], O_RDONLY)) < 0) {
	if ((fd = open(argv[1], O_CREAT, 0644)) < 0) {
	    printf("can't create file %s\n", argv[1]);
	}
    } else {
	close(fd);
	utime(argv[1], NULL);
    }
}
