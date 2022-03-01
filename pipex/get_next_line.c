/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:39:59 by dwren             #+#    #+#             */
/*   Updated: 2021/12/06 18:16:52 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	memory[BUFFER_SIZE];
	long int	len;
	size_t		nxt_ln;
	char		*s;

	if (fd < 0)
		return (NULL);
	s = NULL;
	while (1)
	{
		nxt_ln = ft_str_search(memory, BUFFER_SIZE, '\n');
		if (memory[nxt_ln] == '\n')
			nxt_ln++;
		s = ft_strjoin_changed(s, memory, nxt_ln);
		ft_shift_to_left(memory, nxt_ln);
		len = ft_str_search(s, -1, '\n');
		if (s && s[len] == '\n')
			return (s);
		len = read(fd, memory, BUFFER_SIZE);
		if (len <= 0)
			return (s);
	}
}
