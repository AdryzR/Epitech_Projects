/*
** EPITECH PROJECT, 2025
** B-MUL-100-STG-1-1-myradar-adrien.raphanaud
** File description:
** update_pos_and_coll
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>
#include <math.h>
#include "my.h"
#include "my_radar.h"

void update_pos_and_collisions(plane_t *pl)
{
    pl->position.x += pl->move.x * pl->speed / 10000;
    pl->position.y += pl->move.y * pl->speed / 10000;
    sfRectangleShape_setPosition(pl->hitbox, (sfVector2f)
    {pl->position.x, pl->position.y});
    process_collisions(pl, pl->next);
}
