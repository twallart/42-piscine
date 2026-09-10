/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 00:40:08 by twallart          #+#    #+#             */
/*   Updated: 2026/08/12 18:55:33 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	length;
	int	i;
	int	*tab;

	if (!range)
		return (-1);
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	length = max - min;
	tab = malloc(sizeof(int) * length);
	if (tab == NULL)
		return (-1);
	while (i < length)
	{
		tab[i] = min;
		min++;
		i++;
	}
	*range = tab;
	return (length);
}
/*
#include <stdio.h>
int	main(void)
{
	int	*tab;

	ft_ultimate_range(&tab, 5, 8);
	printf("Tableau : %d, %d, %d, %d\n", tab[0], tab[1], tab[2], tab[3]);
	return (0);
}
*/
