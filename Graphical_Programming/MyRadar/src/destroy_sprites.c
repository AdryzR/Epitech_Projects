/*
** EPITECH PROJECT, 2025
** B-MUL-100-STG-1-1-myradar-adrien.raphanaud
** File description:
** destroy_sprites
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "my.h"
#include "my_radar.h"

void destroy_sprite(main_t *box)
{
    sfSprite_destroy(box->map_sprite);
    sfSprite_destroy(box->tower_sprite);
    sfSprite_destroy(box->plane_sprite);
}
