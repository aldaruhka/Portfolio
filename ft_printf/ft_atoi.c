/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 22:37:07 by dwren             #+#    #+#             */
/*   Updated: 2021/10/17 14:26:37 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str, int *i)
{
	long int	number;

	number = 0;
	while ((unsigned char)str[*i] >= '0' && (unsigned char)str[*i] <= '9')
	{
		if (number > 2147483647)
			return (-1);
		if (number < -2147483648)
			return (0);
		number = number * 10 + ((unsigned char)str[*i] - '0');
		(*i)++;
	}
	return ((int)number);
}
