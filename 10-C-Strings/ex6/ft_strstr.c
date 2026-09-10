/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 15:03:57 by twallart          #+#    #+#             */
/*   Updated: 2026/08/15 00:29:53 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		k = i;
		while (str[k] == to_find[j] && to_find[j] != '\0')
		{
			j++;
			k++;
		}
		if (to_find[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	char	str[] = "Hello World";
	char	*result;

	result = ft_strstr(str, "World");
	printf("Test 1 (trouve): %s\n", result ? result : "NULL");
	result = ft_strstr(str, "xyz");
	printf("Test 2 (absent): %s\n", result ? result : "NULL");
	result = ft_strstr(str, "Hello");
	printf("Test 3 (debut): %s\n", result ? result : "NULL");
	return (0);
}
*/
