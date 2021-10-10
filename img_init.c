/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:11:27 by mbalman           #+#    #+#             */
/*   Updated: 2021/10/10 14:23:27 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_img_init_coin(t_data *data)
{
	int		w;
	int		h;

	data->coins.img_1 = mlx_xpm_file_to_image(data->mlx_ptr, COIN_1, &w, &h);
	data->coins.img_2 = mlx_xpm_file_to_image(data->mlx_ptr, COIN_2, &w, &h);
	data->coins.img_3 = mlx_xpm_file_to_image(data->mlx_ptr, COIN_3, &w, &h);
	data->coins.img_4 = mlx_xpm_file_to_image(data->mlx_ptr, COIN_4, &w, &h);
	data->coins.img_5 = mlx_xpm_file_to_image(data->mlx_ptr, COIN_5, &w, &h);
	data->coins.img_6 = mlx_xpm_file_to_image(data->mlx_ptr, COIN_6, &w, &h);
	data->coins.img_7 = mlx_xpm_file_to_image(data->mlx_ptr, COIN_7, &w, &h);
	data->coins.img_8 = mlx_xpm_file_to_image(data->mlx_ptr, COIN_8, &w, &h);
	data->coins.img_9 = mlx_xpm_file_to_image(data->mlx_ptr, COIN_9, &w, &h);
	data->coins.img = data->coins.img_5;
}

void	ft_inint_plaeyr(t_data *data)
{
	int		w;
	int		h;

	data->player.img_left = mlx_xpm_file_to_image(data->mlx_ptr, \
		PLAYER_L, &w, &h);
	data->player.img_right = mlx_xpm_file_to_image(data->mlx_ptr, \
		PLAYER_R, &w, &h);
	data->player.img = data->player.img_right;
}

void	ft_img_inint(t_data *data)
{
	int		w;
	int		h;

	ft_inint_plaeyr(data);
	data->map.img_floor = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR, &w, &h);
	data->map.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL, &w, &h);
	ft_img_init_coin(data);
	data->exit.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT, &w, &h);
	data->enmy.img_1 = mlx_xpm_file_to_image(data->mlx_ptr, \
		ENEMY_2, &w, &h);
	data->enmy.img_2 = mlx_xpm_file_to_image(data->mlx_ptr, \
		ENEMY_3, &w, &h);
	data->enmy.img = data->enmy.img_1;
}
