/*
** EPITECH PROJECT, 2021
** am
** File description:
** am
*/

#include "my.h"

int open_file(char const *filepath)
{
    struct stat sb;
    int s = stat(filepath, &sb);
    char *buffer = malloc(sizeof(char) * sb.st_size);
    int fd = open(filepath, O_RDONLY);
    int rd = 0;

    if (buffer == NULL)
        return 84;
    rd = read(fd, buffer, sb.st_size);
    if (fd < 0)
        return 84;
    if (rd < 0)
        return 84;
    if ((sb.st_size) == 0)
        return 84;
    if (s == -1)
        return 84;
    return 0;
}
