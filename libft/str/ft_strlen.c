/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:07:02 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/08 12:14:07 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlen(const char *str)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

// int main(int ac, char **av)
// {
//     if (ac != 2)
//         return (0);
//     printf("%lu\n", strlen(av[1]));
//     printf("%d\n", ft_strlen(av[1]));
//     return (0);
// }
