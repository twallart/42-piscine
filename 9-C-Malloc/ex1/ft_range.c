/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 00:59:35 by twallart          #+#    #+#             */
/*   Updated: 2026/08/12 20:50:16 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	length;
	int	i;
	int	*tab;

	i = 0;
	length = max - min;
	if (length <= 0)
		return (NULL);
	tab = malloc(sizeof(int) * length);
	if (!tab)
		return (NULL);
	if (length <= 0)
		return (tab);
	while (i < length)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}
/*
#include <stdio.h>
int	main(void)
{
	int	*tab;

	tab = ft_range(5, 8);
	printf("Tableau : %d, %d, %d, %d\n", tab[0], tab[1], tab[2], tab[3]);
	return (0);
}
*/
