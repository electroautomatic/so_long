/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:36:59 by mbalman           #+#    #+#             */
/*   Updated: 2021/10/08 18:11:59 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_map_inint(t_data *data)
{
	int		l;
	int		h;

	l = 0;
	h = 0;
	data->coins.count = 0;
	while (h != data->map.map_size_h)
	{
		while (l != data->map.map_size_l)
		{
			if (data->map.map_pars[h][l] == 'P')
			{
				data->player.x = l * 32;
				data->player.y = h * 32;
			}
			else if (data->map.map_pars[h][l] == 'E')
			{
				data->exit.x = l * 32;
				data->exit.y = h * 32;
			}
			else if (data->map.map_pars[h][l] == 'Z')
			{
				data->enmy.x = l * 32;
				data->enmy.y = h * 32;
			}
			else if (data->map.map_pars[h][l] == 'C')
				data->coins.count++;
			l++;
		}
		l = 0;
		h++;
	}
}

int	ft_player_action(t_data *data)
{	
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player.img, \
		data->player.x, data->player.y);
	return (0);
}

void	ft_render_steps(t_data *data)
{	
	char	*str;

	str = ft_itoa(data->player.steps);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 5, 0xFFFF00, "Steps count: ");
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
