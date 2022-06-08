/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:49:20 by dwren             #+#    #+#             */
/*   Updated: 2021/10/17 14:58:12 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	t_flags	flags;
	int		i;

	if (!s)
		return (0);
	va_start(args, s);
	i = 0;
	while (s[i])
	{
		ft_print_regular_symb(s, &i);
		ft_flags_to_zero(&flags);
		if (s[i] == '%')
		{
			i++;
			ft_get_flags(s, &flags, &i);
			ft_work_with_type(s[i], &flags, &args);
			i++;
		}
	}
	va_end(args);
	return (ft_put_or_finish(0, 1));
}
