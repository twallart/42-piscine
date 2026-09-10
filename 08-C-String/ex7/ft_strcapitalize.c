/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 09:31:12 by twallart          #+#    #+#             */
/*   Updated: 2026/08/09 00:19:27 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	str = ft_strlowcase(str);
	if (str[0] >= 'a' && str[0] <= 'z')
	{
		str[0] -= 32;
		i++;
	}
	while (str[i] != '\0')
	{
		if ((str[i] < 'a' || str[i] > 'z')
			&& (str[i] < '0' || str[i] > '9'))
		{
			if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
			{
				str[i + 1] -= 32;
				i++;
			}
		}
		i++;
	}
	return (str);
}

/*
#include <stdio.h>
int	main(void)
{
	char	str[] = "abc/ere  iuYYhw WUq [eweWq...42ew 89blabla  .  .. wews";
	printf("abc/ere  iuYYhw WUq [eweWq...42ew 89blabla  .  .. wews : %s\n",
	ft_strcapitalize(str));
	char str2[] = "hello, how are you doing? 42words forty-two; fifty+and+one";
	printf("hello, how are you doing? 42words forty-two; fifty+and+one : %s\n",
        ft_strcapitalize(str2));
	return (0);
}
*/
