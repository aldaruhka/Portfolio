/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 22:53:28 by dwren             #+#    #+#             */
/*   Updated: 2021/10/17 14:58:21 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printstr(char *s, int wdt)
{
	int	i;

	i = 0;
	while (i < wdt)
	{
		ft_put_or_finish(' ', 0);
		i++;
	}
	while (*s)
	{
		ft_put_or_finish(*s, 0);
		s++;
	}
}

void	ft_putstr(char *s, int wdt)
{
	if (!s)
		ft_printstr("(null)", wdt);
	else
		ft_printstr(s, wdt);
}
