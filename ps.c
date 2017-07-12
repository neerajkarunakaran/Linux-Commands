
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
void print_process(char path[]);

    

int main(void)
{   
    int c;
    DIR *d;
    char path[1024];
    struct dirent *dir;
    if((d = opendir("/proc")) != NULL){
        while((dir = readdir(d)) != NULL) {
            if(dir->d_type == DT_DIR && strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..")) {
                c = dir->d_name[0];
                if(isdigit(c)){
                    sprintf(path, "/proc/%s/cmdline", dir->d_name);
                    print_process(path);
                    printf("    %s\n", dir->d_name);
                }
            }

        }
    }
}

void print_process(char path[])
{
    int fd, nread;
    char buf[1024];
    fd = open(path, O_RDONLY);
    while((nread = read(fd, buf, 1024)) > 0){
        if(strcmp(buf, "\n") != 0){
            write(1, buf, nread);
        }
    }
}
        
