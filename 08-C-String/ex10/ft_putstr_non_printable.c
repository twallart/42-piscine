/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 09:47:43 by twallart          #+#    #+#             */
/*   Updated: 2026/08/08 23:16:30 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_hex(int nb)
{
	if (nb >= 16)
		ft_putnbr_hex(nb / 16);
	if (nb % 16 < 10)
		ft_putchar('0' + nb % 16);
	if (nb % 16 == 10)
		ft_putchar('a');
	if (nb % 16 == 11)
		ft_putchar('b');
	if (nb % 16 == 12)
		ft_putchar('c');
	if (nb % 16 == 13)
		ft_putchar('d');
	if (nb % 16 == 14)
		ft_putchar('e');
	if (nb % 16 == 15)
		ft_putchar('f');
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= ' ' && str[i] <= '~')
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			if (str[i] <= 15)
				ft_putchar('0');
			ft_putnbr_hex(str[i]);
		}
		i++;
	}
}
/*
int	main(void)
{
	ft_putstr_non_printable("Hello\nHow\t are you ?");
	return (0);
}*/
