/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 22:24:27 by twallart          #+#    #+#             */
/*   Updated: 2026/08/12 22:22:54 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	check_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = i;
		if (str[i] == '+' || str[i] == '-' || str[i] == ' ')
			return (1);
		while (str[j] != '\0')
		{
			if (str[i] == str[j + 1])
				return (1);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (1);
	return (0);
}

int	check_number(char *nbr, char *str)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	if (nbr[0] == '-')
		i++;
	while (nbr[i] != '\0')
	{
		j = 0;
		found = 0;
		while (str[j] != '\0')
		{
			if (nbr[i] == str[j])
				found = 1;
			j++;
		}
		if (found == 0)
			return (1);
		if (nbr[i] == '-' || nbr[i] == '+' || nbr[i] == ' '
			|| (nbr[i] >= '9' && nbr[i] <= 13))
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_sign(char *nbr)
{
	int	sign;

	sign = 0;
	if (nbr[0] == '-')
		sign = 1;
	return (sign);
}

char	*delete_sign(char *str)
{
	int		i;
	int		j;
	int		length;
	char	*dest;

	i = 0;
	length = ft_strlen(str);
	while ((str[i] == '-' || str[i] == '+') && str[i] != '\0')
		i++;
	dest = malloc(sizeof(char) * (length - i + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (str[i] != '\0')
	{
		dest[j] = str[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
