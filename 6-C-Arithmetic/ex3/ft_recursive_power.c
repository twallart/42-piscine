/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 10:48:21 by twallart          #+#    #+#             */
/*   Updated: 2026/08/05 17:55:06 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power > 1)
		return (result * ft_recursive_power(nb, power - 1));
	return (result);
}

/*
int	main(void)
{
	int	result;

	result = ft_recursive_power(6, 5);
	printf("Resultat : %d\n", result);
}
*/
