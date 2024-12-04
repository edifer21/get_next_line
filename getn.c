#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

char *get_next_line(int fd) {
    static char *save = NULL;
    char buffer[BUFFER_SIZE + 1];
    char *tmp;
    ssize_t bytes_read;

    if (!save) {
        save = malloc(1);
        if (!save) {
            perror("Error de memoria en save");
            return NULL;
        }
        save[0] = '\0';
    }

    while (1) {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0) {
            perror("Error de lectura");
            if (save) free(save);
            return NULL;
        }

        if (bytes_read == 0) {
            if (save && save[0] != '\0') {
                char *line = ft_strdup(save);
                free(save);
                save = NULL;
                return line;
            }
            free(save);
            save = NULL;
            return NULL;
        }

        buffer[bytes_read] = '\0';
        tmp = ft_strjoin(save, buffer);
        if (!tmp) {
            free(save);
            return NULL;
        }
        free(save);
        save = tmp;

        if (ft_strchr(save, '\n')) {
            return extract_line(&save);
        }
    }
}
