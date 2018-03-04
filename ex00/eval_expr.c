/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:28:55 by dslogrov          #+#    #+#             */
/*   Updated: 2018/03/04 16:32:42 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"
#include <stdlib.h>

char	*small_solve(t_list *left, t_list *op, t_list *right)
{
	if (((char *)op->data)[0] == '+')
		return (ft_itoa(ft_atoi(left->data) + ft_atoi(right->data)));
	if (((char *)op->data)[0] == '-')
		return (ft_itoa(ft_atoi(left->data) - ft_atoi(right->data)));
	if (((char *)op->data)[0] == '*')
		return (ft_itoa(ft_atoi(left->data) * ft_atoi(right->data)));
	if (((char *)op->data)[0] == '/')
		return (ft_itoa(ft_atoi(left->data) / ft_atoi(right->data)));
	if (((char *)op->data)[0] == '%')
		return (ft_itoa(ft_atoi(left->data) % ft_atoi(right->data)));
	return ("-42");
}

t_list	*replace_nodes(t_list *start)
{
	t_list	*new;
	t_list	*end;

	new = ft_create_elem(small_solve(start, start->next, start->next->next));
	end = start->next->next->next;
	free(start->next->next);
	free(start->next);
	free(start);
	new->next = end;
	return (new);
}

t_list	**break_chain(t_list **begin_list, int index)
{
	int		i;
	t_list	*cur;
	t_list	*previous;

	cur = *begin_list;
	if (!index)
		*begin_list = replace_nodes(cur);
	else
	{
		i = 0;
		while (i < index - 1)
		{
			cur = cur->next;
			i++;
		}
		previous = cur;
		cur = cur->next;
		previous->next = replace_nodes(cur);
	}
	return (begin_list);
}

int		eval_solve(t_list **begin_list)
{
	t_list	*current;
	int		index;
	int		i;

	if (!((*begin_list)->next))
	{
		index = ft_atoi((*begin_list)->data);
		free(*begin_list);
		return (index);
	}
	i = 0;
	while (i < 2)
	{
		current = *begin_list;
		index = 0;
		while (current->next)
		{
			if (is_order(current->next->data, i))
				return (eval_solve(break_chain(begin_list, index)));
			index += 2;
			current = current->next->next;
		}
		i++;
	}
	return (-42);
}

int		eval_expr(char *str)
{
	int		i;
	t_list	*list;
	int		j;

	list = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '(')
		{
			ft_lpb(&list, ft_itoa(
				eval_expr(ft_strdup(str, i + 1, find_brac(str, i)))));
			i = find_brac(str, i);
		}
		else if (str[i] != ' ' && str[i] != '\0')
		{
			j = i;
			while (str[j] != ' ' && str[j] != '\0')
				j++;
			ft_lpb(&list, ft_strdup(str, i, j));
			i = j - 1;
		}
		i++;
	}
	return (eval_solve(&list));
}
