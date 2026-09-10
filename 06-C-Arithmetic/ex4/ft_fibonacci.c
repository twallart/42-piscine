/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:00:03 by twallart          #+#    #+#             */
/*   Updated: 2026/08/05 11:25:21 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	if (index == 2)
		return (1);
	if (index == 3)
		return (2);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

/*
int	main(void)
{
	int	result;

	result = ft_fibonacci(4);
	printf("Resultat fibonacci de 4 : %d\n", result);
	result = ft_fibonacci(8);
	printf("Resultat fibonacci de 8 : %d\n", result);
	result = ft_fibonacci(15);
	printf("Resultat fibonacci de 15 : %d\n", result);
	return (0);
}
*/
