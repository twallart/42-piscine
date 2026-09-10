/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 18:07:58 by twallart          #+#    #+#             */
/*   Updated: 2026/08/13 11:26:43 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_alloc_size(int size, char **strs, char *sep)
{
	char	*dest;
	int		i;
	int		length;
	int		nb_sep;

	i = 0;
	length = 0;
	nb_sep = 0;
	if (size == 0)
		return (malloc(1));
	while (i < size)
	{
		length += ft_strlen(strs[i]);
		nb_sep++;
		i++;
	}
	nb_sep = ft_strlen(sep) * (nb_sep - 1);
	dest = malloc(sizeof(char) * (length + nb_sep + 1));
	if (!dest)
		return (NULL);
	return (dest);
}

void	ft_copy(char *dest, char *src, int *k)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[*k] = src[i];
		i++;
		(*k)++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		k;
	char	*dest;

	if (!strs || !sep)
		return (NULL);
	dest = ft_alloc_size(size, strs, sep);
	i = 0;
	k = 0;
	while (i < size)
	{
		ft_copy(dest, strs[i], &k);
		if (i < size - 1)
			ft_copy(dest, sep, &k);
		i++;
	}
	dest[k] = '\0';
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*strs[] = {"Je", "suis", "Thomas"};
	char	*dest;

	dest = ft_strjoin(3, strs, "_SLT_");
	if (!dest)
		printf("NULL\n");
	else
		printf("%s\n", dest);
	return (0);
}
*/
