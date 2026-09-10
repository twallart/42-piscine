/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 22:05:31 by twallart          #+#    #+#             */
/*   Updated: 2026/08/06 10:51:52 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
		i++;
		j--;
	}
}

/*
#include <stdio.h>
int	main(void)
{
	int	tab[6] = {10, 2, 35, 44, 15, 6};

	printf("Tableau de base : %d %d %d %d %d %d\n",
	tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
	ft_rev_int_tab(tab, 6);
	printf("Tableau inverse : %d %d %d %d %d %d\n",
	tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
	return (0);
}
*/
