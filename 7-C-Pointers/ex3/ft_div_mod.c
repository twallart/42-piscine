/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 21:50:33 by twallart          #+#    #+#             */
/*   Updated: 2026/08/06 10:47:58 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*#include <stdio.h>
int	main(void)
{
	int	test1;
	int	test2;
	int	a;
	int	b;

	a = 12;
	b = 8;
	test1 = 12;
	test2 = 8;
	ft_div_mod(a, b, &test1, &test2);
	printf("a = %d, b = %d, *div = %d, *mod = %d\n", a, b, test1, test2);
}*/
