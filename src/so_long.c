/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:22:51 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/05 16:23:51 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	start_game(t_game *game, char *file)
{
	game->player.steps = 0;
	game->map.n_position = 0;
	ft_printf("caca\n");
	ft_read_map(game, file);
	/* game->mlx = mlx_init();
	if (!game->mlx)
		ft_error("Failed to open MLX\n");
	game->win = mlx_new_window(game->mlx, game->map.width * 110,
		game->map.height * 110, "Save Rick!");
	if (!game->win)
		ft_error("Failure to load window\n"); */

}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		start_game(&game, argv[1]);
	}

	return (0);
}
