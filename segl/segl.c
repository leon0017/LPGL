#include "segl.h"
#include "segl_impl.h"
#include <util/delay.h>

#define __SEGL_AbsDiff(X, Y)	((X > Y) ? (X - Y) : (Y - X))
#define __SEGL_Swap(X, Y)		do { typeof(X) t = X; X = Y; Y = t; } while (0)

inline void segl_draw_vline(unsigned int y1, unsigned int y2, unsigned int x, unsigned int color) {
	if (y1 > y2) {
		__SEGL_Swap(y1, y2);
	}

	SEGL_SET_PIXELS(x, y1, x, y2, color);
}

inline void segl_draw_hline(unsigned int x1, unsigned int x2, unsigned int y, unsigned int color) {
	if (x1 > x2) {
		__SEGL_Swap(x1, x2);
	}
	
	while (x1 <= x2) {
		SEGL_SET_PIXEL(x1, y, color);
		x1++;
	}
}

void segl_draw_line(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int color) {
	if ((x1 < SEGL_SCREEN_WIDTH) && (x2 < SEGL_SCREEN_WIDTH) &&
	(y1 < SEGL_SCREEN_HEIGHT) && (y2 < SEGL_SCREEN_HEIGHT))
	{
		if (x1 == x2)
		{
			segl_draw_vline(y1, y2, x1, color);
		}
		else if (y1 == y2)
		{
			segl_draw_hline(x1, x2, y1, color);
		}
		else
		{
			unsigned char deltax, deltay, x, y, slope;
			char error, ystep;
			slope = ((__SEGL_AbsDiff(y1, y2) > __SEGL_AbsDiff(x1,x2)) ? 1 : 0);
			if (slope)
			{
				//Swap x1, y1
				__SEGL_Swap(x1, y1);
				//Swap x2, y2
				__SEGL_Swap(x2, y2);
			}
			if (x1 > x2)
			{
				//Swap x1, x2
				__SEGL_Swap(x1, x2);
				//Swap y1,y2
				__SEGL_Swap(y1, y2);
			}
			
			deltax = x2 - x1;
			deltay = __SEGL_AbsDiff(y2, y1);
			error = deltax / 2;
			y = y1;
			ystep = ((y1 < y2) ? 1 : -1);
			
			for (x = x1 ; x <= x2 ; x++)
			{
				if (slope)
				SEGL_SET_PIXEL(y, x, color);
				else
				SEGL_SET_PIXEL(x, y, color);
				
				error -= deltay;
				if (error < 0)
				{
					y = y + ystep;
					error = error + deltax;
				}
			}
		}
	}
}

void segl_draw_rect(const unsigned char x1, const unsigned char y1, const unsigned char x2, const unsigned char y2, unsigned int Color)
{
	if ((x1 < SEGL_SCREEN_WIDTH) && (x2 < SEGL_SCREEN_WIDTH) &&
	(y1 < SEGL_SCREEN_HEIGHT) && (y2 < SEGL_SCREEN_HEIGHT))
	{
		segl_draw_hline(x1, x2, y1, Color);
		segl_draw_hline(x1, x2, y2, Color);
		segl_draw_vline(y1, y2, x1, Color);
		segl_draw_vline(y1, y2, x2, Color);
	}
}

void segl_draw_rounded_rect(const unsigned char x1, const unsigned char y1, const unsigned char x2, const unsigned char y2, const unsigned char Radius, unsigned int Color)
{
	if ((x1<SEGL_SCREEN_WIDTH) && (x2<SEGL_SCREEN_WIDTH) &&
	(y1<SEGL_SCREEN_HEIGHT) && (y2<SEGL_SCREEN_HEIGHT))
	{

		short tSwitch = 3 - 2 * Radius;
		unsigned char width, height, x, y;
		width = x2-x1;
		height = y2-y1;
		x = 0;
		y = Radius;

		//Draw perimeter
		segl_draw_hline(x1+Radius, x2-Radius, y1, Color);	//Top
		segl_draw_hline(x1+Radius, x2-Radius, y2, Color);	//Bottom
		segl_draw_vline(y1+Radius, y2-Radius, x1, Color);	//Left
		segl_draw_vline(y1+Radius, y2-Radius, x2, Color);	//Right
		
		while (x <= y)
		{
			//Upper left corner
			SEGL_SET_PIXEL(x1+Radius-x, y1+Radius-y, Color);
			SEGL_SET_PIXEL(x1+Radius-y, y1+Radius-x, Color);

			//Upper right corner
			SEGL_SET_PIXEL(x1+width-Radius+x, y1+Radius-y, Color);
			SEGL_SET_PIXEL(x1+width-Radius+y, y1+Radius-x, Color);

			//Lower left corner
			SEGL_SET_PIXEL(x1+Radius-x, y1+height-Radius+y, Color);
			SEGL_SET_PIXEL(x1+Radius-y, y1+height-Radius+x, Color);

			//Lower right corner
			SEGL_SET_PIXEL(x1+width-Radius+x, y1+height-Radius+y, Color);
			SEGL_SET_PIXEL(x1+width-Radius+y, y1+height-Radius+x, Color);

			if (tSwitch < 0)
			{
				tSwitch += 4 * x + 6;
			}
			else
			{
				tSwitch += 4 * (x - y) + 10;
				y--;
			}
			x++;
		}
	}
}

void segl_init(void) {
	SEGL_DISPLAY_INIT();
}

// left right=0, up down=!0
int color = 1;
int ballX = 15;
int ballY = 31;
void segl_run_action(int action) {
	switch (action) {
		case SEGL_ACTION_INTERACT:
			SEGL_SET_PIXELS(0, 0, SEGL_SCREEN_WIDTH - 1, SEGL_SCREEN_HEIGHT - 1, 0);
			break;
		case SEGL_ACTION_LEFT:
			ballX--;
			break;
		case SEGL_ACTION_RIGHT:
			ballX++;
			break;
		case SEGL_ACTION_UP:
			ballY--;
			break;
		case SEGL_ACTION_DOWN:
			ballY++;
			break;
	}
}

void segl_draw_step(void) {
	SEGL_SET_PIXEL(ballX, ballY, color);
	SEGL_RENDER();
}

void segl_set_open_page(struct segl_page *segl_page) {
	
}