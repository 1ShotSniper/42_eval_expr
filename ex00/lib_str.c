/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 13:53:53 by dslogrov          #+#    #+#             */
/*   Updated: 2018/03/04 13:56:34 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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
		i = 1;
		sign = -1;
	}
	else
	{
		i = 0;
		sign = 1;
	}
	result = 0;
	while (str[i] != '\0')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}

void	recurse_print(int value, char *spot)
{
	if (value < 10)
		*spot = value + '0';
	else
	{
		recurse_print(value / 10, spot - 1);
		*spot = value % 10 + '0';
	}
}

char	*ft_itoa(int value)
{
	char	*result;
	int		length;
	int		dummy;

	if (value == -2147483648)
		return ("-2147483648");
	length = 1;
	if (value < 0)
		length += 1;
	dummy = value;
	while (dummy /= 10)
		length++;
	result = malloc(sizeof(char) * (length + 1));
	if (value < 0)
	{
		value *= -1;
		result[0] = '-';
	}
	recurse_print(value, result + length - 1);
	result[length] = '\0';
	return (result);
}
