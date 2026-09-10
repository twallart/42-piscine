/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 17:06:25 by twallart          #+#    #+#             */
/*   Updated: 2026/08/24 03:36:38 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include <stdlib.h>
#define BUFF_SIZE	29696
#define C		5

void	ft_putchar(char c, int err);
void	ft_putstr(char *str, int err);
int		ft_atoi(char *str);
int		check_nb1(char *str, int *c);
int		check_nb2(char *str, int *c);
int		check_c1(char *str, int *c);
int		check_c2(char *s1, char *s2, int *c);
int		ft_error(char *name, char *file);
void	ft_read(int fd, char *name, char *file, int c);

int	no_argument(char *name)
{
	ft_putstr(basename(name), 2);
	ft_putstr(": option requires an argument -- 'c'\n", 2);
	ft_putstr("Try 'tail --help' for more information.\n", 2);
	return (1);
}

int	open_file(char **argv, int argc, int i, int *c)
{
	int	fd;
	int	files_nb;

	files_nb = argc - i;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
			return (ft_error(argv[0], argv[i]));
		else
		{
			if (files_nb > 1)
			{
				ft_putstr("==> ", 1);
				ft_putstr(argv[i], 1);
				ft_putstr(" <==\n", 1);
			}
			ft_read(fd, argv[0], argv[i], *c);
			if (i < argc - 1)
				ft_putstr("\n", 1);
			close(fd);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	c;

	if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'c'
		&& argv[1][2] == '\0')
		return (no_argument(argv[0]));
	else if ((argc == 1) || (argc == 2 && check_c1(argv[1], &c) == 1)
		|| (argc == 3 && check_c2(argv[1], argv[2], &c) == 1)
		|| (argc == 2 && argv[1][0] == '-'))
	{
		ft_read(0, argv[0], "stdin", c);
		return (0);
	}
	else
	{
		if (argc >= 3 && check_c2(argv[1], argv[2], &c) == 1)
			i = 3;
		else if (argc >= 2 && check_c1(argv[1], &c) == 1)
			i = 2;
		open_file(argv, argc, i, &c);
	}
	return (0);
}
