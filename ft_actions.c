/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:19:36 by mbalman           #+#    #+#             */
/*   Updated: 2021/10/10 16:19:22 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_press_key_1(t_data *data)
{
	if (data->map.map_pars[(data->player.y) / 32][(data->player.x) / 32] == 'C')
	{	
		data->map.map_pars[(data->player.y) / 32][(data->player.x) / 32] = '0';
		data->coins.count--;
	}
	if (data->coins.count == 0 && data->player.x == data->exit.x \
		&& data->player.y == data->exit.y)
		exit(0);
	if (data->map.map_pars[(data->player.y) / 32][(data->player.x) / 32] == 'Z')
		exit (0);
}

int	press_key(int key, t_data *data)
{
	if (key == 2 && (data->map.map_pars[(data->player.y) / 32] \
		[(data->player.x) / 32 + 1] != '1'))
	{
		(data->player.x) = (data->player.x) + 32;
		data->player.img = data->player.img_right;
	}
	else if (key == 0 && (data->map.map_pars[(data->player.y) / 32] \
		[(data->player.x) / 32 - 1] != '1'))
	{
		(data->player.x) = (data->player.x) - 32;
		data->player.img = data->player.img_left;
	}
	else if (key == 13 && (data->map.map_pars[(data->player.y) / 32 - 1] \
		[(data->player.x) / 32] != '1'))
		(data->player.y) = (data->player.y) - 32;
	else if (key == 1 && (data->map.map_pars[(data->player.y) / 32 + 1] \
		[(data->player.x) / 32] != '1'))
		(data->player.y) = (data->player.y) + 32;
	else if (key == 53)
		exit(0);
	ft_press_key_1(data);
	if (key == 2 || key == 0 || key == 13 || key == 1)
		data->player.steps++;
	printf("Steps count - %d\n", data->player.steps);
	return (0);
}

int	mouse_clik(t_data *data)
{
	(void)data;
	printf("EXIT");
	exit (0);
}
