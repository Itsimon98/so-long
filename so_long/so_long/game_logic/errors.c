#include "so_long.h"

static int    xwall(t_game * game)
{
    int a;
    int b;

    a = game->height;
    b = 0;
    while(b < a)
    {
        if(game->map[b][a] == '1' && game->map[game->height-1][b] == '1' )
        return(0);
        b++;
    }
    return(1);
}

static int    ywall(t_game *game)
{
    int a;
    int b;

    a = game->width;
    b = 0;

    while(b < a)
    {
        if(game->map[b][0] == '1' && game->map[b][game->width - 1])
        return(0);
        b++;
    }
    return(1);
}
static void	if_walls(t_game *game)
{
	int	verticalwalls;
	int	horizontalwalls;

	verticalwalls = ywall(game);
	horizontalwalls = xwall(game);
	if (!verticalwalls || !horizontalwalls)
	{
		printf("\e[31m\e[1mError\nThis map is missing the walls\e[0m \n");
		exit_point(game);
	}
}

static void	count_checker(t_game *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		printf("\e[31m\e[1mError\nError Here!%c\n", game->map[height][width]);
		exit_point(game);
	}
	if (game->map[height][width] == 'C')
			game->columncount++;
	if (game->map[height][width] == 'P')
			game->playercount++;
	if (game->map[height][width] == 'E')
			game->exitcount++;
}

void	character_valid(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->height - 1)
	{
		width = 0;
		while (width <= game->width)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->playercount == 1 && game->columncount > 1
			&& game->exitcount == 1))
	{
		printf("\e[31m\e[1mError\n Something is wrong,");
		printf("either player, exit or collectable issue \e[0m \n");
		exit_point(game);
	}
}

void	check_errors(t_game *game)
{
	if_walls(game);
	character_valid(game);
}
