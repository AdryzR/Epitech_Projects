/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** check_builtin
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "printf.h"
#include "my_sh.h"

void use_previous_path(shell_t *shell)
{
    char *new_line = NULL;
    int size = 0;

    if (shell->path_copy == NULL)
        return;
    size = my_strlen("PATH") + my_strlen(shell->path_copy) + 2;
    new_line = malloc(sizeof(char) * (size + 1));
    if (!new_line)
        return;
    my_strcpy(new_line, "PATH");
    my_strcat(new_line, "=");
    my_strcat(new_line, shell->path_copy);
    add_env_line(new_line, shell);
    free(new_line);
}

void is_path_existing(shell_t *shell)
{
    envi_t *buff = shell->envi;

    for (; buff && my_strcmp(buff->parts[0], "PATH") != 0;
    buff = buff->next);
    if (!buff)
        use_previous_path(shell);
}

static int parse_line(shell_t *shell)
{
    if (shell->command != NULL)
        free(shell->command);
    shell->command = my_str_to_word_array(shell->line, "\t ");
    CHECK_MALLOC(shell->command, FAILURE);
    if (!shell->command[0])
        return EMPTY_LINE;
    shell->nb_args = len_array(shell->command);
    return 0;
}

int check_shell_args(shell_t *shell)
{
    int exec = 0;

    shell->nb_args = len_array(shell->command);
    is_path_existing(shell);
    exec = is_a_built_in(shell, shell->command[0], true);
    if (exec == NOT_A_BUILTIN)
        exec = check_commands(shell, shell->command[0], true);
    else
        return exec;
    if (exec == 84) {
        shell->shell_status = 1;
        return 84;
    }
    execute_cmd(shell);
    return 0;
}
