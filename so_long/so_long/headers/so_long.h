#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line.h"

typedef struct s_game{
int     fd;
void    *mlx;
void    *wind;
char    **map;
int     height;
int     width;
int     playercount;
int     columncount;
int     collectables;
int     playerfirst;
int     playersecond;
int     counter;
int exitcount;
void *player;
void *collect;
void *wall;
void *floor;
void *exit;
}t_game;
int exit_point(t_game *game);
int map_reading(t_game *game, char **argv);
int control(int keycomm, t_game *game);
void adding_graphics(t_game *game);
void put_image(t_game *game);
void    check_errors(t_game *game);
#endif