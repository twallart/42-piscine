/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 08:51:51 by twallart          #+#    #+#             */
/*   Updated: 2026/08/14 09:21:21 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*
int	ft_return(int nb)
{
	return (nb);
}
*/
int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*dest;

	i = 0;
	dest = malloc(sizeof(int) * length);
	if (!dest)
		return (NULL);
	while (i < length)
	{
		dest[i] = (*f)(tab[i]);
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	int	tab[] = {1, 2, 3, 4};
	int	*dest;
	int	size;
	int	i;

	i = 0;
	size = 4;
	dest = ft_map(tab, size, &ft_return);
	while (i < size)
	{
		printf("%d\n", dest[i]);
		i++;
	}
	free(dest);
	return (0);
}
*/
