/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 17:01:42 by twallart          #+#    #+#             */
/*   Updated: 2026/08/26 17:23:39 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*elem;
	t_list	*tmp;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return ;
	elem->data = data;
	elem->next = NULL;
	if (*begin_list == NULL)
	{
		*begin_list = elem;
		return ;
	}
	tmp = *begin_list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
}
