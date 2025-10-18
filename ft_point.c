/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahari <rarahari@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:44:13 by rarahari          #+#    #+#             */
/*   Updated: 2025/04/16 01:12:25 by rarahari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hexa_for_point(unsigned long n, char *base)
{
	int				i;
	int				j;
	int				ct;
	unsigned long	nb;

	i = 0;
	ct = 0;
	if (n == 0)
		return (ft_printchar(base[0]));
	nb = n;
	while (nb / 16 > 0)
	{
		nb /= 16;
		i++;
	}
	while (i >= 0)
	{
		ct += write(1, &base[nb % 16], 1);
		nb = n;
		j = 0;
		i--;
		while (j++ < i)
			nb /= 16;
	}
	return (ct);
}

int	ft_point(void *p)
{
	if (!p)
		return (write(1, "(nil)", 5));
	ft_printstr("0x");
	return (2 + put_hexa_for_point((unsigned long)p, "0123456789abcdef"));
}
