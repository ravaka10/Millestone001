/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahari <rarahari@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:32:44 by rarahari          #+#    #+#             */
/*   Updated: 2025/04/28 09:20:50 by rarahari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list args)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter += ft_printchar(va_arg(args, int));
	else if (c == 's')
		counter += ft_printstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		counter += ft_print_nbr(va_arg(args, int));
	else if (c == 'u')
		counter += ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		counter += ft_put_hexa(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		counter += ft_put_hexa(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		counter += ft_point(va_arg(args, void *));
	else if (c == '%')
		counter += ft_printchar('%');
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	count = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += ft_format(*str, args);
		}
		else
			count += ft_printchar(*str);
		str++;
	}
	va_end(args);
	return (count);
}
