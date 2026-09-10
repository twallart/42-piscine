/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 14:40:36 by twallart          #+#    #+#             */
/*   Updated: 2026/08/13 18:42:50 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char	src[] = "Bonjour\0";
	char	*dest;

	dest = malloc(sizeof(char) * 7 + 1);
	if (!dest)
		return (1);
	dest = ft_strncpy(dest, src, 4);
	printf("%s", dest);
	free(dest);
	return (0);
}
*/
