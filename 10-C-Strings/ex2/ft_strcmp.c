/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 14:47:10 by twallart          #+#    #+#             */
/*   Updated: 2026/08/13 18:49:33 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	s1[] = "Bonjour";
	char	s2[] = "Bonj";

	printf("Ma fonction : %d\n", ft_strcmp(s1, s2));
	printf("strcmp : %d\n", strcmp(s1, s2));
	return (0);
}
*/
