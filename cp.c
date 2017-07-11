#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
    int fdin, fdout;
    char buffer[1024];
    int nread;
    struct stat s;
    mode_t mode;
    if (argc != 3) {
	printf("usage: cp \n");
	exit(1);
    }
    if ((fdin = open(argv[1], O_RDONLY)) == 0) {
	printf("can't open file %s\n", argv[1]);
	exit(1);
    }
    stat(argv[1], &s);
    mode = s.st_mode;

    if ((fdout = open(argv[2], O_RDONLY)) < 0) {
	close(fdout);
	if (fdout = open(argv[2], O_CREAT | O_WRONLY, mode)) {
	    while ((nread = read(fdin, buffer, 1024)) > 0) {
		write(fdout, buffer, nread);
	    }
	} else {
	    printf("file create error\n");
	}

	close(fdout);
    } else {
	close(fdout);
	if (fdout = open(argv[2], O_WRONLY)) {
	    while ((nread = read(fdin, buffer, 1024)) > 0) {
		write(fdout, buffer, nread);
	    }
	} else {
	    printf("file create error\n");
	}
	close(fdout);
    }
    close(fdin);
}
