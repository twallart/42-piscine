/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 03:40:00 by twallart          #+#    #+#             */
/*   Updated: 2026/08/24 03:44:20 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>
# include <stdio.h>
# define BUFF_SIZE	17

typedef	struct	s_multi {
	char	**files;
	char	*name;
	int		count;
	int		idx;
	int		fd;
	int		any_success;
}	t_multi;

#endif
