/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-adrien.raphanaud
** File description:
** intersecting_circles
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "my.h"
#include "my_radar.h"

static float square(float n1)
{
    return n1 * n1;
}

static float max(float n1, float n2)
{
    return n1 > n2 ? n1 : n2;
}

static float min(float n1, float n2)
{
    return n1 < n2 ? n1 : n2;
}

static bool is_circle_rect_intersect(plane_t *pl, tower_t *tw)
{
    sfVector2f circle_center = tw->position;
    sfVector2f square_center = pl->position;
    float top = square_center.y - 10;
    float bot = square_center.y + 10;
    float left = square_center.x - 10;
    float right = square_center.x + 10;
    float closest_x = max(left, min(circle_center.x, right));
    float closest_y = max(top, min(circle_center.y, bot));
    float distance = sqrtf(
        square(closest_x - circle_center.x) +
        square(closest_y - circle_center.y)
    );

    return distance <= tw->radius;
}

static bool check_intersect(float x1, float y1, float x2, float y2)
{
    return
        (x1 + 10.0f >= x2 - 10.0f && x2 + 10.0f >= x1 - 10.0f) &&
        (y1 + 10.0f >= y2 - 10.0f && y2 + 10.0f >= y1 - 10.0f);
}

void is_intersecting(plane_t *plane1, plane_t *plane2)
{
    if (check_intersect(plane1->position.x, plane1->position.y,
        plane2->position.x, plane2->position.y)) {
        plane1->is_dead = true;
        plane2->is_dead = true;
    }
}

bool should_check_collision(plane_t *pl, plane_t *pl2)
{
    if (pl->is_dead || pl2->is_dead)
        return false;
    if (pl->is_safe || pl2->is_safe)
        return false;
    return true;
}

static bool is_plane_in_tower(plane_t *pl, tower_t *tw)
{
    if (is_circle_rect_intersect(pl, tw))
        return true;
    return false;
}

bool is_in_tower_range(plane_t *pl, tower_t *tw)
{
    bool is_plane_safe = false;

    if (pl->is_dead)
        return true;
    for (; tw != NULL && is_plane_safe == false; tw = tw->next) {
        if (tw->id == pl->zone_id)
            is_plane_safe = is_plane_in_tower(pl, tw);
    }
    return is_plane_safe;
}
