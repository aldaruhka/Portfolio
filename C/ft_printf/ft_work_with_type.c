/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_with_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 02:35:24 by dwren             #+#    #+#             */
/*   Updated: 2021/10/17 14:58:23 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_work_with_type(char type, t_flags *flags, va_list *args)
{
	if (type == 'c')
		ft_put_or_finish((unsigned char)va_arg(*args, int), 0);
	else if (type == 's')
		ft_putstr(va_arg(*args, char *), flags->wdt);
	else if (type == 'p')
		ft_putnbr(va_arg(*args, unsigned long long), flags, type);
	else if (type == 'i' || type == 'd')
		ft_putnbr(va_arg(*args, int), flags, type);
	else if (type == 'u')
		ft_putnbr(va_arg(*args, int), flags, type);
	else if (type == 'x')
		ft_putnbr(va_arg(*args, int), flags, type);
	else if (type == 'X')
		ft_putnbr(va_arg(*args, int), flags, type);
	else if (type == '%')
		ft_put_or_finish('%', 0);
	else
		ft_put_or_finish(type, 0);
}
