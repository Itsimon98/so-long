#include "so_long.h"

    static void *ft_memset(void *b,int c, size_t lenght)
    {
        unsigned char *a;
        a = (unsigned char *)b;
        while(lenght--)
            *a++ = (unsigned char)c;
            return b;
    }
    int exit_point(t_game *game)
    {
        int line;
        line = 0;
        if(game->wind)
        mlx_destroy_window(game->mlx, game->wind);
            free(game->mlx);
            while(line < game->height - 1)
            free(game->map[line++]);
            exit(0);        
        

    }
    int main(int argc, char **argv)
    {
    t_game game;
    
    if(argc != 2)
        return(0);
    
    ft_memset(&game, 0, sizeof(t_game));
    map_reading(&game, argv);
    check_errors(&game);
    game.mlx = mlx_init();
    game.wind = mlx_new_window(game.mlx, (game.width * 40), (game.height * 40) ,"So_long");
    put_image(&game);
    adding_graphics(&game);
    mlx_key_hook(game.wind, control, &game);
    mlx_hook(game.wind, 17, 0, (void*)exit, 0);
    mlx_loop(game.mlx);
    }
