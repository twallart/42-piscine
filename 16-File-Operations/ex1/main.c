/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 17:06:25 by twallart          #+#    #+#             */
/*   Updated: 2026/08/23 04:38:34 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#define BUFF_SIZE	29696

void	ft_putchar(char c, int err)
{
	write(err, &c, 1);
}

void	ft_putstr(char *str, int err)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], err);
		i++;
	}
}

int	ft_error(char *name, char *file)
{
	ft_putstr(basename(name), 2);
	ft_putstr(": ", 2);
	ft_putstr(file, 2);
	ft_putstr(": ", 2);
	ft_putstr(strerror(errno), 2);
	ft_putstr("\n", 2);
	return (1);
}

void	ft_read(int fd, char *name, char *file)
{
	char	buf[BUFF_SIZE];
	int		nb_read;

	nb_read = read(fd, buf, BUFF_SIZE - 1);
	while (nb_read > 0)
	{
		buf[nb_read] = '\0';
		write(1, buf, nb_read);
		nb_read = read(fd, buf, BUFF_SIZE - 1);
	}
	if (nb_read < 0)
		ft_error(name, file);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	fd;

	if (argc == 1)
		ft_read(0, argv[0], "stdin");
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
			return (ft_error(argv[0], argv[i]));
		else
		{
			ft_read(fd, argv[0], argv[i]);
			close(fd);
		}
		i++;
	}
	return (0);
}
