/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 16:37:47 by twallart          #+#    #+#             */
/*   Updated: 2026/08/09 16:40:26 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

char	get_char(int i, int j, int x, int y)
{
	if (i == 0)
	{
		if (j == 0 || j == x - 1)
			return ('A');
		return ('B');
	}
	if (i == y - 1)
	{
		if (j == 0 || j == x - 1)
			return ('C');
		return ('B');
	}
	if (j == 0 || j == x - 1)
		return ('B');
	return (' ');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	if (x <= 0 || y <= 0)
	{
		write(1, "ERROR!\n", 7);
		return ;
	}
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_putchar(get_char(i, j, x, y));
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
