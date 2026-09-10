/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 16:28:49 by twallart          #+#    #+#             */
/*   Updated: 2026/08/18 16:55:21 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"
/*
int			ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char			*ft_strcpy(char *str)
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
	int			i;
	t_stock_str		*Mystruct;

	Mystruct = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!Mystruct)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		Mystruct[i].size = ft_strlen(av[i]);
		Mystruct[i].str = av[i];
		Mystruct[i].copy = ft_strcpy(av[i]);
		i++;
	}
	Mystruct[i].str = '\0';
	return (Mystruct);
}
*/
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_putnbr(int nb)
{
	int	sign;

	sign = 1;
	if (nb < 0)
	{
		nb = -nb;
		sign = -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar('0' + nb % 10);
	return (nb * sign);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}
/*
#include <stdio.h>
int			main(int argc, char *argv[])
{
	struct s_stock_str	*Mystruct;

	Mystruct = ft_strs_to_tab(argc, argv);
	ft_show_tab(Mystruct);
	return (0);
}
*/
