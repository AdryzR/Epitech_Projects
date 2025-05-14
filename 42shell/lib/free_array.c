/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** free_array
*/

#include <stdlib.h>
#include <stdio.h>

void free_array(char **array)
{
    if (!array)
        return;
    for (int i = 0; array[i]; i++)
        if (array[i])
            free(array[i]);
    free(array);
}
