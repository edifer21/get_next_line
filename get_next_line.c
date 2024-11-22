/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patferna <patferna@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-20 12:47:01 by patferna          #+#    #+#             */
/*   Updated: 2024-11-20 12:47:01 by patferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
//#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
/*
char	*get_next_line(int fd)
{
	char str[BUFFER_SIZE + 1]; 
	int leer;
	if  (fd = -1)
		int fd = open ("texto", O_RDONLY);
	return (1);
	leer = read(texto, str,10);
	close (texto);
}
*/

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t leerchar = read(fd,buffer,BUFFER_SIZE);
    if (leerchar <= 0) // Error o fin de archivo
        return NULL;
    buffer[leerchar] = '\0'; // Agregar terminador nulo
    return strdup(buffer);
    //read();
}
int	main(void)
{
	//get_next_line(fd);
	// char	*get_next_line(int fd)
	//char str[20];
    char *line; 
	ssize_t leer;
    int fd = open ("texto", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    
	//return (1);
	//leer = read("texto.txt", str,19);
	//str[leer] = '\0';
	close (fd);
    return 0;
}