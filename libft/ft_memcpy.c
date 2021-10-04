/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:20:50 by mbalman           #+#    #+#             */
/*   Updated: 2021/04/23 12:19:09 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (dest == NULL && source == NULL)
			break ;
		((char *)dest)[i] = ((char *)source)[i];
		i++;
	}
	return (dest);
}
