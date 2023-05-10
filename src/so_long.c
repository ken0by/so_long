/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:22:51 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/10 17:13:32 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	start_game(t_game *game, char *file)
{
	game->player.steps = 0;
	game->map.n_position = 0;
	ft_read_map(game, file);
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error("Failed to open MLX\n");
	game->win = mlx_new_window(game->mlx, game->map.width * 110,
		game->map.height * 110, "Save Pickle Rick!");
	if (!game->win)
		ft_error("Failure to load window\n");
	mlx_loop(game->mlx);
}

static void	init_elements(t_game *game)
{
	char	*path_wall;
	char	*path_floor;

	path_wall = "../xpm/wall.xpm";
	path_floor = "../xpm/floor.xpm";
	game->img_height = 50;
	game->img_width = 50;
	put_elem(game, path_wall, path_floor);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		start_game(&game, argv[1]);
		init_elements(&game);
	}

	return (0);
}
