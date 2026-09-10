/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:04:03 by twallart          #+#    #+#             */
/*   Updated: 2026/08/26 16:06:00 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	result;

	result = 0;
	while (begin_list != NULL)
	{
		begint_list = begin_list->next;
		result++;
	}
	return (result);
}
