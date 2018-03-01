/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:07:25 by dslogrov          #+#    #+#             */
/*   Updated: 2018/03/01 16:16:06 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	new->data = data;
	new->next = NULL;
	return (new);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *current_node;

	if (*begin_list == NULL)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	current_node = *begin_list;
	while (current_node->next)
		current_node = current_node->next;
	current_node->next = ft_create_elem(data);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new;

	new = ft_create_elem(data);
	new->next = *begin_list;
	*begin_list = new;
}

int		ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*current_node;

	current_node = begin_list;
	i = 1;
	while (current_node->next)
	{
		i++;
		current_node = current_node->next;
	}
	return (i);
}

t_list	*ft_list_last(t_list *begin_list)
{
	t_list *current;

	current = begin_list;
	while (current->next)
		current = current->next;
	return (current);
}

