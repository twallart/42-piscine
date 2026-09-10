/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:00:28 by twallart          #+#    #+#             */
/*   Updated: 2026/08/18 16:57:53 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *str)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int				i;
	t_stock_str		*mystruct;

	mystruct = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!mystruct)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		mystruct[i].size = ft_strlen(av[i]);
		mystruct[i].str = av[i];
		mystruct[i].copy = ft_strcpy(av[i]);
		i++;
	}
	mystruct[i].str = '\0';
	return (mystruct);
}
/*
#include <stdio.h>
int			main(int argc, char *argv[])
{
	struct s_stock_str	*Mystruct;
	int			i;

	Mystruct = ft_strs_to_tab(argc, argv);
	i = 0;
	while (i < argc)
	{
		printf("size = %d\nstr = %s\ncopy = %s\n-----------\n",
		Mystruct[i].size, Mystruct[i].str, Mystruct[i].copy);
		i++;
	}
	return (0);
}
*/
