/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:07:25 by dslogrov          #+#    #+#             */
/*   Updated: 2018/03/04 16:00:03 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

char	*ft_strdup(char *str, int start, int end)
{
	char	*newstr;
	int		i;

	newstr = malloc(end - start + 1);
	i = 0;
	while (i < end - start)
	{
		newstr[i] = str[start + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

t_list	*ft_create_elem(void *data)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	new->data = data;
	new->next = NULL;
	return (new);
}

void	ft_lpb(t_list **begin_list, void *data)
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
