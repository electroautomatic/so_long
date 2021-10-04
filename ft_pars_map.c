/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:36:41 by mbalman           #+#    #+#             */
/*   Updated: 2021/10/03 19:38:13 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_next_line(int fd, char **line)
{
	int		rd;
	int		i;
	char	ch;
	char	*buffer;

	rd = 1;
	i = 0;
	ch = 0;
	buffer = malloc(100000);
	*line = buffer;
	while ((rd > 0) && (ch != '\n'))
	{
		rd = read(fd, &ch, 1);
		buffer[i++] = ch;
	}
	buffer[i] = '\0';
	return (rd);
}
