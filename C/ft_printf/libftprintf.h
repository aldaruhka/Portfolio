/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:56:05 by dwren             #+#    #+#             */
/*   Updated: 2021/10/17 14:58:40 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	char	plus;
	char	space;
	char	oct;
	char	wdt;
}	t_flags;

void	ft_putnbr(long int n, t_flags *flags, char type);
void	ft_putstr(char *s, int wdt);
void	ft_putchar(char c);
int		ft_atoi(const char *str, int *i);
void	ft_flags_to_zero(t_flags *flags);
void	ft_print_regular_symb(const char *s, int *i);
void	ft_get_flags(const char *s, t_flags *flags, int *i);
void	ft_work_with_type(char type, t_flags *flags, va_list *args);
int		ft_put_or_finish(char c, char stopper);

#endif