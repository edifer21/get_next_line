#include <unistd.h> // Para read() y close()
#include <fcntl.h>  // Para open()
#include <stdio.h>  // Para printf()
#include <stdlib.h> 
#include <string.h> 
#define BUFFER_SIZE 1
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*ptd;
	char			*pts;

	if (!dest && !src)
		return (NULL);
	i = n;
	ptd = (char *) dest;
	pts = (char *) src;
	if (ptd > pts)
	{
		i = n;
		while (i-- > 0)
			ptd[i] = pts[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			ptd[i] = pts[i];
			i++;
		}
	}
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	a;

	a = c;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == a)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	if (a == 0)
	{
		return ((char *) &s[i]);
	}
	return (0);
}

char *search(char *buffer)
{
   // Buscar el primer salto de línea en el buffer
    char *newline_pos = ft_strchr(buffer, '\n');
        size_t n = 4;
    char *linesmall = malloc (n+1);
ft_memmove(linesmall,buffer,n);
    linesmall[n] = '\0';

    //printf ("%s\n",newline_pos);
    /*
    if (newline_pos != NULL)
     {
        // Si encuentras el salto de línea, colocar el terminador nulo
        *newline_pos = '\0';
    }
    linesmall = 
    */
    return linesmall;  // Devuelve el buffer hasta el salto de línea
}
char *get_next_line(int fd)
{
    static char *save;
    char buffer[BUFFER_SIZE + 1];
     char *newline_pos;
    char *str;
    ssize_t leerchar;

    // Lee del archivo
    leerchar = read(fd,buffer, BUFFER_SIZE);
    if (leerchar <= 0) // Error o fin de archivo
        return NULL;
    buffer[leerchar] = '\0'; // Agregar terminador nulo
    str = search(buffer);
    //printf ("%s\n",str);
    return strdup(str); // Devuelve la línea leída
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