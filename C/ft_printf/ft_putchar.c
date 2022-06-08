/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:49:01 by dwren             #+#    #+#             */
/*   Updated: 2021/10/17 14:58:16 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_put_or_finish(char c, char stopper)
{
	static unsigned int	how_much_print_symb;
	unsigned int		tmp;

	if (stopper == 1)
	{
		tmp = how_much_print_symb;
		how_much_print_symb = 0;
		return (tmp);
	}
	how_much_print_symb++;
	ft_putchar(c);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
