/*
** EPITECH PROJECT, 2022
** 
** File description:
** 
*/

#include <cstdlib>
#include <cstddef>

static int size_w(char *input, int ix)
{
    int i = 0;

    for (; input[ix] != '\0'; ix++, i++)
        if (input[ix] == '\n')
            return (i);
    return (i);
}

static int count_word(char *input)
{
    int nb = 0;

    for (int i = 0; input[i] != '\0' ;i++)
        if (input[i] == '\n')
                nb++;
    return (nb + 1);
}

char **str_to_word_array(char *input)
{
    int nb_word = count_word(input);
    char **tb = (char **) malloc((nb_word + 1) * sizeof(char *));
    int i = 0;
    int j = 0;
    int ix = 0;

    for (; i != nb_word; i++, ix++) {
        tb[i] = (char *) malloc((size_w(input, ix) + 1) * sizeof(char));
        j = 0;
        for (int size = size_w(input, ix); j < size; ix++, j++) {
            tb[i][j] = input[ix];
        }
        tb[i][j] = '\0';
    }
    tb[nb_word] = NULL;
    return (tb);
}
