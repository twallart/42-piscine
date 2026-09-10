/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 22:44:47 by twallart          #+#    #+#             */
/*   Updated: 2026/08/05 12:44:54 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_display(char i1, char i2, char i3)
{
	i1 = '0' + i1;
	i2 = '0' + i2;
	i3 = '0' + i3;
	write(1, &i1, 1);
	write(1, &i2, 1);
	write(1, &i3, 1);
	if (i1 == '7' && i2 == '8' && i3 == '9')
		return ;
	else
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	ft_print_comb(void)
{
	int	i1;
	int	i2;
	int	i3;

	i1 = 0;
	i2 = 1;
	i3 = 2;
	while (i1 <= 7)
	{
		i2 = i1 + 1;
		while (i2 <= 8)
		{
			i3 = i2 + 1;
			while (i3 <= 9)
			{
				ft_display(i1, i2, i3);
				i3++;
			}
			i2++;
		}
		i1++;
	}
	return ;
}

/*
int	main(void)
{
	ft_print_comb();
	return (0);
}
*/
