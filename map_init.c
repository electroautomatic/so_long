/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:29:26 by mbalman           #+#    #+#             */
/*   Updated: 2021/10/10 17:45:08 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_map_init_1(int l, int h, t_data *data)
{
	if (data->map.map_pars[h][l] == 'P')
	{
		data->player.x = l * 32;
		data->player.y = h * 32;
		data->player.count++;
	}
	else if (data->map.map_pars[h][l] == 'E')
	{
		data->exit.x = l * 32;
		data->exit.y = h * 32;
		data->exit.count++;
	}
	else if (data->map.map_pars[h][l] == 'Z')
	{
		data->enmy.x = l * 32;
		data->enmy.y = h * 32;
	}
	else if (data->map.map_pars[h][l] == 'C')
		data->coins.count++;
}

void	ft_map_inint(t_data *data)
{
	int		l;
	int		h;

	l = 0;
	h = 0;
	data->coins.count = 0;
	data->exit.count = 0;
	data->player.count = 0;
	while (h != data->map.map_size_h)
	{
		while (l != data->map.map_size_l)
		{
			ft_map_init_1(l, h, data);
			l++;
		}
		l = 0;
		h++;
	}
}
