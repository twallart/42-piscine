/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 09:03:35 by twallart          #+#    #+#             */
/*   Updated: 2026/08/14 09:20:48 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
int	ft_is_there_an_X(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'X')
			return (1);
		i++;
	}
	return (0);
}
*/
int	ft_any(char **tab, int (*f)(char *))
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		if ((*f)(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	int	result;
	char	*tab1[] = {"test", "test X", "test"};
	char	*tab2[] = {"test", "test", "test"};

	result = ft_any(tab1, &ft_is_there_an_X);
	printf("result de tab1 = %d\n", result);
	result = ft_any(tab2, &ft_is_there_an_X);
	printf("result de tab2 = %d\n", result);
	return (0);
}
*/
