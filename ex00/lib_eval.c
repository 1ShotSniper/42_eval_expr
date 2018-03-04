/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_eval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 13:57:40 by dslogrov          #+#    #+#             */
/*   Updated: 2018/03/04 16:29:04 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		is_order(char *str, int i)
{
	if (str[1] != '\0')
		return (0);
	if (i == 0)
	{
		if (str[0] == '*' || str[0] == '%' || str[0] == '/')
			return (1);
	}
	else
	{
		if (str[0] == '+' || str[0] == '-')
			return (1);
	}
	return (0);
}

int		is_order_1(char *str)
{
	if (str[1] != '\0')
		return (0);
	if (str[0] == '*' || str[0] == '%' || str[0] == '/')
		return (1);
	return (0);
}

int		is_order_2(char *str)
{
	if (str[1] != '\0')
		return (0);
	if (str[0] == '+' || str[0] == '-')
		return (1);
	return (0);
}

int		find_brac(char *str, int start)
{
	int j;
	int result;

	j = start;
	while (str[j] != '\0')
	{
		if (str[j] == ')')
			result = j;
		j++;
	}
	return (result);
}
