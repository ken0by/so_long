/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:49:55 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/10 16:49:57 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_slen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
