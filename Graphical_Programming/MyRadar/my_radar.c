/*
** EPITECH PROJECT, 2024
** MyRadar
** File description:
** my_radar
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "my.h"
#include "my_radar.h"

static sfRenderWindow *create_renderwindow(int x, int y, int bpp, char *title)
{
    sfVideoMode video_mode = {x, y, bpp};

    return sfRenderWindow_create(video_mode, title, sfResize | sfClose, NULL);
}

static void init_bool_and_font(main_t *box)
{
    box->disp_sprites = true;
    box->disp_hitbox = false;
    box->game_speed = GS_NORMAL;
    box->font = sfFont_createFromFile("./assets/arial.ttf");
    box->timer_text = sfText_create();
    sfText_setFont(box->timer_text, box->font);
}

main_t *init_box(void)
{
    main_t *box = malloc(sizeof(main_t));

    box->game_time = 0;
    box->map_texture = create_texture("world_map.jpg");
    box->map_sprite = sfSprite_create();
    sfSprite_setTexture(box->map_sprite, box->map_texture, sfTrue);
    sfSprite_setScale(box->map_sprite, (sfVector2f){2, 1.6});
    box->plane_texture = create_texture("plane.png");
    box->plane_sprite = sfSprite_create();
    sfSprite_setTexture(box->plane_sprite, box->plane_texture, sfTrue);
    sfSprite_setOrigin(box->plane_sprite, (sfVector2f){142.5, 134});
    sfSprite_setScale(box->plane_sprite, (sfVector2f){20.f / 285, 20.f / 268});
    box->tower_texture = create_texture("tower.png");
    box->tower_sprite = sfSprite_create();
    sfSprite_setTexture(box->tower_sprite, box->tower_texture, sfTrue);
    sfSprite_setOrigin(box->tower_sprite, (sfVector2f){236, 256});
    sfSprite_setScale(box->tower_sprite, (sfVector2f){0.2, 0.2});
    init_l_lists(box);
    return box;
}

int close_window(main_t *box, sfRenderWindow *window)
{
    sfRenderWindow_close(window);
    sfRenderWindow_destroy(window);
    free_tower_list(box);
    sfTexture_destroy(box->map_texture);
    sfTexture_destroy(box->plane_texture);
    sfTexture_destroy(box->tower_texture);
    free_planes(box);
    sfClock_destroy(box->clock);
    destroy_sprite(box);
    sfText_destroy(box->timer_text);
    sfFont_destroy(box->font);
    free(box);
    return 0;
}

int main_loop(sfRenderWindow *window, main_t *box)
{
    sfText_setPosition(box->timer_text, (sfVector2f){1800.0, 30.0});
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        handle_events(box, window);
        handle_updates(box);
        if (should_close_window(box) == true)
            return close_window(box, window);
        handle_display(box, window);
    }
    return close_window(box, window);
}

int main(int ac, char **av)
{
    main_t *box = NULL;
    sfRenderWindow *window = NULL;
    int return_value = 0;

    return_value = should_return(ac, av);
    if (return_value != 1)
        return return_value;
    box = init_box();
    init_bool_and_font(box);
    if (!parse_file(av[1], box)) {
        close_window(box, window);
        return 84;
    }
    box->clock = sfClock_create();
    window = create_renderwindow(1920, 1080, 32, "My radar");
    srand(time(0));
    return main_loop(window, box);
}
