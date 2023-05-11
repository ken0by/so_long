/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:49:18 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/11 14:43:59 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	*start_xpm(t_game *game, char *str)
{
	char	*r;
	void	*img;

	r = ft_strjoin(XPM_PATH, str);
	img = mlx_xpm_file_to_image(game->mlx, r,
			&game->img_width, &game->img_height);
	if (!img)
		ft_error("Failed to load XPM\n");
	free (r);
	return (img);
}

static void	p_xpm(t_game *game)
{
	game->player.player_front = start_xpm(game, "front_stop.xpm");
	game->player.player_back = start_xpm(game, "back_stop.xpm");
	game->player.player_right = start_xpm(game, "right_stop.xpm");
	game->player.player_left = start_xpm(game, "left_stop.xpm");
}

static void	map_xpm(t_game *game)
{
	game->map.wall = start_xpm(game, "wall.xpm");
	game->map.floor = start_xpm(game, "floor.xpm");
	game->map.portal = start_xpm(game, "portal.xpm");
	game->map.potion = start_xpm(game, "potion.xpm");
}

void	all_xpm(t_game *game)
{
	p_xpm(game);
	map_xpm(game);
}

void	print_img(t_game *game, void *img, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win, img, i, j);
}
