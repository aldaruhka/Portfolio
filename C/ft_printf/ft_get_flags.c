/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:16:20 by dwren             #+#    #+#             */
/*   Updated: 2021/10/17 14:58:27 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_get_flags(const char *s, t_flags *flags, int *i)
{
	while ((s[*i] == '+' || s[*i] == ' ' || s[*i] == '#') && s[*i])
	{
		if (!flags->plus && s[*i] == ' ')
			flags->space = 1;
		if (s[*i] == '+')
		{
			flags->plus = 1;
			flags->space = 0;
		}
		if (s[*i] == '#')
			flags->oct = 1;
		(*i)++;
		if (s[*i] >= '0' && s[*i] <= '9')
			flags->wdt = ft_atoi(s, i);
	}
}
