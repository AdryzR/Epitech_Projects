/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-adrien.raphanaud
** File description:
** timers
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>
#include <math.h>
#include "my.h"
#include "my_radar.h"
#include <stdint.h>

static char *my_uint_to_str_timer(uint64_t nb)
{
    uint64_t seconds = nb % 60;
    static char str[6] = { '0', '0', ':', '0', '0', '\0' };

    str[0] = '0' + seconds / 60 / 10 % 10;
    str[1] = '0' + seconds / 60 % 10;
    str[3] = '0' + seconds % 60 / 10 % 10;
    str[4] = '0' + seconds % 60 % 10;
    return str;
}

void handle_timers(main_t *box)
{
    char *str = my_uint_to_str_timer((uint64_t)box->game_time);

    sfText_setString(box->timer_text, str);
    return;
}
