/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahari <rarahari@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 08:52:07 by rarahari          #+#    #+#             */
/*   Updated: 2025/05/05 14:33:50 by rarahari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_print_nbr(int nb);
int	ft_put_hexa(unsigned int n, char *s);
int	ft_print_unsigned(unsigned int nb);
int	ft_point(void *p);
#endif
