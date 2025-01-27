/*
** EPITECH PROJECT, 2025
** B-MUL-100-STG-1-1-myradar-adrien.raphanaud
** File description:
** kill_dead_planes
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "my.h"
#include "my_radar.h"

void kill_dead_planes(main_t *box, int id)
{
    plane_t *previous = NULL;

    for (plane_t *pl = box->planes[id]; pl; pl = pl->next) {
        if (pl->is_dead) {
            pl = delete_plane(previous, pl, box, id);
            break;
        }
        previous = pl;
    }
}

void destroy_collided_planes(main_t *box)
{
    kill_dead_planes(box, 0);
    kill_dead_planes(box, 1);
    kill_dead_planes(box, 2);
    kill_dead_planes(box, 3);
}
