/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:38:26 by twallart          #+#    #+#             */
/*   Updated: 2026/08/23 15:38:45 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str);

int	check_nb1(char *str, int *c)
{
	int	i;

	i = 2;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	*c = ft_atoi(&str[2]);
	return (1);
}

int	check_nb2(char *str, int *c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	*c = ft_atoi(str);
	return (1);
}

int	check_c1(char *str, int *c)
{
	if (str[0] == '-' && str[1] == 'c' && check_nb1(str, c) == 1)
		return (1);
	return (0);
}

int	check_c2(char *s1, char *s2, int *c)
{
	if (s1[0] == '-' && s1[1] == 'c' && check_nb2(s2, c) == 1)
		return (1);
	return (0);
}
