/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:54:18 by mbalman           #+#    #+#             */
/*   Updated: 2021/04/21 20:06:26 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	i;
	char	*strbuff;

	strbuff = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			strbuff = (char *)&str[i];
		i++;
	}
	if (str[i] == ch)
		strbuff = (char *)&str[i];
	return (strbuff);
}
