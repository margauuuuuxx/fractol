/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:13:31 by marlonco          #+#    #+#             */
/*   Updated: 2025/06/13 10:19:00 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

// #if defined (__APPLE__)
//     # include "../minilibx/mlx.h"
// #elif defined (__linux__)
#include "../minilibx-linux/mlx.h"
// #else 
//     #error "Unsuported platform"
// #endif 

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define WIDTH 1080
#define HEIGHT 720

// #if defined(__APPLE__)
//     #define ESC 53
//     #define UP 126
//     #define DOWN 125
//     #define LEFT 123
//     #define RIGHT 124

//     #define PLUS_MB 24    // + on main keyboard
//     #define MINUS_MB 27   // - on main keyboard
//     #define PLUS 69       // + on numeric keypad
//     #define MINUS 78      // - on numeric keypad
//     #define C 8

// #elif defined(__linux__)
#define ESC 65307
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363

#define PLUS_MB 61   
#define MINUS_MB 45   
#define PLUS 65451   
#define MINUS 65453   
#define C 99          

// #else
//     #error "Unsupported platform"
// #endif

#define KEY_PRESS 2
#define KEY_RELEASE 3
#define SCROLL_UP 4
#define SCROLL_DOWN 5
#define MOUSE_MOVE 6
#define CLOSE_WINDOW 17

#define BLACK 0x000000
#define WHITE 0xFFFFFF