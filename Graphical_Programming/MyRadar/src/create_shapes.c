/*
** EPITECH PROJECT, 2024
** MyRadar_BSv2
** File description:
** create_circles
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "my.h"
#include "my_radar.h"

sfRectangleShape *create_rect(sfVector2f position)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setSize(shape, (sfVector2f){20.0, 20.0});
    sfRectangleShape_setFillColor(shape, sfTransparent);
    sfRectangleShape_setOutlineThickness(shape, 2);
    sfRectangleShape_setOutlineColor(shape, sfBlack);
    sfRectangleShape_setPosition(shape, (sfVector2f){position.x - 10.0,
    position.y - 10.0 });
    return shape;
}

sfCircleShape *create_circle(sfVector2f position, float radius)
{
    sfCircleShape *shape = sfCircleShape_create();

    sfCircleShape_setRadius(shape, radius);
    sfCircleShape_setFillColor(shape, sfTransparent);
    sfCircleShape_setOutlineThickness(shape, 2);
    sfCircleShape_setOutlineColor(shape, sfWhite);
    sfCircleShape_setPosition(shape, position);
    sfCircleShape_setOrigin(shape, (sfVector2f){radius, radius});
    return shape;
}
