/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-adrien.raphanaud
** File description:
** display
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>
#include <math.h>
#include "my.h"
#include "my_radar.h"

void update_sprites_and_hitboxes(main_t *box, plane_t *pl)
{
    sfSprite_setPosition(box->plane_sprite, pl->position);
    sfSprite_setRotation(box->plane_sprite, pl->rotation);
    sfRectangleShape_setRotation(pl->hitbox, pl->rotation);
    sfRectangleShape_setOrigin(pl->hitbox, (sfVector2f){10, 10});
}

void display_planes(main_t *box, sfRenderWindow *window, int id)
{
    for (plane_t *pl = box->planes[id]; pl != NULL; pl = pl->next) {
        update_sprites_and_hitboxes(box, pl);
        if (box->disp_sprites == true && box->game_time >= pl->delay)
            sfRenderWindow_drawSprite(window, box->plane_sprite, NULL);
        if (box->disp_hitbox == true && box->game_time >= pl->delay)
            sfRenderWindow_drawRectangleShape(window, pl->hitbox, NULL);
    }
}

void handle_display(main_t *box, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, box->map_sprite, NULL);
    for (tower_t *tw = box->towers; tw != NULL; tw = tw->next) {
        sfSprite_setPosition(box->tower_sprite, tw->position);
        if (box->disp_sprites == true)
            sfRenderWindow_drawSprite(window, box->tower_sprite, NULL);
        if (box->disp_hitbox == true)
            sfRenderWindow_drawCircleShape(window, tw->circle, NULL);
    }
    display_planes(box, window, 0);
    display_planes(box, window, 1);
    display_planes(box, window, 2);
    display_planes(box, window, 3);
    sfRenderWindow_drawText(window, box->timer_text, NULL);
    sfRenderWindow_display(window);
}
