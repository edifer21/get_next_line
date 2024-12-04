#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    FILE *file = fopen("texto.txt", "r");
    if (!file)
    {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fileno(file))) != NULL)
    {
        printf("%s", line); // Agregamos un salto de línea para asegurar el formato
        free(line);
    }
    fclose(file);
    return 0;
}
