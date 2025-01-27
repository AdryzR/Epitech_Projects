/*
** EPITECH PROJECT, 2024
** test
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stdbool.h>

int size_of_word(char *word, char delim)
{
    int length = 0;

    while (word[length] && word[length] != delim)
        ++length;
    return length;
}

int number_of_words(char *str, char delim)
{
    int nb_words = 0;

    for (bool is_word = false; str[0]; str++) {
        if (str[0] == delim) {
            is_word = false;
            continue;
        }
        if (is_word == false) {
            is_word == true;
            nb_words++;
        }
    }
    return nb_words;
}

void set_words(char **words, char *str, char delim)
{
    int word_len = 0;

    for (int pos_words = 0; *str; ++pos_words) {
        for (; *str == delim && *str; ++str);
        if (!*str) {
            words[pos_words] = NULL;
            break;
        }
        word_len = size_of_word(str, delim);
        words[pos_words] = malloc(sizeof(char) * (word_len + 1));
        for (int pos_char = 0; *str != delim && *str != '\0'; str++) {
            words[pos_words][pos_char] = *str;
            pos_char++;
        }
        words[pos_words][word_len] = '\0';
        str = (*str) ? str + 1 : str;
    }
}

char **my_str_to_word_array(char *str, char delim)
{
    char **words = NULL;
    int words_count = 0;

    if (!str)
        return NULL;
    words_count = number_of_words(str, delim);
    words = malloc(sizeof(char *) * (words_count + 1));
    for (size_t i = 0; i < words_count + 1; i++)
        words[i] = NULL;
    set_words(words, str, delim);
    return words;
}
