/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 09:37:48 by twallart          #+#    #+#             */
/*   Updated: 2026/08/18 15:31:51 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
int	ft_difference(int index1, int index2)
{
	return (index1 - index2);
}
*/
int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	order;

	i = 0;
	order = 0;
	while (i < length - 1)
	{
		if (order == 0)
			order = (*f)(tab[i], tab[i + 1]);
		if (order > 0 && (*f)(tab[i], tab[i + 1]) < 0)
			return (0);
		if (order < 0 && (*f)(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	int	result;
	int	tab1[] = {94, 85, 79, 46, 33, 26, 24, 21, 4, 3, -3,
	-32, -41, -51, -71, -78, -95};
	int	tab2[] = {1, 9, 3, 4};

	result = ft_is_sort(tab1, 17, &ft_difference);
	printf("result de tab1 = %d\n", result);
	result = ft_is_sort(tab2, 4, &ft_difference);
	printf("result de tab2 = %d\n", result);
	return (0);
}
*/
