int main(void) {
    int fd = open("texto.txt", O_RDONLY);
    if (fd == -1) { perror("Error al abrir el archivo"); return 1; }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("Leida linea: %s", line);
        free(line);
    }

    close(fd);
    return 0;
}