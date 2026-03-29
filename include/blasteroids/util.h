#ifndef _BLASTEROIDS_UTIL_H
#define _BLASTEROIDS_UTIL_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <signal.h>

/* util_draw declarations */
float deg2rad(float deg);
float blasteroids_get_delta_x(float speed, float degrees);
float blasteroids_get_delta_y(float speed, float degrees);
float blasteroids_get_distance(float ax, float ay, float bx, float by);
float al_draw_line_scaled(float ax, float ay, float bx, float by, ALLEGRO_COLOR color, float thickness, float scale);

#define al_draw_line_scaled(ax, ay, bx, by, color, thick, scale) \
    al_draw_line(ax*scale, ay*scale, bx*scale, by*scale, color, thick)

/* util_log declarations */
void debug(char *message, ...);
void error(char *message, ...);
void info(char *message, ...);

/* util_rand declarations */
int randomize(int max);
ALLEGRO_COLOR blasteroids_rand_color();

/* util_signal declarations */
int catch_signal(int sig, void(*handler)(int));

#endif
