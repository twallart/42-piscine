/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 22:02:57 by twallart          #+#    #+#             */
/*   Updated: 2026/08/05 14:21:00 by twallart         ###   ########.fr       */
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

void	ft_display(int nb, int decimal)
{
	while (decimal > 0)
	{
		ft_putchar('0' + nb / decimal);
		nb = nb % decimal;
		decimal = decimal / 10;
	}
}

void	ft_putnbr(int nb)
{
	int	temp;
	int	decimal;

	decimal = 1;
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
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
	ft_display(nb, decimal);
}

/*
int	main(void)
{
	ft_putnbr(45);
	ft_putchar('\n');
	ft_putnbr(-65789);
	ft_putchar('\n');
	ft_putnbr(0);
	ft_putchar('\n');
	ft_putnbr(-2147483648);
	ft_putchar('\n');
	return (0);
}
*/
