/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:39:57 by dwren             #+#    #+#             */
/*   Updated: 2021/12/06 18:16:43 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_shift_to_left(char memory[BUFFER_SIZE], size_t nxt_ln)
{
	size_t	i;

	i = 0;
	while (i + nxt_ln < BUFFER_SIZE)
	{
		memory[i] = memory[i + nxt_ln];
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		memory[i] = 0;
		i++;
	}
}

size_t	ft_str_search(const char *s, size_t len, char symb)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != symb && i < len)
		i++;
	return (i);
}

static void	ft_copy_str(char *result, const char *s, size_t *i, size_t len)
{
	size_t	cnt;

	cnt = 0;
	while (s && s[cnt] && cnt < len)
	{
		result[*i] = s[cnt];
		(*i)++;
		cnt++;
	}
}

char	*ft_strjoin_changed(char *s, char memory[BUFFER_SIZE], size_t len)
{
	size_t	i;
	char	*result;
	size_t	size;

	if (len == 0)
		return (s);
	size = len;
	if (s)
		size += ft_str_search(s, -1, '\0');
	result = malloc((size + 1) * sizeof(char));
	if (!result)
	{
		if (s)
			free(s);
		return (NULL);
	}
	i = 0;
	ft_copy_str(result, s, &i, size - len);
	ft_copy_str(result, memory, &i, len);
	result[i] = 0;
	if (s)
		free(s);
	return (result);
}
