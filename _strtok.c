#include <stdio.h>
#include <string.h>

void custom_strtok(const char *str, char delimeter)
{
        int len = strlen(str);
        char word[len + 1];
        int i, j;

        for (i = 0; i <= len; i++)
        {
                j = 0;
                if (str[i] == delimeter || str[i] == '\0')
                        word[j] = '\0';
                if (j > 0)
                {
                printf("%s\n", word);
                j = 0;
                }
                else
                {
                word[j++] = str [i];
                }

        }
}
	int main(void)

{
    const char *example_string = "This is a sample string";
    char delimiter = ' ';

    custom_strtok(example_string, delimiter);
        return 0;
}
