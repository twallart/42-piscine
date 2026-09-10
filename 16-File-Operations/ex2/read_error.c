/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 16:18:54 by twallart          #+#    #+#             */
/*   Updated: 2026/08/24 03:23:08 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <libgen.h>
#include <unistd.h>
#define BUFF_SIZE	29696
#define C		5

void	ft_putstr(char *str, int err);

int	ft_error(char *name, char *file)
{
	ft_putstr(basename(name), 2);
	ft_putstr(": cannot open \'", 2);
	ft_putstr(file, 2);
	ft_putstr("\' for reading: ", 2);
	ft_putstr(strerror(errno), 2);
	ft_putstr("\n", 2);
	return (1);
}

void	ft_read(int fd, char *name, char *file, int c)
{
	char	buf[BUFF_SIZE];
	char	*temp;
	int		nb_read;
	int		i;

	temp = malloc(sizeof(char) * (c + 2));
	if (!temp)
		return ;
	nb_read = read(fd, buf, BUFF_SIZE - 1);
	while (nb_read > 0)
	{
		i = 0;
		buf[nb_read] = '\0';
		while (i < c)
		{
			temp[c - 1 - i] = buf[nb_read - 1 - i];
			i++;
		}
		temp[c + 1] = '\0';
		nb_read = read(fd, buf, BUFF_SIZE - 1);
	}
	ft_putstr(temp, 1);
	free(temp);
	if (nb_read < 0)
		ft_error(name, file);
}
