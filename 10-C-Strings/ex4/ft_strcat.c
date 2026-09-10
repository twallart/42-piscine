/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 14:55:43 by twallart          #+#    #+#             */
/*   Updated: 2026/08/13 19:02:52 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
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
	ft_strcat(dest, src);
	printf("Test 1 (dest vide): \"%s\"\n", dest);
	ft_strcat(dest, " le monde");
	printf("Test 2 (dest non vide): \"%s\"\n", dest);
	ft_strcat(dest, "");
	printf("Test 3 (src vide): \"%s\"\n", dest);
	free(dest);
	return (0);
}
*/
