#include "../include/so_long.h"

static void	ft_steps(t_game *game)
{
	ft_putstr_fd("Steps: ", 1);
	ft_putnbr_fd(game->player.steps, 1);
	ft_putchar_fd('\n', 1);
	game->player.steps_flag = 0;
}

static void	win_steps(t_game *game)
{
	char	*s;

	s = ft_itoa(game->player.steps);
	mlx_string_put(game->mlx, game->win, 33, 23, 0xFFFFFF, s);
	free (s);
}

void	print_steps(t_game *game)
{
	if (game->player.steps_flag)
		ft_steps(game);
	win_steps(game);
}
