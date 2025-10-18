/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahari <rarahari@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:38:57 by rarahari          #+#    #+#             */
/*   Updated: 2025/04/16 00:37:00 by rarahari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hexa(unsigned int n, char *base)
{
	int				i;
	int				j;
	int				ct;
	unsigned int	nb;

	i = 0;
	ct = 0;
	if (n == 0)
		return (ct += ft_printchar(base[0]));
	nb = n;
	while (nb / 16 > 0)
	{
		nb /= 16;
		i++;
	}
	while (i >= 0)
	{
		ct += ft_printchar(base[nb % 16]);
		nb = n;
		j = 0;
		i--;
		while (j++ < i)
			nb /= 16;
	}
	return (ct);
}
