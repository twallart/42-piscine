/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 14:58:48 by twallart          #+#    #+#             */
/*   Updated: 2026/08/15 00:28:37 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	while (j < nb)
	{
		dest[i] = '\0';
		j++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char	*dest;
	char	src[] = "Bonjour";

	dest = malloc(20);
	if (!dest)
		return (1);
	dest[0] = '\0';
	ft_strncat(dest, src, 4);
	printf("Test 1 (dest vide): \"%s\"\n", dest);
	ft_strncat(dest, " le monde", 4);
	printf("Test 2 (dest non vide): \"%s\"\n", dest);
	ft_strncat(dest, "", 4);
	printf("Test 3 (src vide): \"%s\"\n", dest);
	free(dest);
	return (0);
}
*/
