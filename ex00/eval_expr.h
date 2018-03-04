/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:46:17 by dslogrov          #+#    #+#             */
/*   Updated: 2018/03/04 16:32:06 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_H
# define EVAL_EXPR_H

# include "ft_list.h"

int		eval_expr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nbr);
int		ft_atoi(char *str);
void	ft_lpb(t_list **begin_list, void *data);
t_list	*ft_create_elem(void *data);
char	*ft_itoa(int i);
char	*ft_strdup(char *str, int start, int end);
int		is_order(char *str, int i);
int		find_brac(char *str, int start);

#endif
