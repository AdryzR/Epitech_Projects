/*
** EPITECH PROJECT, 2024
** B-CPE-101-STG-1-1-myprintf-malo.brunetti
** File description:
** my_strncpy
*/

#include "../include/my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

char *my_strncpy(char const *src, int n)
{
    int i = 1;
    int j = 0;
    char *dest = malloc(sizeof(my_strlen(src)) + 1);

    for (; i < n; i++) {
        dest[j] = src[i];
        if (src[i] == '\0')
            break;
        j++;
    }
    dest[i] = '\0';
    return dest;
}
