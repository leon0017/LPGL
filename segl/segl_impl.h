#ifndef SEGL_IMPL_H_
#define SEGL_IMPL_H_

#include "segl.h"

/* See segl_impl.c */
void segl_impl_display_init(void);
void segl_impl_set_pixels(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int color);
void segl_impl_set_pixel(unsigned int x, unsigned int y, unsigned int color);
void segl_impl_render(void);

/**
* Width in pixels of the display.
*/
#define SEGL_SCREEN_WIDTH 128
/**
* Height in pixels of the display.
*/
#define SEGL_SCREEN_HEIGHT 64
/**
* Function called by SEGL when initialized to enable the display.
*/
#define SEGL_DISPLAY_INIT segl_impl_display_init
/**
* Function used to fill pixels from x1 to x2, and y1 to y2. Similar to fill rectangle but
* instead, width=x2-x1 and height=y2-y1.
* If display is 1 color, color=0 is an unlit pixel. color=1 is a lit pixel.
*/
#define SEGL_SET_PIXELS segl_impl_set_pixels
/**
* Function used to set a single pixel at the location specified.
* If display is 1 color, color=0 is an unlit pixel. color=1 is a lit pixel.
*/
#define SEGL_SET_PIXEL segl_impl_set_pixel
/**
* Function used to send all the pending draw commands to the display.
* If your display implementation sends the pixel to the display as soon
* as segl_draw_pixel is called, you can leave this function blank.
*/
#define SEGL_RENDER segl_impl_render


#endif