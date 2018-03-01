/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:28:55 by dslogrov          #+#    #+#             */
/*   Updated: 2018/03/01 16:48:13 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"
#include "ft_list.h"
#include <stdlib.h>

char	*my_strdup(char *str, int begin, int end)
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
int		eval_expr(char *str)
{
	int		i;
	t_list	*begin_list;
	int		last_bracket;
	int		j;

	begin_list = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			if (str[i] == '(')
			{
				j = i;
				while (str[j] != '\0')
				{
					if (str[j] == ')')
						last_bracket = j;
					j++;
				}
				ft_list_push_back(&begin_list,
					&eval_expr(my_strdup(str, i + 1, last_bracket))
				);
				i = last_bracket;
			}
			else
			{
				end = i;
				while (str[end] != ' ')
					end++;
				ft_list_push_back(&begin_list,
						my_strdup(str, i, end));
				i = end;
			}
		}
		i++;
	}
	return solve(begin_list)
}

