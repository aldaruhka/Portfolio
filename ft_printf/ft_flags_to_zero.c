/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_to_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:21:57 by dwren             #+#    #+#             */
/*   Updated: 2021/10/17 14:58:00 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_flags_to_zero(t_flags *flags)
{
	flags->plus = 0;
	flags->space = 0;
	flags->oct = 0;
	flags->wdt = 0;
}
