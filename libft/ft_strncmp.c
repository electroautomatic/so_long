/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:21:32 by mbalman           #+#    #+#             */
/*   Updated: 2021/04/22 16:14:11 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *string1, const char *string2, size_t num)
{
	size_t	i;

	i = 0;
	if (num == 0)
	{
		return (0);
	}
	while ((unsigned char)*string1 == (unsigned char)*string2
		&& *string1 != '\0' && i < num - 1)
	{
		string1++;
		string2++;
		i++;
	}
	return ((unsigned char)*string1 - (unsigned char)*string2);
}
