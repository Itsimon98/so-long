#include "so_long.h"
static int  move(t_game *game, int a, int b)
{
    if(game->map[b][a] == 'E')
        {
            if(game->collectables != 0)
            return(0);
            ft_printf("You Have Won");
            exit_point(game);
        }
    if(game->map[b][a] == '0')
    {
        game->map[b][a] = 'P';
        game->playerfirst = a;
        game->playersecond = b;
        game->counter++;
    }
    if(game->map[b][a] == 'C')
    {
        game->map[b][a] = 'P';
        game->playerfirst = a;
        game->playerfirst = b;
        game->collectables--;
        game->counter++;
    }
    return(1);
}

static int key_w_s(t_game *game, int mov)
{
    int a;
    int b;
    int k;

    a = game->playerfirst;
    b = game->playersecond;

    if(mov == 13)
    {
        a--;
        if(game->map[b][a] == '1')
            return(0);
        k = move(game, a, b);
        if(!k)
        return(0);
        game->map[b + 1][a] = '0';
        }
    else if (mov == 1)
    {
         a++;
         if(game->map[b][a] == '1')
         return(0);
         k = move(game, a, b);
         if(!k)
         return(0);
         game->map[b - 1][a] = '0';
       
    }
    ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Left: %i\n", game->collectables);
	return (1);
}
static  int key_a_d(t_game *game,int mov)
{
    int a;
    int b;
    int k;

    a = game->playerfirst;
    b = game->playersecond;
    if(mov == 0)
    {
        a--;

        if(game->map[b][a] == '1')
        return(0);
        k = move(game, a ,b);
        if(!k)
        return(0);
        game->map[b][a - 1] = '0'; 
    }
    else if(mov == 2)
    {
        a++;
        if(game->map[b][a] == '1')
        return(0);
        k = move(game, a ,b );
        if(!k)
        return(0);
        game->map[b][a + 1] = '0';
    }
    ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Left: %i\n", game->collectables);
    return(1);
}

int control(int comm, t_game *game)
{
    int work;

    if(comm == 53)
    exit_point(game);
    
    if(comm == 13 || comm == 1)
    work = key_w_s(game, comm);

    if(comm == 0 || comm == 2)
    work = key_a_d(game, comm);
    
    if(work)
    adding_graphics(game);
    
    return(1);
}