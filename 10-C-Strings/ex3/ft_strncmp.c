/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 14:52:15 by twallart          #+#    #+#             */
/*   Updated: 2026/08/15 16:00:10 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n) && (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'))
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int	main(void)
{
	char	s1[] = "FJMWacFutDdZZAmJOfUiazRAuanaTWRHNgmhMPmtrSlgEzOfbrCZYhqiP";
	char	s2[] = "FJMWacFutDdZZAmJOfUiazRAuanaTaPPwhjrbccnRqJuxKc";

	printf("Ma fonction : %d\n", ft_strncmp(s1, s2, 5));
	printf("strncmp : %d\n", strncmp(s1, s2, 5));
	return (0);
}
*/
