#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, const char *argv[])
{
    int fds[100], fd;
    int nread;
    char buf[1024];
    if (argc == 1) {
	while ((nread = read(0, buf, 1024)) > 0) {

	    write(1, buf, nread);
	}
    } else {

	for (int i = 1, j = 0; i < argc && j < 100; i++, j++) {
	    if ((fd = open(argv[i], O_RDONLY)) >= 0) {
		close(fd);
		fds[j] = open(argv[i], O_WRONLY);
	    } else {
		if ((fds[j] = open(argv[i], O_CREAT | O_WRONLY, 0644)) < 0) {
		    printf("can't create %s\n", argv[i]);
		}
	    }


	}
	while ((nread = read(0, buf, 1024)) > 0) {
	    write(1, buf, nread);
	    for (int i = 0; i < argc - 1; i++) {
		write(fds[i], buf, nread);
	    }
	}
    }
    for (int i = 0; i < argc - 1; i++) {
	close(fds[i]);
    }


}
