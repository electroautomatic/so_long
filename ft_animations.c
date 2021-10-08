/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:14:12 by mbalman           #+#    #+#             */
/*   Updated: 2021/10/08 18:13:41 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_coin_animation(t_data *data)
{
	static int	t;

	if (t < 5)
		data->coins.img = data->coins.img_1;
	else if (5 < t && t < 10)
		data->coins.img = data->coins.img_2;
	else if (10 < t && t < 15)
		data->coins.img = data->coins.img_3;
	else if (15 < t && t < 20)
		data->coins.img = data->coins.img_4;
	else if (20 < t && t < 25)
		data->coins.img = data->coins.img_5;
	else if (25 < t && t < 30)
		data->coins.img = data->coins.img_6;
	else if (30 < t && t < 35)
		data->coins.img = data->coins.img_7;
	else if (35 < t && t < 40)
		data->coins.img = data->coins.img_8;
	else if (45 < t && t < 50)
		data->coins.img = data->coins.img_9;
	t++;
	if (t == 50)
	{
		t = 0;
	}
}

void	ft_enemy_animation(t_data *data)
{
	static int	z;

	if (z < 10)
		data->enmy.img = data->enmy.img_1;
	else if (10 < z && z < 20)
		data->enmy.img = data->enmy.img_2;
	z++;
	if (z == 20)
	{
		z = 0;
	}
}


int	ft_render(t_data *data)
{
	int		l;
	int		h;

	l = 0;
	h = 0;
	while (h != data->map.map_size_h)
	{
		while (l != data->map.map_size_l)
		{
			if (data->map.map_pars[h][l] != '1')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
					data->map.img_floor, l * 32, h * 32);
			}
			else if (data->map.map_pars[h][l] == '1')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
					data->map.img_wall, l * 32, h * 32);
			}
			if (data->map.map_pars[h][l] == 'C')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
					data->coins.img, l * 32, h * 32);
			}
			if (data->map.map_pars[h][l] == 'E' && data->coins.count == 0)
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
					data->exit.img_exit, l * 32, h * 32);
			}
			if (data->map.map_pars[h][l] == 'Z')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
					data->enmy.img, l * 32, h * 32);
			}
			l++;
		}
		l = 0;
		h++;
	}
	return (0);
}
