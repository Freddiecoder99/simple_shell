#include <stdlib.h>
#include <stdio.h>

int main()
{
        int i;
        int *buff;
        int size;

        printf("Enter the number to allocate: ");
        scanf("%d", &size);

        buff = (int *)malloc(size * sizeof(int));
        if (buff == NULL)
        {
                printf("Can't allocate memory\n");
        }
        else
        {
                for (i = 0; i < size; i++)
                {
                        buff[i] = i + 1;
                }
                printf("NUMBERS: ");
                for (i = 0; i <size; i++)
                {
                        printf("%d", buff[i]);
                }
        }
        printf("\n");
        free(buff);
        return 0;
}
