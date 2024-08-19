#include "../include/fractol.h"

// key codes
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define PLUS 69 // on the numeric keypad 
# define MINUS 78

# define SCROLL_UP 4 // zoom out --> augmenting the range
# define SCROLL_DOWN 5 // zoom in --> reducing the range 
# define MOUSE_MOVE 6

# define R 15
# define C 8
# define H 4
# define J 38
# define P 35
# define M 46

/*
KEYCODE VS KEYSYM:
    * keycode = represent a specific key on the keyboard, usually represented by a numeric value
    * keysym (key symbol) = maps specific char/fcts of keys independent of the keyboard layout/hardware specifics 
*/


// on destroy: int (*f)(void *param)
int close_handler(t_fractal *fract) //how to do it for when i go to the X with my mouse !!!!
{
   mlx_destroy_image(fract->mlx_connection, fract->image.image_ptr);
   mlx_destroy_window(fract->mlx_connection, fract->mlx_window);
//    mlx_destroy_display(fract->mlx_connection); // HERE
   free(fract->mlx_connection);
   exit(EXIT_SUCCESS);
}

// keypress: int (*f)(int keycode, void *param)
int key_handler(int keysym, t_fractal *fract)
{
    if (keysym == ESC)
        close_handler(fract);
    else if (keysym == LEFT)
        fract->shift_x += (0.5 * fract->zoom_factor);
    else if (keysym == RIGHT)
        fract->shift_x -= (0.5 * fract->zoom_factor);
    else if (keysym == UP)
        fract->shift_y -= (0.5 * fract->zoom_factor);
    else if (keysym == DOWN)
        fract->shift_y += (0.5 * fract->zoom_factor);
    else if (keysym == PLUS)
        fract->iterations_nbr += 10;
    else if (keysym == MINUS)
        fract->iterations_nbr -= 10;
    fractal_render(fract);
    return (0);
}

// mouse scroll: int (*f)(int button, int x, int y, void *param)
int mouse_handler(int button, int x, int y, t_fractal *fract)
{
    (void)x;
    (void)y;
    if (button == SCROLL_DOWN)
    {
        fract->zoom_factor *= 0.95;
    }
    else if (button == SCROLL_UP)
    {
        fract->zoom_factor *= 1.05;
    }
    fractal_render(fract);
    return (0);
}

// mouse movement (pointer): int (*f)(int x, int y, void *param)
int track_julia(int x, int y, t_fractal *fract)
{
    if (ft_strncmp(fract->name, "julia", 5))
    {
        fract->julia_r = (map(x, -2, 2, 0, WIDTH)) * fract->zoom_factor + fract->shift_x;
        fract->julia_i = (map(y, 2, -2, 0, HEIGHT)) * fract->zoom_factor + fract->shift_y;
    }
    fractal_render(fract);
    return (0);
}