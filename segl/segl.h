#ifndef SEGL_H_
#define SEGL_H_

typedef void (*segl_display_init)(void);
typedef void (*segl_set_pixels)(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int color);
typedef void (*segl_set_pixel)(unsigned int x, unsigned int y, unsigned int color);
typedef void (*segl_render)(void);

/* SEGL actions */
#define SEGL_ACTION_INTERACT    0  // Such as clicking a button
#define SEGL_ACTION_LEFT_UP     1  // Moving to the component on the left or up
#define SEGL_ACTION_RIGHT_DOWN  2  // Moving to the component on the right or down
#define SEGL_ACTION_LEFT        3  // Moving to the component on the left
#define SEGL_ACTION_RIGHT       4  // Moving to the component on the right
#define SEGL_ACTION_UP          5  // Moving to the component above
#define SEGL_ACTION_DOWN        6  // Moving to the component below

/**
 * A SEGL page stores a bunch of components at specific locations.
 * When you switch to a SEGL page, all currently drawn components
 * are cleared and the components of the new page are added to the
 * screen and can be interacted with. 
*/
struct segl_page {

};

/**
 * Called to initialize SEGL.
 * Must be called before using any other SEGL functions.
*/
void segl_init(void);

/**
 * Runs the specified action when called.
 * Current actions:
 *  - SEGL_ACTION_INTERACT
 *  - SEGL_ACTION_LEFT_UP
 *  - SEGL_ACTION_RIGHT_DOWN
*/
void segl_run_action(int action);

/**
 * Should be called in a loop to step the drawing process
*/
void segl_draw_step(void);

/**
 * Called to move to another page.
*/
void segl_set_open_page(struct segl_page *segl_page);

#endif
