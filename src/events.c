#include "../include/fractol.h"

// key codes
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define PLUS 69 // on the numeric keypad 
# define MINUS 78

# define SCROLL_UP 4 // zoom in
# define SCROLL_DOWN 5 // zoom out  
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
    else if (keysym == RIGHT)
        fract->limit_x += (0.5 * fract->zoom_factor);
    else if (keysym == LEFT)
        fract->limit_x -= (0.5 * fract->zoom_factor);
    else if (keysym == DOWN)
        fract->limit_y -= (0.5 * fract->zoom_factor);
    else if (keysym == UP)
        fract->limit_y += (0.5 * fract->zoom_factor);
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
    // (void)x;
    // (void)y;
    double  ratio;
    double  lx;
    double  ly;

    ratio = (double)WIDTH / HEIGHT;
    if (button == SCROLL_UP)
    {
        lx = (map(x, -2 * ratio, 2 * ratio, 0, WIDTH) * fract->zoom_factor);
        fract->limit_x += lx;
        ly = (map(y, 2, -2, 0, HEIGHT) * fract->zoom_factor);
        fract->limit_y += ly;
        fract->zoom_factor /= 1.3;
        fractal_render(fract);
    }
    else if (button == SCROLL_DOWN)
    {
        fract->zoom_factor *= 1.05;
        fractal_render(fract);
    }
    return (0);
}

// mouse movement (pointer): int (*f)(int x, int y, void *param)
int track_julia(int x, int y, t_fractal *fract)
{
    if (ft_strncmp(fract->name, "julia", 5))
    {
        fract->julia_r = (map(x, -2, 2, 0, WIDTH)) * fract->zoom_factor + fract->limit_x;
        fract->julia_i = (map(y, 2, -2, 0, HEIGHT)) * fract->zoom_factor + fract->limit_y;
    }
    fractal_render(fract);
    return (0);
}