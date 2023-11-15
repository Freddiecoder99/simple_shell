#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
        DIR *dir;
        char *path = ".";
        struct dirent *read_dir;

        /*call openddir function to open the dir and store the result*/
        dir = opendir(path);
        if (dir == NULL)
        {
                perror("can't open the dir");
        }

        while ((read_dir = readdir(dir)) != NULL)
        {
                if (read_dir->d_type == DT_REG)
                {
                        /*if there are files, just print their names*/
                        printf("FILE: %s\n", read_dir->d_name);
                }
                /*checking for dirs*/
                else if (read_dir->d_type == DT_DIR)
                {
                        printf("DIR: %s\n", read_dir->d_name);
                }
        }
        if (closedir(dir) == -1)
        {
                perror("can't close the dir\n");
                return 1;
        }
        return 0;
}
