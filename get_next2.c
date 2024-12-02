#include <unistd.h> // Para read() y close()
#include <fcntl.h>  // Para open()
#include <stdio.h>  // Para printf()
#include <stdlib.h> 
#include <string.h> 
#define BUFFER_SIZE 5

char *get_next_line(int fd)
{
    char buffer[BUFFER_SIZE + 1];
    ssize_t leerchar;

    // Lee del archivo
    leerchar = read(fd, buffer, BUFFER_SIZE);
    if (leerchar <= 0) // Error o fin de archivo
        return NULL;

    buffer[leerchar] = '\0'; // Agregar terminador nulo
    return strdup(buffer); // Devuelve la línea leída
}

int main(void)
{
    int fd;
    char *line;

    // Abre el archivo
    fd = open("texto.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Lee líneas del archivo
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    // Cierra el archivo
    close(fd);
    return 0;
}
/*
int main() 
{
    int fd; 

    fd = open("example.txt", O_RDONLY);
    if (fd == -1) 
    {
        perror("Error opening file");
        return 1;
    }

    char buffer[1024];
    read(fd, buffer, 1024);
    printf("%s\n", buffer);

    close(fd);
    return 0;
}
*/