/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:49:03 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/10 17:17:49 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_elem(t_game *game, char *path_wall, char *path_floor)
{
	int	i;
	int	j;
	char	*path_player;
/* 	char	*path_portal;
	char	*path_potions; */

	path_player = "../xpm/front_stop.xpm";
	/* path_portal = "../xpm/().xpm";
	path_potions = "../xpm/().xpm"; */
	i = 0;
	while (game->map.cpy[i])
	{
		j = 0;
		while (game->map.cpy[i][j])
		{
			if (game->map.cpy[i][j] == '1')
				game->img = mlx_xpm_file_to_image(game->mlx, path_wall, &(i * game->img_width), &(j * game->img_height));
			if (game->map.cpy[i][j] == '0')
				game->img = mlx_xpm_file_to_image(game->mlx, path_floor, &(i * game->img_width), &(j * game->img_height));
			if (game->map.cpy[i][j] == 'P')
				game->img = mlx_xpm_file_to_image(game->mlx, path_player, &(i * game->img_width), &(j * game->img_height));
			/* if (game->map.cpy[i][j] == 'C')
				game->img = mlx_xpm_file_to_image(game->mlx, path_potions, (i * &game->img_width), (j * &game->img_height));
			if (game->map.cpy[i][j] == 'E')
				game->img = mlx_xpm_file_to_image(game->mlx, path_portal, (i * &game->img_width), (j * &game->img_height)); */
			j++;
		}
		i++;
	}
}
