/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-adrien.raphanaud
** File description:
** create_texture
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "my.h"
#include "my_radar.h"

sfTexture *create_texture(char *name)
{
    sfTexture *texture = NULL;
    char *assets_path = "assets/";
    int asset_path_len = my_strlen(assets_path);
    int name_len = my_strlen(name);
    char *path = malloc(asset_path_len + name_len + 1);

    for (int i = 0; i < asset_path_len; i++)
        path[i] = assets_path[i];
    for (int i = 0; i < name_len; i++)
        path[i + asset_path_len] = name[i];
    path[asset_path_len + name_len] = '\0';
    texture = sfTexture_createFromFile(path, NULL);
    free(path);
    return texture;
}
