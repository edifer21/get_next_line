#include <unistd.h>  // Para read()
#include <stdlib.h>  // Para malloc() y free()
#include <string.h>  // Para memcpy()
#include <stdio.h>   // Para perror()
#include "get_next_line.h"

char *ft_strjoin(const char *s1, const char *s2) {
    if (!s1 || !s2) return NULL;
    size_t s1_len = strlen(s1);
    size_t s2_len = strlen(s2);
    char *result = malloc(s1_len + s2_len + 1);
    if (!result) return NULL;
    memcpy(result, s1, s1_len);
    memcpy(result + s1_len, s2, s2_len);
    result[s1_len + s2_len] = '\0';
    return result;
}

char *ft_strdup(const char *s) {
    size_t len = strlen(s) + 1;
    char *dup = malloc(len);
    if (!dup) return NULL;
    memcpy(dup, s, len);
    return dup;
}

char *ft_strchr(const char *s, int c) {
    while (*s) {
        if (*s == (char)c) return (char *)s;
        s++;
    }
    return (c == '\0') ? (char *)s : NULL;
}

size_t ft_strlen(const char *s) {
    size_t len = 0;
    while (s[len]) len++;
    return len;
}

char *extract_line(char **save) {
    char *newline_pos = ft_strchr(*save, '\n');
    if (!newline_pos) return NULL;

    size_t len = newline_pos - *save + 1;
    char *line = ft_strndup(*save, len);
    if (!line) return NULL;

    char *remaining = ft_strdup(newline_pos + 1);
    if (!remaining) {
        free(line);
        return NULL;
    }

    free(*save);
    *save = remaining;

    return line;
}

char *ft_strndup(const char *s, size_t n) {
    char *dup = malloc(n + 1);
    if (!dup) return NULL;
    memcpy(dup, s, n);
    dup[n] = '\0';
    return dup;
}
