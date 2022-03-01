/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:48:22 by dwren             #+#    #+#             */
/*   Updated: 2021/10/17 14:58:19 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	ft_change_sign_num_sys(long int n, char type)
{
	if (n < 0)
		n = -n;
	if (n >= 10 && (type == 'x' || type == 'p'))
		return (n + 'a' - 10);
	if (n >= 10 && type == 'X')
		return (n + 'A' - 10);
	return (n + '0');
}

static void	ft_put(long int n, int num_sys, char type)
{
	if (n / num_sys == 0)
		ft_put_or_finish(ft_change_sign_num_sys(n, type), 0);
	else
	{
		ft_put(n / num_sys, num_sys, type);
		ft_put_or_finish(ft_change_sign_num_sys(n % num_sys, type), 0);
	}
}

static void	ft_put_pointer(unsigned long int n, char type)
{
	if (n / 16 == 0)
	{
		ft_putstr("0x", 0);
		ft_put_or_finish(ft_change_sign_num_sys(n, type), 0);
	}
	else
	{
		ft_put_pointer(n / 16, type);
		ft_put_or_finish(ft_change_sign_num_sys(n % 16, type), 0);
	}
}

void	ft_putnbr(long int n, t_flags *flags, char type)
{
	if (type == 'i' || type == 'd')
	{
		if (n < 0)
			ft_put_or_finish('-', 0);
		else if (flags->plus)
			ft_put_or_finish('+', 0);
		else if (flags->space)
			ft_put_or_finish(' ', 0);
		ft_put((int)n, 10, type);
	}
	else if (type == 'x' || type == 'X')
	{
		if (flags->oct && n)
		{
			ft_put_or_finish('0', 0);
			ft_put_or_finish(type, 0);
		}
		ft_put((unsigned int)n, 16, type);
	}
	else if (type == 'u')
		ft_put((unsigned int)n, 10, type);
	else if (type == 'p')
	{
		ft_put_pointer((unsigned long long)n, type);
	}
}
