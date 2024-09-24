#ifndef __LGPL_H
#define __LGPL_H

typedef void (*lgpl_draw_pixel)(int x, int y, unsigned int color);
typedef void (*lgpl_render)();

struct lgpl_implementation {
    unsigned int    screen_width;
    unsigned int    screen_height;
    lgpl_draw_pixel lgpl_draw_pixel;
    lgpl_render     lgpl_render;
};

#endif
