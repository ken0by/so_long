/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_messeg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:49:18 by rofuente          #+#    #+#             */
/*   Updated: 2023/06/27 13:14:34 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(char *s)
{
	ft_putstr_fd(RED "Error: " RESET, 2);
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd(RESET, 2);
	exit (EXIT_FAILURE);
}

void	ft_win(t_game *game)
{
	ft_putstr_fd(GREEN"\n----------------------", 1);
	ft_putstr_fd("\n¡YOU SAVED PICKLE RICK!\n", 1);
	ft_putstr_fd("----------------------\n"RESET, 1);
	ft_close(game);
	exit(EXIT_SUCCESS);
}

void	ft_lose(t_game *game)
{
	ft_putstr_fd(RED"\n----------------------", 1);
	ft_putstr_fd("\n¡YOU KILLED PICKLE RICK!\n", 1);
	ft_putstr_fd("----------------------\n"RESET, 1);
	ft_close(game);
	exit(EXIT_SUCCESS);
}
