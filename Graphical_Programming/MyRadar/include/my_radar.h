/*
** EPITECH PROJECT, 2024
** MyRadar_BSv2
** File description:
** my_radar
*/

#ifndef MY_RADAR_H_
    #define MY_RADAR_H_
    #define PI 3.14159265358979323846264338327950288419716939937510582097494459
    #define MAX(a, b) a > b ? a : b
    #define MIN(a, b) a < b ? a : b
    #define CHECK_MALLOC(ptr, retval) if (ptr == NULL) return retval
typedef enum {
    GS_SLOWED,
    GS_NORMAL,
    GS_DOUBLE,
} game_speed_t;

typedef struct tower_s {
    int id;
    sfCircleShape *circle;
    sfVector2f position;
    int radius;
    struct tower_s *next;
} tower_t;

typedef struct plane_s {
    bool is_safe;
    int zone_id;
    bool is_dead;
    sfRectangleShape *hitbox;
    sfVector2f position;
    sfVector2f end;
    sfVector2f move;
    float rotation;
    int speed;
    int delay;
    struct plane_s *next;
} plane_t;

typedef struct main_s {
    plane_t *planes[4];
    tower_t *towers;
    sfTexture *map_texture;
    sfSprite *map_sprite;
    sfTexture *plane_texture;
    sfSprite *plane_sprite;
    sfTexture *tower_texture;
    sfSprite *tower_sprite;
    sfClock *clock;
    game_speed_t game_speed;
    bool disp_hitbox;
    bool disp_sprites;
    float game_time;
    sfFont *font;
    sfText *timer_text;
} main_t;

void process_collisions(plane_t *pl1, plane_t *pl2);
void update_pos_and_collisions(plane_t *pl);
bool is_in_tower_range(plane_t *pl, tower_t *tw);
void free_planes(main_t *box);
void free_tower_list(main_t *box);
bool should_close_window(main_t *box);
void init_l_lists(main_t *box);
int should_return(int ac, char **av);
void print_h(void);
bool should_check_collision(plane_t *pl, plane_t *pl2);
void is_intersecting(plane_t *plane1, plane_t *plane2);
plane_t *safe_next(plane_t *current);
plane_t *delete_plane(plane_t *prev, plane_t *current, main_t *box, int id);
sfRectangleShape *create_rect(sfVector2f position);
bool parse_file(char *path, main_t *box);
sfTexture *create_texture(char *name);
void handle_updates(main_t *box);
void handle_timers(main_t *box);
void handle_events(main_t *plane_container, sfRenderWindow *window);
void handle_display(main_t *plane_container, sfRenderWindow *window);
sfCircleShape *create_circle(sfVector2f position, float radius);
void destroy_collided_planes(main_t *box);
void destroy_sprite(main_t *box);
#endif
