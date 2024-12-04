/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patferna <patferna@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-20 12:49:57 by patferna          #+#    #+#             */
/*   Updated: 2024-11-20 12:49:57 by patferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>

char *get_next_line(int fd);
char *ft_strjoin(const char *s1, const char *s2);
char *ft_strdup(const char *s);
char *ft_strchr(const char *s, int c);
size_t ft_strlen(const char *s);
char *ft_strndup(const char *s, size_t n);
char *extract_line(char **save);

#endif
