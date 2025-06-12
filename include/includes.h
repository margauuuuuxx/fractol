/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:13:31 by marlonco          #+#    #+#             */
/*   Updated: 2025/06/12 19:16:48 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

# include "../minilibx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 400

#define ESC 53
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124
#define PLUS 69 // on the numeric keypad
#define MINUS 78

#define KEY_PRESS 2
#define KEY_RELEASE 3
#define SCROLL_UP 4 // zoom in 
#define SCROLL_DOWN 5 // zoom out
#define MOUSE_MOVE 6    // MotionNotify
#define REDRAW 12       // ON_EXPOSE
#define CLOSE_WINDOW 17 // clicking on the x of the window

#define R 15
#define C 8
#define H 4
#define J 38
#define P 35
#define M 46

#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define BRIGHT_WHITE 0xF5F5F5

#define RED 0xFF007F
#define BRIGHT_RED 0xFF3366

#define GREEN 0x00FF7F
#define BRIGHT_GREEN 0x33FF66

#define YELLOW 0xFFFF00
#define BRIGHT_YELLOW 0xFFFF66

#define BLUE 0x7F00FF
#define BRIGHT_BLUE 0x6666FF

#define MAGENTA 0xFF00FF
#define BRIGHT_MAGENTA 0xFF66FF

#define CYAN 0x00FFFF
#define BRIGHT_CYAN 0x66FFFF