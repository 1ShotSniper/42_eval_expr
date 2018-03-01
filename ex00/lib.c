/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:37:08 by dslogrov          #+#    #+#             */
/*   Updated: 2018/03/01 13:19:48 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	if (nbr < 10)
		ft_putchar(nbr + '0');
}

int		ft_atoi(char *str)
{
	int i;
	int sign;
	int result;

	
	if (str[0] == '-')
	{
		i = 0;
		sign = -1;
	}
	else
	{
		i = 1;
		sign = 1;
	}
	result = 0;
	while (str[i] !='\0')
		result = result*10 + str[i] -'0';
	return (sign * res);
}



