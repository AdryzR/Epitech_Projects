/*
** EPITECH PROJECT, 2025
** B-MUL-100-STG-1-1-myradar-adrien.raphanaud
** File description:
** init_planes_towers
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "my.h"
#include "my_radar.h"

void init_l_lists(main_t *box)
{
    box->planes[0] = NULL;
    box->planes[1] = NULL;
    box->planes[2] = NULL;
    box->planes[3] = NULL;
    box->towers = NULL;
}

bool should_close_window(main_t *box)
{
    if (box->planes[0] || box->planes[1] || box->planes[2] || box->planes[3])
        return false;
    return true;
}

void free_tower_list(main_t *box)
{
    tower_t *temp = NULL;

    while (box->towers != NULL) {
        temp = box->towers;
        sfCircleShape_destroy(temp->circle);
        box->towers = box->towers->next;
        free(temp);
    }
}

void free_plane_list(main_t *box, int id)
{
    plane_t *previous = NULL;

    for (plane_t *pl = box->planes[id]; pl; pl = safe_next(pl)) {
        pl = delete_plane(previous, pl, box, id);
        previous = pl;
    }
}

void free_planes(main_t *box)
{
    free_plane_list(box, 0);
    free_plane_list(box, 1);
    free_plane_list(box, 2);
    free_plane_list(box, 3);
}
