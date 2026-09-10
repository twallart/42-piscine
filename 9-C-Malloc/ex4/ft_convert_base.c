/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 18:48:01 by twallart          #+#    #+#             */
/*   Updated: 2026/08/24 13:12:38 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		check_base(char *str);
int		check_number(char *nbr, char *str);
int		ft_strlen(char *str);
int		check_sign(char *nbr);
char	*delete_sign(char *str);

int	ft_atoi_base(char *nbr, char *base)
{
	int	i;
	int	j;
	int	nb;

	nbr = delete_sign(nbr);
	i = 0;
	nb = 0;
	while (nbr[i] != '\0')
	{
		j = 0;
		while (base[j] != nbr[i])
			j++;
		nb = nb * ft_strlen(base) + j;
		i++;
	}
	return (nb);
}

int	ft_digits(int nb, char *base)
{
	int	length;
	int	digits;

	digits = 0;
	if (nb < 0)
		nb = -nb;
	length = ft_strlen(base);
	while (nb > 0)
	{
		nb = nb / length;
		digits++;
	}
	return (digits);
}

void	*ft_alloc(int nb_digits, char **dest, int sign)
{
	if (sign == 0)
		*dest = malloc(sizeof(char) * (nb_digits + 1));
	else
		*dest = malloc(sizeof(char) * (nb_digits + 2));
	if (!*dest)
		return (NULL);
	return (*dest);
}

void	*ft_convert(int nb, char *base, char **final, int sign)
{
	int	i;
	int	length;
	int	nb_digits;

	nb_digits = ft_digits(nb, base);
	length = ft_strlen(base);
	i = 0;
	if (sign == 1)
	{
		*final[0] = '-';
		i = 1;
	}
	i += nb_digits - 1;
	while (nb_digits > 0)
	{
		(*final)[i] = base[nb % length];
		nb = nb / length;
		nb_digits--;
		i--;
	}
	if (i == 0)
		(*final)[1 + ft_strlen(*final)] = '\0';
	else
		(*final)[0 + ft_strlen(*final)] = '\0';
	return (NULL);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb_int;
	int		nb_digits;
	int		sign;
	char	*final;

	if (base_from[0] == '\0' || base_to[0] == '\0' || nbr[0] == '\0')
		return (NULL);
	if (check_base(base_from) == 1 || check_base(base_to) == 1)
		return (NULL);
	if (check_number(nbr, base_from) == 1)
		return (NULL);
	sign = check_sign(nbr);
	nb_int = ft_atoi_base(nbr, base_from);
	nb_digits = ft_digits(nb_int, base_to);
	ft_alloc(nb_digits, &final, sign);
	ft_convert(nb_int, base_to, &final, sign);
	return (final);
}

#include <stdio.h>
int	main(void)
{
	char	*result;

	result = ft_convert_base("+-1000", "0123456789", "0123456789abcdef");
	printf("Resultat : %s\n", result);
	return (0);
}
