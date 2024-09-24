#ifndef __SEGL_H
#define __SEGL_H

typedef void (*segl_draw_pixel)(int x, int y, unsigned int color);
typedef void (*segl_render)();

/**
 * The struct used by SEGL to know about the display
 * and how to talk to the display.
*/
struct segl_implementation {
    /**
     * Width in pixels of the display.
    */
    unsigned int    screen_width;
    /**
     * Height in pixels of the display.
    */
    unsigned int    screen_height;
    /**
     * Function used to draw a pixel at the specified location and color to the display.
     * If display is 1 color, color=0 is an unlit pixel. color=1 is a lit pixel.
    */
    segl_draw_pixel segl_draw_pixel;
    /**
     * Function used to send all the pending draw commands to the display.
     * If your display impementation sends the pixel to the display as soon
     * as segl_draw_pixel is called, you can leave this function blank.
    */
    segl_render     segl_render;
};

/**
 * A SEGL page stores is a bunch of components at specific locations.
 * When you switch to a SEGL page, all currently drawn components
 * are cleared and the components of the new page are added to the
 * screen and can be interacted with. 
*/
struct segl_page {

};

#endif
