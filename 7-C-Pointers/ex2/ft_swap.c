/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 21:35:17 by twallart          #+#    #+#             */
/*   Updated: 2026/08/06 10:40:45 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*
#include <stdio.h>
int	main(void)
{
	int	test1;
	int	test2;

	test1 = 12;
	test2 = 8;
	ft_swap(&test1, &test2);
	printf("*a = %d, *b = %d\n", test1, test2);
}
*/
