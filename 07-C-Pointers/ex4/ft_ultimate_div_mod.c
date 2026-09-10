/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 22:02:25 by twallart          #+#    #+#             */
/*   Updated: 2026/08/06 13:10:58 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = temp / *b;
	*b = temp % *b;
}

/*
#include <stdio.h>
int	main(void)
{
	int	test1;
	int	test2;

	test1 = 12;
	test2 = 8;
	ft_ultimate_div_mod(&test1, &test2);
	printf("*a = %d, *b = %d\n", test1, test2);
}
*/
