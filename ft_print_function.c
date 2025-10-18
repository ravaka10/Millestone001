/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahari <rarahari@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:00:42 by rarahari          #+#    #+#             */
/*   Updated: 2025/04/16 01:07:29 by rarahari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printstr(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		cnt = cnt + ft_printchar(str[i]);
		i++;
	}
	return (cnt);
}

int	ft_print_nbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (n < 0)
	{
		count += ft_printchar('-');
		count += ft_print_nbr(-n);
	}
	else if (n > 9)
	{
		count += ft_print_nbr(n / 10);
		count += ft_print_nbr(n % 10);
	}
	else
	{
		n = n + 48;
		count += ft_printchar(n);
	}
	return (count);
}

int	ft_print_unsigned(unsigned int nb)
{
	int	cnt;

	cnt = 0;
	if (nb > 9)
	{
		cnt += ft_print_unsigned(nb / 10);
		cnt += ft_print_unsigned(nb % 10);
	}
	else
	{
		nb = nb + '0';
		cnt += ft_printchar(nb);
	}
	return (cnt);
}
