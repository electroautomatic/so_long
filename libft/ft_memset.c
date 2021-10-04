/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:44:53 by mbalman           #+#    #+#             */
/*   Updated: 2021/04/22 20:03:36 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t count)
{
	char	*buf1;
	size_t	i;

	buf1 = (char *)buf;
	i = 0;
	while (i < count)
	{
		buf1[i] = (char)ch;
		i++;
	}
	return (buf);
}
