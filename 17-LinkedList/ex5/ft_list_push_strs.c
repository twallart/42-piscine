/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 17:27:20 by twallart          #+#    #+#             */
/*   Updated: 2026/08/27 13:03:34 by twallart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->data = data;
	elem->next = *begin_list;
	*begin_list = elem;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	int	i;
	t_list	*head;

	head = NULL;
	i = 1;
	if (size >= 1)
		head = ft_create_elem(strs[0]);
	while (i < size)
	{
		ft_list_push_front(&head, strs[i]);
		i++;
	}
	return (head);
}
