/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 09:23:01 by twallart          #+#    #+#             */
/*   Updated: 2026/08/14 09:36:18 by twallart         ###   ########.fr       */
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
int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (i < length)
	{
		if ((*f)(tab[i]) == 1)
			result++;
		i++;
	}
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	int	result;
	char	*tab1[] = {"teXst", "Xtest X", "testX"};
	char	*tab2[] = {"test", "test", "test"};

	result = ft_count_if(tab1, 3, &ft_is_there_an_X);
	printf("result de tab1 = %d\n", result);
	result = ft_count_if(tab2, 3, &ft_is_there_an_X);
	printf("result de tab2 = %d\n", result);
	return (0);
}
*/
