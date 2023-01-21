/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpideci <@student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:59:50 by hpideci           #+#    #+#             */
/*   Updated: 2023/01/21 12:59:51 by hpideci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char a)
{
	return (write(1, &a, 1));
}

int	ft_format(va_list *ac, char c)
{
	if (c == 'u')
		return (ft_unsigned(va_arg((*ac), unsigned int)));
	else if (c == 'c')
		return (ft_putchar(va_arg((*ac), int)));
	else if (c == 'i' || c == 'd')
		return (ft_int(va_arg((*ac), int)));
	else if (c == 'x' || c == 'X')
		return (ft_hex(va_arg((*ac), unsigned int), c));
	else if (c == 'p')
		return (ft_point(va_arg((*ac), unsigned long), 1));
	else if (c == 's')
		return (ft_string(va_arg((*ac), char *)));
	else
		return (ft_string("%"));
}

int	ft_flag_catch(const char *str, int i)
{
	return (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == 'd'
			|| str[i + 1] == 'i' || str[i + 1] == 'u'
			|| str[i + 1] == 'x' || str[i + 1] == 'X'
			|| str[i + 1] == 'p' || str[i + 1] == 's' || str[i + 1] == '%'));
}

int	ft_printf(const char *str, ...)
{
	va_list	ac;
	int		i;
	int		rtn;

	i = -1;
	rtn = 0;
	va_start(ac, str);
	while (str[++i])
	{
		if (ft_flag_catch(str, i))
			rtn += ft_format(&ac, str[++i]);
		else if (str[i] != '%')
			rtn += write(1, &str[i], 1);
	}
	va_end(ac);
	return (rtn);
}
