/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_regular_symb.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:15:06 by dwren             #+#    #+#             */
/*   Updated: 2021/10/17 14:58:09 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_regular_symb(const char *s, int *i)
{
	while (s[*i] && s[*i] != '%')
	{
		ft_put_or_finish(s[*i], 0);
		(*i)++;
	}
}
