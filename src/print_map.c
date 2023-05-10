#include "../include/so_long.h"

static void	print_elements(t_game *game, int i, int j, int k)
{
	print_img(game, game->map.floor, j * 100, i * 100);
	if (game->map.line[k] == '1')
		print_img(game, game->map.wall, j * 100, i * 100);
	else if (game->map.line[k] == 'E')
	{
		if (game->map.n_position == game->map.all_positions)
			print_img(game, game->map.portal, j * 100, i * 100);
		else
			print_img(game, game->map.wall, j * 100, i * 100);
	}
	else if (game->map.line[k] == 'C')
		print_img(game, game->map.potion, j * 100, i * 100);
	else
		print_img(game, game->map.floor, j * 100, i * 100);
}

static void	print_player(t_game *game, int i, int j, char c)
{
	if (c == 'w')
		print_img(game, game->player.player_back, j * 100, i * 100);
	else if (c == 's')
		print_img(game, game->player.player_front, j * 100, i * 100);
	else if (c == 'd')
		print_img(game, game->player.player_right, j * 100, i * 100);
	else if (c == 'a')
		print_img(game, game->player.player_left, j * 100, i * 100);
}

void	print_map(t_game *game, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			print_elements(game, i, j, k);
			if (game->map.line[k] == 'P')
				print_player(game, i, j, c);
			k++;
			j++;
		}
		i++;
	}
}
