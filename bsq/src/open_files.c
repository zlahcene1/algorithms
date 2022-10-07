/*
** EPITECH PROJECT, 2020
** open file
** File description:
** lib
*/

#include "my.h"
#include "bsq.h"

char *open_file(char *str)
{
    char *buffer = NULL;
    int fd = 0;
    struct stat size;

    if ((fd = open(str, O_RDONLY)) <= 0)
        return ("NTM\0");
    if (stat(str, &size) < 0)
        return ("NTM\0");
    buffer = malloc(sizeof(char) * size.st_size + 1);
    if (read(fd, buffer, size.st_size) <= 0)
        return ("NTM\0");
    buffer[size.st_size] = '\0';
    close(fd);
    return (check_buffer(buffer));
}
