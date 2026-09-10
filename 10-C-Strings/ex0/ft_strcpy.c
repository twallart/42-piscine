/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 14:23:15 by twallart          #+#    #+#             */
/*   Updated: 2026/08/13 18:29:04 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
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
	dest = ft_strcpy(dest, src);
	printf("%s", dest);
	free(dest);
	return (0);
}
*/
