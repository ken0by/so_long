#include "../include/so_long.h"

static void	press_w(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < ft_slen(game->map.line))
		if (game->map.line[i] == 'P')
			break ;
	if (game->map.line[i - game->map.width] == 'C')
		game->map.n_position++;
	if (game->map.line[i - game->map.width] == 'E'
		&& game->map.n_position == game->map.all_potions)
		ft_win(game);
	if (game->map.line[i - game->map.width] != '1'
		&& game->map.line[i - game->map.width] != 'E')
	{
		game->map.line[i] = '0';
		game->map.line[i - game->map.width] = 'P';
		game->player.steps++;
		game->player.steps_flag = 1;
		print_map(game, 'w');
	}
}

static void	press_s(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < ft_slen(game->map.line))
		if (game->map.line[i] == 'P')
			break ;
	if (game->map.line[i + game->map.width] == 'C')
		game->map.n_position++;
	if (game->map.line[i + game->map.width] == 'E'
		&& game->map.n_position == game->map.all_potions)
		ft_win(game);
	if (game->map.line[i + game->map.width] != '1'
		&& game->map.line[i + game->map.width] != 'E')
	{
		game->map.line[i] = '0';
		game->map.line[i + game->map.width] = 'P';
		game->player.steps++;
		game->player.steps_flag = 1;
		print_map(game, 's');
	}
}

static void	press_d(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < ft_slen(game->map.line))
		if (game->map.line[i] == 'P')
			break ;
	if (game->map.line[i + 1] == 'C')
		game->map.n_position++;
	if (game->map.line[i + 1] == 'E'
		&& game->map.n_position == game->map.all_potions)
		ft_win(game);
	if (game->map.line[i + 1] != '1' && game->map.line[i + 1] != 'E')
	{
		game->map.line[i] = '0';
		game->map.line[i + 1] = 'P';
		game->player.steps++;
		game->player.steps_flag = 1;
		print_map(game, 'd');
	}
}

static void	press_a(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < ft_slen(game->map.line))
		if (game->map.line[i] == 'P')
			break ;
	if (game->map.line[i - 1] == 'C')
		game->map.n_position++;
	if (game->map.line[i - 1] == 'E'
		&& game->map.n_position == game->map.all_potions)
		ft_win(game);
	if (game->map.line[i - 1] != '1' && game->map.line[i + 1] != 'E')
	{
		game->map.line[i] = '0';
		game->map.line[i - 1] = 'P';
		game->player.steps++;
		game->player.steps_flag = 1;
		print_map(game, 'a');
	}
}

int	ft_key(int key, t_game *game)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(EXIT_SUCCESS);
	}
	if (key == KEY_W || key == ARROW_UP)
		press_w(game);
	if (key == KEY_S || key == ARROW_DOWN)
		press_s(game);
	if (key == KEY_D || key == ARROW_RIGHT)
		press_d(game);
	if (key == KEY_A || key == ARROW_LEFT)
		press_a(game);
	return (0);
}
