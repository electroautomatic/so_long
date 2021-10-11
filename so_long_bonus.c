/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:36:59 by mbalman           #+#    #+#             */
/*   Updated: 2021/10/11 19:27:38 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_render_steps(t_data *data)
{	
	char	*str;

	str = ft_itoa(data->player.steps);
	mlx_string_put(data->mlx_ptr, data->win_ptr, \
		5, 5, 0xFFFF00, "Steps count: ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 130, 5, 0xFFFF00, str);
}

int	ft_frame(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_render(data);
	ft_player_action(data);
	ft_coin_animation(data);
	ft_enemy_animation(data);
	ft_render_steps(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.player.steps = 0;
	data.mlx_ptr = mlx_init();
	ft_map_volidation(argc, argv, &data);
	ft_pars_map(argv, &data);
	ft_map_inint(&data);
	ft_check_map(&data);
	ft_img_inint(&data);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map.map_size_l * 32, \
		data.map.map_size_h * 32, "21 School");
	mlx_loop_hook(data.mlx_ptr, ft_frame, &data);
	mlx_hook(data.win_ptr, 2, 0, press_key, &data);
	mlx_hook(data.win_ptr, 17, 0L, mouse_clik, &data);
	mlx_clear_window(data.mlx_ptr, data.win_ptr);
	mlx_loop(data.mlx_ptr);
	return (0);
}
