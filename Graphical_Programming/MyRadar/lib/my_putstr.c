/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** my_putstr
*/

#include "../include/my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int my_putstr(int fd, char const *str)
{
    write(fd, str, my_strlen(str));
}
