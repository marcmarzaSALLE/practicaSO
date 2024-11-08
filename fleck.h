#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>

#define writing(x) write(1, x, strlen(x))


typedef struct
{
    char *name;
    char *directory;
    char *ipServer;
    int portServer;
} Fleck;