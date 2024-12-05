/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patferna <patferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:38:43 by patferna          #+#    #+#             */
/*   Updated: 2024/12/05 12:38:43 by patferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

char *initialize_save(void)
{
    char *save = malloc(1);
    if (!save)
    {
        return NULL;
    }
    save[0] = '\0';
    return save;
}
int handle_read_error(ssize_t bytes_read, char **save) 
{
    if (bytes_read < 0)
    {
        free(*save);
        *save = NULL;
        return 1;
    }
    return 0;
}

char *join_and_free(char *save, char *buffer) 
{
    char *tmp;
    
    tmp = ft_strjoin(save, buffer);
    if (!tmp) 
    {
        free(save);
        return NULL;
    }
    free(save);
    return tmp;
}

char *finalize_save(char **save) 
{
    char *line;
    
    line  = NULL;
    if (*save && **save != '\0')
        line = ft_strdup(*save);
    free(*save);
    *save = NULL;
    return line;
}

char *get_next_line(int fd) 
{
    static char *save = NULL;
    char buffer[BUFFER_SIZE + 1];
    ssize_t bytes_read;

    if (!save)
        save = initialize_save();
    if (!save)
        return NULL;
    while (1) 
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (handle_read_error(bytes_read, &save))
            return NULL;
        if (bytes_read == 0)
            return finalize_save(&save);
        buffer[bytes_read] = '\0';
        save = join_and_free(save, buffer);
        if (!save)
            return NULL;
        if (ft_strchr(save, '\n'))
            return extract_line(&save);
    }
}