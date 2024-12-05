/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patferna <patferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:37:26 by patferna          #+#    #+#             */
/*   Updated: 2024/12/05 13:37:26 by patferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>  // Para read()
#include <stdlib.h>  // Para malloc() y free()
#include <string.h>  // Para memcpy()
#include <stdio.h>   // Para perror()
#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptd;
	unsigned char	*pts;

	if (!dest && !src)
		return (NULL);
	ptd = (unsigned char *) dest;
	pts = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		ptd[i] = pts[i];
		i++;
	}
	return ((void *)dest);
}

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
	len++;
	return len;
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
		ft_memcpy (ptr, s1, s1_len);
	if (s2)
		ft_memcpy (ptr + s1_len, s2, str2_len);
	ptr[ptr_len] = '\0';
	return (ptr);
}
char *ft_strdup(const char *s)
{
	size_t len;
	char *dup;
	
	len = strlen(s) + 1;
	dup = malloc(len);
	if (!dup) 
		return NULL;
	memcpy(dup, s, len);
	return dup;
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
	char *newline_pos;
	size_t len;
	char *line;
	char *remaining;

	newline_pos = ft_strchr(*save, '\n');
	if (!newline_pos)
		return NULL;
	len = newline_pos - *save + 1;
	line = ft_strndup(*save, len);
	if (!line) 
	return NULL;
	remaining = ft_strdup(newline_pos + 1);
	if (!remaining) 
	{
		free(line);
		return NULL;
	}
	free(*save);
	*save = remaining;
	return line;
}

char *ft_strndup(const char *s, size_t n)
{
	char *dup;

	dup =  malloc(n + 1);
	if (!dup)
		return NULL;
	memcpy(dup, s, n);
	dup[n] = '\0';
	return dup;
}
