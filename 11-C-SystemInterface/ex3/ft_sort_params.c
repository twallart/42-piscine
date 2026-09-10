/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 20:33:50 by twallart          #+#    #+#             */
/*   Updated: 2026/08/16 00:31:01 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

void	sort_argv(int argc, char *argv[], int isordered)
{
	int		i;
	int		j;
	char	*temp;

	while (isordered == 0)
	{
		isordered = 1;
		i = 1;
		while (i < argc - 1)
		{
			j = 0;
			while (argv[i][j] != '\0' && argv[i + 1][j] != '\0'
				&& argv[i][j] == argv[i + 1][j])
				j++;
			if (argv[i][j] > argv[i + 1][j])
			{
				temp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = temp;
				isordered = 0;
			}
			i++;
		}
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc >= 2)
		sort_argv(argc, argv, 0);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
	}
	return (0);
}
