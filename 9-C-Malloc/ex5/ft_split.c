/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 22:59:32 by twallart          #+#    #+#             */
/*   Updated: 2026/08/13 18:47:45 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_check_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_countwords(char *str, char *charset)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		while (!ft_check_sep(str[i], charset) && str[i])
			i++;
		if (ft_check_sep(str[i], charset) && str[i])
			nb++;
		while (ft_check_sep(str[i], charset) && str[i])
			i++;
	}
	return (nb);
}

int	ft_strlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && ft_check_sep(str[i], charset))
		i++;
	return (i);
}

void	*ft_alloc(char *str, char *charset, int *j)
{
	int		i;
	char	*temp;

	i = 0;
	temp = malloc(sizeof(char) * (ft_strlen(&str[*j], charset) + 1));
	if (!temp)
		return (NULL);
	while (str[*j] != '\0' && ft_check_sep(str[*j], charset))
	{
		temp[i] = str[*j];
		i++;
		(*j)++;
	}
	temp[i] = '\0';
	return (temp);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**dest;

	i = 0;
	j = 0;
	dest = malloc(sizeof(char *) * (ft_countwords(str, charset) + 1));
	if (!dest)
		return (NULL);
	while (i < ft_countwords(str, charset))
	{
		while (!(ft_check_sep(str[j], charset)) && str[j])
			j++;
		dest[i] = ft_alloc(str, charset, &j);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	char	**dest;

	dest = ft_split("", "");
	printf("%s\n%s\n%s\n%s\n", dest[0], dest[1], dest[2], dest[3]);
	free(dest);
	return (0);
}
*/
