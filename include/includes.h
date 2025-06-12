/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:13:31 by marlonco          #+#    #+#             */
/*   Updated: 2025/06/12 21:48:32 by marlonco         ###   ########.fr       */
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
#define PLUS_MB 24 
#define MINUS_MB 27
#define PLUS 69 // on the numeric keypad
#define MINUS 78
#define C 8

#define KEY_PRESS 2
#define KEY_RELEASE 3
#define SCROLL_UP 4 // zoom in 
#define SCROLL_DOWN 5 // zoom out
#define MOUSE_MOVE 6    // MotionNotify
#define CLOSE_WINDOW 17 // clicking on the x of the window

#define BLACK 0x000000
#define WHITE 0xFFFFFF