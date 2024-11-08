#include "reads.h"

char *read_untilEnter(int fd, char character, int i)
{
    char *buffer = NULL;

    while (character != '\n' || i == 0)
    {
        read(fd, &character, sizeof(char));

        if (buffer == NULL)
        {
            buffer = (char *)malloc(1 * sizeof(char));
        }
        else
        {
            buffer = (char *)realloc(buffer, i + 1);
        }
        buffer[i] = character;

        if (character == '\n' || character == '\0')
        {
            buffer[i] = '\0';
            return buffer;
        }
        i++;
    }

    return buffer;
}

char *read_until(int fd, char character)
{
    int i = 0, size;
    char c = '\0';
    char *string = NULL;
    char *temp = NULL;

    while (1)
    {
        size = read(fd, &c, sizeof(char));

        if (c != character && size > 0)
        {
            temp = (char *)realloc(string, sizeof(char) * (i + 1));
            if (temp == NULL)
            {
                free(string);
                return NULL;
            }
            string = temp;
            string[i++] = c;
        }
        else
        {
            break;
        }
    }

    temp = (char *)realloc(string, sizeof(char) * (i + 1));
    if (temp == NULL)
    {
        free(string);
        return NULL;
    }
    string = temp;
    string[i] = '\0';

    return string;
}

