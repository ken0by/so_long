/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:22:51 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/18 17:18:55 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_close(t_game *game)
{
	int	i;

	mlx_destroy_window(game->mlx, game->win);
	i = 0;
	while (i < game->map.height)
	{
		free (game->map.cpy[i]);
		i++;
	}
	free (game->map.cpy);
	free (game->map.line);
	return (0);
}

static int	ft_loop(t_game *game)
{
	print_steps(game);
	return (0);
}

static void	start_game(t_game *game, char *file)
{
	game->player.steps = 0;
	game->map.n_potions = 0;
	ft_read_map(game, file);
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error("Failed to open MLX\n");
	game->win = mlx_new_window(game->mlx, game->map.width * 110,
			game->map.height * 110, "Save Pickle Rick!");
	if (!game->win)
		ft_error("Failure to load window\n");
	all_xpm(game);
	print_map(game, 's');
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		start_game(&game, argv[1]);
		mlx_hook(game.win, DESTROY, 0, ft_close, &game);
		mlx_key_hook(game.win, ft_key, &game);
		mlx_loop_hook(game.mlx, &ft_loop, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}
