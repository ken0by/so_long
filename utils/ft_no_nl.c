/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_nl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:49:47 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/18 17:09:04 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* char	*ft_strdup_no_nl(char *s1)
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
	//free (s1);
	return (dst);
}

char	*ft_strjoin_no_nl(char *s1, char *s2)
{
	char	*r;
	int		x;
	int		y;

	if(!s1 && !s2)
		return (NULL);
	else if (!s1 || !s2)
	{
		r =ft_strdup_no_nl(s1);
		free (s1);
		free (s2);
		return (r);
	}
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
	free (s1);
	free (s2);
	return (r);
} */

char	*ft_strdup_no_nl(char *s)
{
	char	*new_mem;
	int		size;
	int		i;

	new_mem = NULL;
	size = ft_strlen(s);
	i = 0;
	new_mem = malloc(size + 1);
	if (!(new_mem))
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		new_mem[i] = s[i];
		i++;
	}
	new_mem[i] = '\0';
	return (new_mem);
}

static int	ft_strlcpy_no_nl(char *dst, char *src, int len)
{
	int	src_len;
	int	i;

	src_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	if (len == 0)
	{
		return (src_len);
	}
	while (i < len - 1 && *src && *src != '\n')
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	return (src_len);
}

char	*ft_strjoin_no_nl(char *s1, char *s2)
{
	char	*new_mem;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL || s2 == NULL)
	{
		new_mem = ft_strdup_no_nl(s1);
		free(s1);
		free(s2);
		return (new_mem);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_mem = malloc(s1_len + s2_len);
	if (!(new_mem))
		return (NULL);
	ft_strlcpy_no_nl(new_mem, s1, s1_len + 1);
	ft_strlcpy_no_nl(new_mem + s1_len, s2, s2_len + 1);
	free(s1);
	free(s2);
	return (new_mem);
}
