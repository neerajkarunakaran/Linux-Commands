#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
    struct stat s;
    mode_t mode;
    if (argc != 2) {
	printf("usage: rm\n");
	exit(1);
    }
    stat(argv[1], &s);
    mode = s.st_mode;
    if (mode & S_IFREG) {
	unlink(argv[1]);
    } else {
	printf("%s is not remove, is a directory\n", argv[1]);
    }
}
