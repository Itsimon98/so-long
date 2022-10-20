#include <mlx.h>
#include "so_long.h"

int main()
{
    t_game game;
    game.mlx = mlx_init();
    game.wind = mlx_new_window(game.mlx, game.widht, game.height, "so_long");
    mlx_put_image_to_window(game.mlx, game.wind, );
    mlx_key_hook(game.wind,*ft_keymove, &game);
    mlx_loop_hook(game.mlx,game.wind,  );
    mlx_loop(game.mlx, *ft_update, &game);


}