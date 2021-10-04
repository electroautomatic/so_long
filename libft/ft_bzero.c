/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:12:17 by mbalman           #+#    #+#             */
/*   Updated: 2021/04/22 18:48:50 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*buffer;
	size_t			i;

	i = 0;
	buffer = (unsigned char *)s;
	while (i != n)
	{
		buffer[i] = '\0';
		i++;
	}
	return (buffer);
}	
