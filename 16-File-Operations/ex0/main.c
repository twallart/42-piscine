/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 11:05:45 by twallart          #+#    #+#             */
/*   Updated: 2026/08/23 04:39:02 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar(char c, int err)
{
	if (err == 1)
		write(err, &c, 1);
	else
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

void	ft_read(int fd)
{
	char	buf[101];
	int		nb_read;

	nb_read = -1;
	while (nb_read != 0)
	{
		nb_read = read(fd, buf, 100);
		if (nb_read == -1)
		{
			ft_putstr("Cannot read file.\n", 2);
			return ;
		}
		buf[nb_read] = '\0';
		write(1, buf, nb_read);
	}
}

int	main(int argc, char *argv[])
{
	int	fd;

	if (argc == 1)
	{
		ft_putstr("File name missing.\n", 2);
		return (1);
	}
	else if (argc > 2)
	{
		ft_putstr("Too many arguments.\n", 2);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 2)
	{
		ft_putstr("Cannot read file.\n", 2);
		return (1);
	}
	ft_read(fd);
	close(fd);
	return (0);
}
