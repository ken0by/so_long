/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_nl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:31:30 by rodro             #+#    #+#             */
/*   Updated: 2023/05/09 13:34:56 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strdup_no_nl(const char *s1)
{
	char	*dst;
	int		x;
	int		j;

	dst = malloc(sizeof(char) * ft_strlen((char *)s1) + 1);
	if (!dst)
	{
		free (dst);
		return (0);
	}
	x = 0;
	j = 0;
	while (s1[x])
	{
		if (s1[x] != '\n')
		{
			dst[j] = s1[x];
			j++;
		}
		x++;
	}
	dst[j] = '\0';
	return (dst);
}

char	*ft_strjoin_no_nl(char *s1, char *s2)
{
	char	*r;
	int		x;
	int		y;

	if (!s2)
		return (s1);
	r = malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2)) + 1);
	if (!r)
		return (NULL);
	x = 0;
	y = 0;
	while (s1[y])
		r[x++] = s1[y++];
	y = 0;
	while (s2[y])
	{
		if (s2[y] != '\n')
			r[x++] = s2[y++];
		else
			y++;
	}
	r[x] = '\0';
	return (r);
}
