#include <stdio.h>

int main()
{
        FILE* file;

        /*call open function to open the file by write mode*/
        file = fopen("flush.txt", "w");
        /*checking for errors while opening*/
        if (file == NULL)
        {
                perror("can't open the file");
                return 1;
        }

        /*using fprintf function to write inside the file*/
        fprintf(file, "Hello form, ");
        /*making sure that the file is flushed*/
        fflush(file);

        /*we wrote again*/
        fprintf(file, "world C,!\n");
        /*closing the file*/
        fclose(file);
        return 0;
}
