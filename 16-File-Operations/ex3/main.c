/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 17:06:25 by twallart          #+#    #+#             */
/*   Updated: 2026/08/24 03:50:51 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

char	*change_for_c(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127)
			str[i] = '.';
		i++;
	}
	return (str);
}

void	print_open_error(char *name, char *file)
{
	ft_putstr(basename(name), 2);
	ft_putstr(": ", 2);
	ft_putstr(file, 2);
	ft_putstr(": ", 2);
	ft_putstr(strerror(errno), 2);
	ft_putstr("\n", 2);
}

int	open_next(t_multi *m)
{
	while (m->idx < m->count)
	{
		m->fd = open(m->files[m->idx], O_RDONLY);
		m->idx++;
		if (m->fd >= 0)
		{
			m->any_success = 1;
			return (1);
		}
		print_open_error(m->name, m->files[m->idx - 1]);
	}
	return (0);
}

int	multi_read(t_multi *m, char *buf, int size)
{
	int	total;
	int	nb;

	total = 0;
	while (total < size)
	{
		if (m->fd < 0 && !open_next(m))
			break ;
		nb = read(m->fd, buf + total, size - total);
		if (nb < 0)
			return (-1);
		if (nb == 0)
		{
			close(m->fd);
			m->fd = -1;
			if (!open_next(m))
				break ;
			continue ;
		}
		total += nb;
	}
	return (total);
}

void	put_byte_nb(int nb)
{
	char	hexa[] = "0123456789abcdef";
	char	dest[] = "00000000";
	int		i;

	i = 7;
	while (i >= 0)
	{
		dest[i] = hexa[nb % 16];
		nb = nb / 16;
		i--;
	}
	ft_putstr(dest, 1);
}

void	ft_putnbr_hex(int nb)
{
	char    hexa[] = "0123456789abcdef";

	if (nb >= 16)
		ft_putnbr_hex(nb / 16);
	ft_putchar(hexa[nb % 16], 1);
}

void	print_hex_couple(char *str, int nb_read)
{
	int	i;

	i = 0;
	while (i < nb_read && str[i] != '\0')
	{
		if (str[i] < 16)
			ft_putchar('0', 1);
		ft_putnbr_hex(str[i]);
		ft_putchar(' ', 1);
		if (i == 7 || i == 15)
			ft_putchar(' ', 1);
		i++;
	}
	while (i < 16)
	{
		ft_putstr("  ", 1);
		ft_putchar(' ', 1);
		if (i == 7 || i == 15)
			ft_putchar(' ', 1);
		i++;
	}
}

void	ft_read(t_multi *m)
{
	char	*buf;
	char	*old_buf;
	int		nb_read;
	int		old_nb_read;
	int		total_read;
	int		starline;
	int		i;

	total_read = 0;
	starline = 0;
	old_nb_read = -1;
	old_buf = malloc(sizeof(char) * BUFF_SIZE);
	buf = malloc(sizeof(char) * BUFF_SIZE);
	nb_read = multi_read(m, buf, BUFF_SIZE - 1);
	while (nb_read > 0)
	{
		i = 0;
		while (i < nb_read && i < old_nb_read && buf[i] == old_buf[i])
			i++;
		if (nb_read == old_nb_read && i == nb_read && starline == 0)
		{
			ft_putstr("*\n", 1);
			starline = 1;
		}
		else if (!(nb_read == old_nb_read && i == nb_read))
		{
			if (total_read == 0)
				ft_putstr("00000000  ", 1);
			else
			{
				put_byte_nb(total_read);
				ft_putstr("  ", 1);
			}
			starline = 0;
			print_hex_couple(buf, nb_read);
			ft_putstr("|", 1);
			i = 0;
			while (i < nb_read)
			{
				old_buf[i] = buf[i];
				i++;
			}
			old_nb_read = nb_read;
			buf = change_for_c(buf);
			write(1, buf, nb_read);
			ft_putstr("|\n", 1);
		}
		total_read += nb_read;
		nb_read = multi_read(m, buf, BUFF_SIZE - 1);
	}
	put_byte_nb(total_read);
	ft_putchar('\n', 1);
	free(buf);
	free(old_buf);
}

void	put_byte_nb_no_c(int nb)
{
	char	hexa[] = "0123456789abcdef";
	char	dest[] = "0000000";
	int		i;

	i = 6;
	while (i >= 0)
	{
		dest[i] = hexa[nb % 16];
		nb = nb / 16;
		i--;
	}
	ft_putstr(dest, 1);
}

void	print_hex_no_c(char *str, int nb_read)
{
	int	i;

	i = 0;
	while (i < 17 && i < nb_read)
	{
		if (i + 1 < nb_read)
		{
			if (str[i + 1] < 16)
				ft_putchar('0', 1);
			ft_putnbr_hex(str[i + 1]);
		}
		else
		{
			ft_putchar('0', 1);
			ft_putchar('0', 1);
		}
		if (str[i] < 16)
			ft_putchar('0', 1);
		ft_putnbr_hex(str[i]);
		if (i != 14)
			ft_putchar(' ', 1);
		i += 2;
	}
	while (i < 16)
	{
		ft_putchar(' ', 1);
		ft_putchar(' ', 1);
		ft_putchar(' ', 1);
		ft_putchar(' ', 1);
		if (i != 14)
			ft_putchar(' ', 1);
		i += 2;
	}
}

void	ft_read_no_c(t_multi *m)
{
	char	*buf;
	char	*old_buf;
	int		nb_read;
	int		old_nb_read;
	int		total_read;
	int		starline;
	int		i;

	total_read = 0;
	starline = 0;
	old_nb_read = -1;
	old_buf = malloc(sizeof(char) * BUFF_SIZE);
	buf = malloc(sizeof(char) * BUFF_SIZE);
	nb_read = multi_read(m, buf, BUFF_SIZE - 1);
	while (nb_read > 0)
	{
		i = 0;
		while (i < nb_read && i < old_nb_read && buf[i] == old_buf[i])
			i++;
		if (nb_read == old_nb_read && i == nb_read && starline == 0)
		{
			ft_putstr("*\n", 1);
			starline = 1;
		}
		else if (!(nb_read == old_nb_read && i == nb_read))
		{
			if (total_read == 0)
				ft_putstr("0000000 ", 1);
			else
			{
				put_byte_nb_no_c(total_read);
				ft_putchar(' ', 1);
			}
			starline = 0;
			print_hex_no_c(buf, nb_read);
			ft_putchar('\n', 1);
			i = 0;
			while (i < nb_read)
			{
				old_buf[i] = buf[i];
				i++;
			}
			old_nb_read = nb_read;
		}
		total_read += nb_read;
		nb_read = multi_read(m, buf, BUFF_SIZE - 1);
	}
	put_byte_nb_no_c(total_read);
	ft_putchar('\n', 1);
	free(buf);
	free(old_buf);
}

int	main(int argc, char *argv[])
{
	t_multi	m;
	int		start;
	int		c_flag;

	c_flag = 0;
	start = 1;
	if (argc > 1 && argv[1][0] == '-' && argv[1][1] != '\0')
	{
		if (argv[1][1] == 'C' && argv[1][2] == '\0')
		{
			c_flag = 1;
			start = 2;
		}
		else
		{
			ft_putstr(basename(argv[0]), 2);
			ft_putstr(": invalid option -- '", 2);
			ft_putstr(argv[1] + 1, 2);
			ft_putstr("'\n", 2);
			return (1);
		}
	}
	m.files = argv + start;
	m.count = argc - start;
	m.idx = 0;
	m.name = argv[0];
	m.any_success = 0;
	if (m.count == 0)
	{
		m.fd = 0;
		m.any_success = 1;
	}
	else
		m.fd = -1;
	if (c_flag)
		ft_read(&m);
	else
		ft_read_no_c(&m);
	if (!m.any_success)
	{
		ft_putstr(basename(argv[0]), 2);
		ft_putstr(": all input file arguments failed\n", 2);
		return (1);
	}
	return (0);
}
