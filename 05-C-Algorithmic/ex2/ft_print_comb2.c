/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:24:35 by twallart          #+#    #+#             */
/*   Updated: 2026/08/06 17:38:21 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_putnbr(int nb)
{
	int	temp;
	int	decimal;

	decimal = 1;
	if (nb == -2147483648)
		ft_putstr("-2147483648");
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	temp = nb;
	while (temp > 9)
	{
		temp = temp / 10;
		decimal = decimal * 10;
	}
	while (decimal > 0)
	{
		ft_putchar('0' + nb / decimal);
		nb = nb % decimal;
		decimal = decimal / 10;
	}
}

void	ft_print_comb2(void)
{
	int	i1;
	int	i2;

	i1 = 0;
	while (i1 < 99)
	{
		i2 = i1 + 1;
		while (i2 < 100)
		{
			if (i1 < 10)
				ft_putchar('0');
			ft_putnbr(i1);
			ft_putchar(' ');
			if (i2 < 10)
				ft_putchar('0');
			ft_putnbr(i2);
			if (!(i1 == 98 && i2 == 99))
				ft_putstr(", ");
			i2++;
		}
		i1++;
	}
	return ;
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
