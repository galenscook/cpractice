#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mystrcpy(char *dest, const char *src) {
    int i;
    for (i=0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i];
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("ERROR: You need one argument.\n");
        return 1;
    }

    char *src = argv[1];
    // Use calloc for things you aren't going to completely overwrite to avoid crazy memory ish
    char *dest = calloc(strlen(src) + 1);

    mystrcpy(dest, src);

    printf("This is my copied string : %s\n", dest);

    free(dest);

    return 0;
}
