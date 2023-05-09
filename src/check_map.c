/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:59:03 by rodro             #+#    #+#             */
/*   Updated: 2023/05/09 13:48:07 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_check_elements(char *line)
{
	int	i;
	int	e;
	int	c;
	int	p;

	i = 0;
	e = 0;
	c = 0;
	p = 0;
	while (line[i])
	{
		if (line[i] == 'E')
			e++;
		if (line[i] == 'C')
			c = 1;
		if (line[i] == 'P')
			p++;
		i++;
	}
	if (e != 1 || c != 1 || p != 1)
		ft_error("Invalid elements\n");
}

static void	ft_check_diferent(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'E'
			&& line[i] != 'C' && line[i] != 'P')
			ft_error("Found unrecognized element\n");
		i++;
	}
}

static void	ft_check_walls(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (i < ft_slen(line))
	{
		if (i < game->map.width && line[i] != '1')
			ft_error("Map isn't surrounded of walls\n");
		else if ((i % game->map.width == 0 || i % game->map.width
			== game->map.width - 1) && line[i] != '1')
			ft_error("Map isn't surrounded of walls\n");
		else if (i > (ft_slen(line) - game->map.width) && line[i] != '1')
			ft_error("Map isn't surrounded of walls\n");
		i++;
	}
}

void	ft_check_map(t_game *game)
{
	ft_check_elements(game->map.line);
	ft_check_diferent(game->map.line);
	ft_check_walls(game->map.line, game);
	check_path(game);
}
