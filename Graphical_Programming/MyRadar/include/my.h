/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** my_printf
*/

#include <stdbool.h>
#ifndef MY_H

    #define MY_H
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdarg.h>

char **my_str_to_word_array(char *str, char delim);
int len_array(char **array);
void my_putchar(char c);
void my_putchar_ch(char c, int fd);
int my_strcmp(char const *s1, char const *s2);
char *my_strncpy(char const *src, int n);
void my_putchar_ch(char c, int fd);
int my_put_nbr(int nb);
int my_put_nbr_ch(int nb, int fd);
int my_putstr(int fd, char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);

#endif
