/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:36:01 by mbalman           #+#    #+#             */
/*   Updated: 2021/04/23 12:36:45 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)(s1);
	ss2 = (unsigned char *)(s2);
	i = 0;
	if (n == 0)
		return (0);
	while (n != 0)
	{
		if (ss1[i] < ss2[i])
			return (ss1[i] - ss2[i]);
		if (ss1[i] > ss2[i])
			return (ss1[i] - ss2[i]);
		if (ss1[i] == ss2[i])
		{
			++i;
			--n;
		}
	}
	return (0);
}
