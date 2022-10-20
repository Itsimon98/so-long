#include "so_long.h"

void    put_player(t_game *game , int a, int b)
{
    mlx_put_image_to_window(game->mlx, game->wind, b * 40, a *40);
    game->playerfirst = a;
    game->playersecond = b;
}
void    put_collectable(t_game *game, int a, int b);
{
    mlx_put_image_to_window(game->mlx, game->wind, b * 40, a *,40);
}

void put_image(t_game *game)
{
    int i;
    int j;
    game->floor = mlx_xpm_file_to_image(game->mlx, "game_images/floor.xpm", &i, &j);
    game->wall = mlx_xpm_file_to_image(game->mlx, "game_images/wall.xpm", &i, &j);
    game->player = mlx_xpm_file_to_image(game->mlx, "game_images/player.xpm", &i, &j);
    game->collect = mlx_xpm_file_to_image(game->mlx, "game_images/collect.xpm", &i, &j);
    game->exit = mlx_xpm_file_to_image(game->mlx, "game_images/exit.xpm", &i, &j);
}

void    add_graphics(t_game *game, int a, int b)
{
    int height;
    int width;

    game->collectables = 0;
    height = 0;
    while(height < game->height)
    {
        width = 0;
        while(game->map[width][height])
        {
        if(game->map[height][width] == '1')
        mlx_put_image_to_window(game->mlx, game->wind, game->wall, width * 40, height * 40);
        if(game->map[height][width] == 'P')
        put_player(t_game *game, width * 40, height * 40);
        if(game->map[height][width] == 'C')
        put_collectable(t_game *game, width * 40, height * 40);
        if(game->map[height][width] = '0')
        mlx_put_image_to_window(game->mlx, game->wind, game->floor, width * 40, height * 40);
        if(game->map[height][width] = 'E')
        mlx_put_image_to_window(game->mlx, game->wind, game->exit, width * 40, height * 40);
        width++;
        }    
    height++;
    }
    
}