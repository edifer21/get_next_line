#include <unistd.h> // Para read() y close()
#include <fcntl.h>  // Para open()
#include <stdio.h>  // Para printf()
#include <stdlib.h> 
#include <string.h> 
#define BUFFER_SIZE 3

char *ft_strndup(const char *s, size_t n) {
    // Reserva memoria para los primeros n caracteres + el terminador nulo
    char *dup = malloc(n + 1);
    if (!dup)  // Verifica que la memoria se haya reservado correctamente
        return NULL;
    
    // Copia hasta n caracteres de s a dup
    strncpy(dup, s, n);
    
    // Asegura que la nueva cadena esté terminada en nulo
    dup[n] = '\0';
    
    return dup;
}


char *ft_strdup(const char *s) {
    // Reserva memoria para la cadena (incluye el terminador nulo)
    char *dup = malloc(strlen(s) + 1); 
    if (!dup)  // Verifica que la memoria se haya reservado correctamente
        return NULL;
    
    // Copia la cadena original a la nueva ubicación de memoria
    strcpy(dup, s); 
    
    return dup;
}


size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
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
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1_len;
	size_t	str2_len;
	size_t	ptr_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	str2_len = ft_strlen(s2);
	ptr_len = s1_len + str2_len;
	ptr = malloc(((ptr_len) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	if (s1)
		ft_memmove (ptr, s1, s1_len);
	if (s2)
		ft_memmove (ptr + s1_len, s2, str2_len);
	ptr[ptr_len] = '\0';
	return (ptr);
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

char *extract_line(char **save)
{
    char *newline_pos = ft_strchr(*save, '\n');
    char *line;
    char *remaining;

    if (newline_pos) 
    {
        size_t len = newline_pos - *save + 1;
        line = ft_strndup(*save, len);
        remaining = ft_strdup(newline_pos + 1);
        free(*save);
        *save = remaining;
    } else {
        line = ft_strdup(*save);
        free(*save);
        *save = NULL;
    }
    return line;
}


/*
char *search(char *buffer)
{
    char *newline_pos = ft_strchr(buffer, '\n');
    size_t n;
    
    if (newline_pos != NULL) 
    {
        n = newline_pos - buffer + 1;
    } 
    else 
    {
        n = strlen(buffer);
    }
    char *linesmall = malloc (n+1);
    if (!linesmall)
        return NULL;
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
    
    return linesmall;  // Devuelve el buffer hasta el salto de línea
    }
  */  

char *get_next_line(int fd)
{
    static char *save;
    char buffer[BUFFER_SIZE + 1];
     char *newline_pos;
    char *tmp;
    ssize_t leerchar;
     if (!save)
        save = NULL;
    
  while (!ft_strchr(save, '\n'))
    {
    leerchar = read(fd,buffer, BUFFER_SIZE);
    if (leerchar <= 0) // Error o fin de archivo
        return NULL;
    buffer[leerchar] = '\0'; // Agregar terminador nulo
  
    tmp = ft_strjoin(save, buffer);
    free(save);
    save =tmp;
    //printf ("%s\n",str);
    }
    return extract_line(&save);
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
    line = get_next_line(fd);
        printf("%s", line);
        printf("%s", line);
        printf("%s", line);
/*
    // Lee líneas del archivo
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
*/
    // Cierra el archivo
    close(fd);
    return 0;
}