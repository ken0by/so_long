/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:30:13 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/15 20:55:19 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_close(char *line, int fd)
{
	free (line);
	close (fd);
}

void	ft_free_matrix(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		free (game->map.cpy[i]);
		i++;
	}
	free (game->map.cpy);
}
