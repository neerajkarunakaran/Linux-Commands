#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#define NORMAL "\x1b[0m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
void read_dir_recur(char *path);
int main(int argc, const char *argv[])
{
    char *path;
    char buf[1024];
    if ((path = getcwd(buf, 1024)) != NULL) {
	read_dir_recur(path);
    }
}

void read_dir_recur(char *path)
{
    DIR *d;
    struct dirent *dir;
    d = opendir(path);
    while ((dir = readdir(d)) != NULL) {
	if (dir->d_type != DT_DIR) {
	    printf("%s%s ", NORMAL, dir->d_name);
	} else {
	    if (dir->d_type == DT_DIR && strcmp(dir->d_name, ".") != 0
		&& strcmp(dir->d_name, "..") != 0) {
		printf("%s%s ", BLUE, dir->d_name);
		char dpath[255];
		sprintf(dpath, "%s/%s", path, dir->d_name);
		printf("->");
		read_dir_recur(dpath);
	    }
	}
    }
    printf("\n");
    closedir(d);
}
