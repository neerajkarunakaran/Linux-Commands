


#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define NORMAL "\0x1b[0m"
#define GREEN "\0x1B[32m"
#define BLUE "\0x1b[34m"

int main(void)
{
    DIR * d;
    struct dirent *dir;
    char *path;
    char buf[1024];
    if((path = getcwd(buf, 1024)) != NULL){
        d = opendir(path);
        while(( dir = readdir(d)) != NULL) {
            if(dir->d_type != DT_DIR){

                printf("%s%s ", GREEN, dir->d_name);
            } else{
                if(dir->d_type == DT_DIR && strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0){
                    printf("%s%s ", BLUE, dir->d_name);
                }
            }
        }
        printf("\n");
        closedir(d);
    }
}
                    
               
    
