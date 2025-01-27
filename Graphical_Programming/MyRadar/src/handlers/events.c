/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-adrien.raphanaud
** File description:
** events
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>
#include <math.h>
#include "my.h"
#include "my_radar.h"

void handle_events(main_t *box, sfRenderWindow *window)
{
    sfEvent event = {};

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeyD)
            box->game_speed = MIN(GS_DOUBLE, (int)box->game_speed + 1);
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeyF)
            box->game_speed = MAX(GS_SLOWED, (int)box->game_speed - 1);
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeyL)
            box->disp_hitbox = !box->disp_hitbox;
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeyS)
            box->disp_sprites = !box->disp_sprites;
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeyP) {
            sfSprite_scale(box->plane_sprite, (sfVector2f){2, 2});
        }
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeyO) {
            sfSprite_scale(box->plane_sprite, (sfVector2f){0.5, 0.5});
        }
    }
}
