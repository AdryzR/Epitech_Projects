/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-adrien.raphanaud
** File description:
** updates
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>
#include <math.h>
#include "my.h"
#include "my_radar.h"

static float update_time(main_t *box)
{
    switch (box->game_speed) {
        case GS_NORMAL:
            return 0.0001;
        case GS_DOUBLE:
            return 0.000005;
        case GS_SLOWED:
            return 0.0005;
    }
    return 0.0001;
}

static bool has_reached_end(const plane_t *pl)
{
    return
        pl->end.x - 20.0f <= pl->position.x &&
        pl->position.x <= pl->end.x + 20.0f &&
        pl->end.y - 20.0f <= pl->position.y &&
        pl->position.y <= pl->end.y + 20.0f;
}

plane_t *delete_plane(plane_t *prev, plane_t *current, main_t *box, int id)
{
    plane_t *next = current->next;

    if (prev)
        prev->next = next;
    else
        box->planes[id] = next;
    sfRectangleShape_destroy(current->hitbox);
    free(current);
    return next;
}

plane_t *safe_next(plane_t *current)
{
    return current != NULL ? current->next : NULL;
}

void process_collisions(plane_t *pl1, plane_t *pl2)
{
    for (; pl2; pl2 = safe_next(pl2)) {
        if (pl1 == pl2)
            continue;
        if (should_check_collision(pl1, pl2))
            is_intersecting(pl1, pl2);
    }
}

static int has_left_zone(plane_t *pl)
{
    int idx =
        (int)(pl->position.x * 2 / 1920) +
        ((int)(pl->position.y * 2 / 1080) * 2);

    return idx;
}

static void change_zone(main_t *box, plane_t *prev, plane_t *pl, int id)
{
    plane_t *next = pl->next;

    if (prev)
        prev->next = next;
    else
        box->planes[pl->zone_id] = next;
    pl->next = box->planes[id];
    pl->zone_id = id;
    box->planes[id] = pl;
}

static void update_plane(main_t *box, int id)
{
    plane_t *previous = NULL;
    int new_id = id;

    for (plane_t *pl = box->planes[id]; pl; pl = safe_next(pl)) {
        if (has_reached_end(pl)) {
            delete_plane(previous, pl, box, id);
            pl = previous;
            continue;
        }
        pl->is_safe = is_in_tower_range(pl, box->towers);
        new_id = has_left_zone(pl);
        if (new_id != id) {
            change_zone(box, previous, pl, new_id);
            pl = previous;
            continue;
        }
        if (box->game_time >= pl->delay)
            update_pos_and_collisions(pl);
        previous = pl;
    }
}

void update_planes(main_t *box)
{
    update_plane(box, 0);
    update_plane(box, 1);
    update_plane(box, 2);
    update_plane(box, 3);
}

void handle_updates(main_t *box)
{
    sfTime elapsed = sfClock_getElapsedTime(box->clock);
    float time = sfTime_asSeconds(elapsed);

    box->game_time += time;
    if (time > update_time(box))
        sfClock_restart(box->clock);
    while (time > update_time(box)) {
        handle_timers(box);
        update_planes(box);
        destroy_collided_planes(box);
        time -= update_time(box);
    }
}
