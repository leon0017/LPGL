#include "segl_impl.h"
#include "../../SSD1306.h"

void segl_impl_display_init(void) {
	GLCD_Setup(F_CPU);
}

void segl_impl_set_pixels(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int color) {
	// Don't know why white is black and black is white (SSD1306 lib fault)
	GLCD_SetPixels(x1, y1, x2, y2, (color == 0 ? GLCD_White : GLCD_Black));
}

void segl_impl_set_pixel(unsigned int x, unsigned int y, unsigned int color) {
	GLCD_SetPixel(x, y, (color == 0 ? GLCD_White : GLCD_Black));
}

void segl_impl_render(void) {
	GLCD_Render();
}