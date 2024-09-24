#ifndef __SEGL_H
#define __SEGL_H

typedef void (*segl_draw_pixel)(int x, int y, unsigned int color);
typedef void (*segl_render)();

struct segl_implementation {
    unsigned int    screen_width;
    unsigned int    screen_height;
    segl_draw_pixel segl_draw_pixel;
    segl_render     segl_render;
};

#endif
