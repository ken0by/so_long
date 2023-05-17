/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:49:08 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/17 18:30:54 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	all_potions(t_game *game)
{
	int	i;

	game->map.all_potions = 0;
	i = 0;
	while (game->map.line[i])
	{
		if (game->map.line[i] == 'C')
			game->map.all_potions++;
		i++;
	}
}

static void	ft_cpymap(t_game *game)
{
	int	i;
	int	j;
	int	k;
	int	len;

	game->map.cpy = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!game->map.cpy)
		return ;
	i = 0;
	k = 0;
	while (i < game->map.height)
	{
		len = game->map.width + 1;
		game->map.cpy[i] = ft_calloc(len, sizeof(char));
		if (!game->map.cpy[i])
			return ;
		j = 0;
		while (j < game->map.width)
			game->map.cpy[i][j++] = game->map.line[k++];
		game->map.cpy[i][j] = '\0';
		i++;
	}
}

static void	check_extention(char *file, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(file) - ft_strlen(ext);
	j = 0;
	while (file[i + j] && ext[j])
	{
		if (file[i + j] == ext[j])
			j++;
		else
			ft_error("Map file extetion is not '.ber'\n");
	}
}

static void	check_rectangular(t_game *game)
{
	if (ft_strlen(game->map.line) % game->map.width != 0)
		ft_error("Map not rectangular\n");
}

void	ft_read_map(t_game *game, char *file)
{
	int		fd;
	char	*line;

	check_extention(file, ".ber");
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		ft_error("Failed to open file\n");
	line = get_next_line(fd);
	if (!line)
		ft_error("Empty map\n");
	game->map.height = 0;
	game->map.width = ft_strlen(line) - 1;
	game->map.line = ft_strdup_no_nl(line);
	while (line)
	{
		line = get_next_line(fd);
		game->map.line = ft_strjoin_no_nl(game->map.line, line);
		free (line);
		check_rectangular(game);
		game->map.height++;
	}
	close (fd);
	ft_cpymap(game);
	all_potions(game);
	ft_check_map(game);
}
