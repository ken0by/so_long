/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:16:28 by rodro             #+#    #+#             */
/*   Updated: 2023/05/05 16:07:41 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_move(char **cpy, int i, int j)
{
	if (cpy[i][j] == 'P' && (cpy[i + 1][j] == 'C' || cpy[i + 1][j] == '0'
		|| cpy[i - 1][j] == 'C' || cpy[i - 1][j] == '0'
		|| cpy[i][j + 1] == 'C' || cpy[i][j + 1] == '0'
		|| cpy[i][j - 1] == 'C' || cpy[i][j - 1] == '0'))
		return (1);
	return (0);
}

static void	fill(t_game *game, int i, int j)
{
	if(game->map.cpy[i][j] == '0' || game->map.cpy[i][j] == 'C')
		game->map.cpy[i][j] = 'P';
}

static int	check_collectibles(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.cpy[i][j] == 'C')
				ft_error("Unable to reach all collectables\n");
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_scape(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if ((game->map.cpy[i][j] == 'E' && game->map.cpy[i + 1][j] == 'P')
				|| (game->map.cpy[i][j] == 'E' && game->map.cpy[i - 1][j] == 'P')
				|| (game->map.cpy[i][j] == 'E' && game->map.cpy[i][j + 1] == 'P')
				|| (game->map.cpy[i][j] == 'E' && game->map.cpy[i][j - 1] == 'P'))
				return (1);
			j++;
		}
		i++;
	}
	ft_error("Unable to find a valid path\n");
	return (0);
}

int	check_path(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (check_move(game->map.cpy, i, j) == 1)
			{
				fill(game, i + 1, j);
				fill(game, i - 1, j);
				fill(game, i, j + 1);
				fill(game, i, j - 1);
				i = 0;
			}
			j++;
		}
		i++;
	}
	if (check_collectibles(game) == 1 && check_scape(game) == 1)
		return (1);
	return (0);
}
