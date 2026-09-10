/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 23:32:19 by twallart          #+#    #+#             */
/*   Updated: 2026/08/06 13:48:19 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;
	int	isordered;

	i = 0;
	j = size - 1;
	isordered = 0;
	while (isordered != 1)
	{
		isordered = 1;
		i = 0;
		while (i < j)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				isordered = 0;
			}
			i++;
		}
	}
}

/*
#include <stdio.h>
int	main(void)
{
	int	tab[6] = {10, 2, 35, 44, 15, 6};

	printf("Tableau de base : %d %d %d %d %d %d\n",
	tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
	ft_sort_int_tab(tab, 6);
	printf("Tableau range : %d %d %d %d %d %d\n",
	tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
	return (0);
}
*/
