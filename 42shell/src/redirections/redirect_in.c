/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** redirect_in
*/

#include <my_sh.h>
#include <fcntl.h>
#include <parser.h>
#include <errno.h>

int make_redirect_in(shell_t *shell, char *filename)
{
    int file_fd = 0;
    int saved_stdin = dup(STDIN);

    file_fd = open(filename, O_RDONLY, 0664);
    if (file_fd < 0) {
        dprintf(2, "%s: %s.\n", filename, strerror(errno));
        return 84;
    }
    dup2(file_fd, STDIN);
    close(file_fd);
    return 0;
}
