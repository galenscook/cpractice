#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mystrcpy(char *dest, const char *src) {
    int i;
    for (i=0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("ERROR: You need one argument.\n");
        return 1;
    }

    char *src = argv[1];
    char *dest = malloc(strlen(src));

    mystrcpy(dest, src);

    printf("This is my copied string : %s\n", dest);

    free(dest);

    return 0;
}
