/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** my_exit
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "printf.h"
#include "my_sh.h"

static bool is_alphanumeric(char c)
{
    return (c >= '0' && c <= '9');
}

static int error_numbers(shell_t *shell)
{
    my_putstr_ch(2, "exit: Badly formed number.\n");
    shell->shell_status = 1;
    return 84;
}

static int error_syntax(shell_t *shell)
{
    my_putstr_ch(2, "exit: Expression Syntax.\n");
    shell->shell_status = 1;
    return 84;
}

static int exec_exit(shell_t *shell)
{
    int exit_status = shell->shell_status;

    if (isatty(0) == 1)
        printf("exit\n");
    free_all(shell);
    exit(exit_status);
    return (exit_status);
}

static bool is_arg_int(char *arg)
{
    for (int i = 0; arg[i]; i++)
        if (!is_alphanumeric(arg[i]))
            return false;
    return true;
}

int my_exit(shell_t *shell, int exit_status)
{
    if (exit_status != CURRENT_STATUS)
        shell->shell_status = exit_status;
    if (shell->nb_args == 0)
        return exec_exit(shell);
    if (shell->nb_args == 1)
        return exec_exit(shell);
    if (shell->nb_args > 2)
        return error_syntax(shell);
    if (shell->nb_args == 2 && !is_alphanumeric(*shell->command[1]))
        return error_syntax(shell);
    if (shell->nb_args == 2 && is_arg_int(shell->command[1]) == true) {
        shell->shell_status = my_getnbr(shell->command[1]);
        return exec_exit(shell);
    } else if (shell->nb_args == 2 && is_arg_int(shell->command[1]) == false)
        return error_numbers(shell);
}
