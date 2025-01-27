/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-adrien.raphanaud
** File description:
** lenarray
*/

#include "../include/my.h"

int len_array(char **array)
{
    int i = 0;

    while (array[i])
        i++;
    return i;
}
