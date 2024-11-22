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

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
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
	read();
}
int	main(void)
{
	//get_next_line(fd);
	// char	*get_next_line(int fd)
	char str[20]; 
	ssize_t leer;
	if  (fd = -1)
	int fd = open ("texto", O_RDONLY);
	return (1);
	leer = read("texto.txt", str,19);
	str[leer] = '\0';
	close (texto)
    ,
}