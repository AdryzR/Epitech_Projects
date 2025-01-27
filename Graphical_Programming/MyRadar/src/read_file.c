/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-adrien.raphanaud
** File description:
** read_file
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

static sfVector2f vector_normalized(sfVector2f vector)
{
    float norm = sqrtf(vector.x * vector.x + vector.y * vector.y);

    return (sfVector2f) {
        vector.x / norm,
        vector.y / norm
    };
}

bool parse_plane(main_t *box, int id, int values[])
{
    plane_t *plane = malloc(sizeof(plane_t));

    CHECK_MALLOC(plane, false);
    plane->zone_id = id;
    plane->is_safe = true;
    plane->is_dead = false;
    plane->hitbox = create_rect((sfVector2f){values[0], values[1]});
    plane->position = (sfVector2f){values[0], values[1]};
    plane->end = (sfVector2f){values[2], values[3]};
    plane->speed = values[4];
    plane->delay = values[5];
    plane->move = vector_normalized((sfVector2f){
        values[2] - values[0], values[3] - values[1]});
    plane->rotation = atan2(values[3] - values[1],
    values[2] - values[0]) * (180.0f / PI);
    plane->next = box->planes[id];
    box->planes[id] = plane;
    return true;
}

bool parse_tower(char **data, main_t *box)
{
    int values[3] = {0};
    tower_t *tower = malloc(sizeof(tower_t));

    CHECK_MALLOC(tower, false);
    for (size_t i = 0; data[i]; i++)
        values[i] = my_getnbr(data[i]);
    *tower = (tower_t){
        .circle = create_circle((sfVector2f){values[0], values[1]}, values[2]),
        .position = {values[0], values[1]},
        .radius = values[2],
        .next = box->towers,
        .id = (int)(values[0] * 2 / 1920) + ((int)(values[1] * 2 / 1080) * 2)
    };
    box->towers = tower;
    return true;
}

bool select_plane_list(char **data, main_t *box)
{
    bool return_value = false;
    int values[6] = {0};
    int id = -1;

    for (size_t i = 0; data[i]; i++)
        values[i] = my_getnbr(data[i]);
    id = (int)(values[0] * 2 / 1920) + ((int)(values[1] * 2 / 1080) * 2);
    return_value = parse_plane(box, id, values);
    return return_value;
}

bool parse_lines(char *line, main_t *box)
{
    bool return_value = false;
    char **line_data = my_str_to_word_array(line, ' ');

    if (len_array(line_data) == 7 && line[0] == 'A')
        return_value = select_plane_list(line_data + 1, box);
    if (len_array(line_data) == 4 && line[0] == 'T')
        return_value = parse_tower(line_data + 1, box);
    for (size_t i = 0; line_data[i]; i++)
        free(line_data[i]);
    free(line_data);
    return return_value;
}

static int check_file_path(FILE *file)
{
    if (file == NULL) {
        my_putstr(2, "File path is not found or incorrect. Use ./my_radar -h"
        " for programm usage indications.\n");
        return 84;
    }
    return 0;
}

bool parse_file(char *path, main_t *box)
{
    FILE *file = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;
    int getline_result = 0;

    if (check_file_path(file) == 84)
        return false;
    while (true) {
        getline_result = getline(&line, &len, file);
        if (getline_result == -1)
            break;
        if (!parse_lines(line, box)) {
            free(line);
            fclose(file);
            return false;
        }
    }
    free(line);
    fclose(file);
    return true;
}
