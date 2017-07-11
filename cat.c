#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, const char *argv[])
{
    int fdin;
    int nread;
    char buffer[1024];
    if (argc != 2) {
	printf("usage: cat\n");
    }
    if ((fdin = open(argv[1], O_RDONLY)) < 0) {
	printf("can't open file\n");
	exit(1);
    }
    while ((nread = read(fdin, buffer, 1024)) > 0) {
	write(1, buffer, nread);
    }
    close(fdin);
}
