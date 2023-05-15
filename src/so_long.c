/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:22:51 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/15 21:27:32 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_free_lst(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		free (game->map.cpy[i]);
		i++;
	}
	free (game->map.cpy);
	free (game->map.line);
}

int	ft_close(t_game *game)
{
	//int i;

	mlx_destroy_window(game->mlx, game->win);
	/* i = 0;
	while (i < game->map.height)
	{
		ft_printf("%p\n", game->map.cpy[i]);
		i++;
	}
	ft_printf("%p\n", game->map.line); */
	ft_free_lst(game);
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

void	ft_leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_game	game;

	atexit(ft_leaks);
	if (argc == 2)
	{
		start_game(&game, argv[1]);
		mlx_hook(game.win, DESTROY, 0, ft_close, &game);
		mlx_key_hook(game.win, ft_key, &game);
		mlx_loop_hook(game.mlx, &ft_loop, &game);
		mlx_loop(game.mlx);
	}
	//ft_free_matrix(&game);
	return (0);
}
