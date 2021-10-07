/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:36:59 by mbalman           #+#    #+#             */
/*   Updated: 2021/10/07 17:52:15 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	press_key(int key, t_data *data)
{
	printf("Hello World! Press key %d\n", key);
	if (key == 2 && (data->map.map_pars[(data->player.y)/ 32][(data->player.x)/32 + 1] != '1'))
		(data->player.x) = (data->player.x) + 32;
	else if (key == 0 && (data->map.map_pars[(data->player.y)/ 32][(data->player.x)/ 32 - 1] != '1'))
		(data->player.x) = (data->player.x) - 32;
	else if (key == 13 && (data->map.map_pars[(data->player.y)/32 - 1][(data->player.x)/ 32] != '1'))
		(data->player.y) = (data->player.y) - 32;
	else if (key == 1 && (data->map.map_pars[(data->player.y)/32 + 1][(data->player.x)/ 32] != '1'))
		(data->player.y) = (data->player.y) + 32;	
	else if (key == 53)
		exit(0);
	if (data->map.map_pars[(data->player.y)/ 32][(data->player.x)/32] == 'C')
	{	
		data->map.map_pars[(data->player.y)/ 32][(data->player.x)/32] = '0';
		data->coins.count--;
	}
	if (data->coins.count == 0 && data->player.x == data->exit.x && data->player.y == data->exit.y)
		exit(0);
	return (0);
}

void	ft_map_volidation(int argc, char **argv, t_data *data)
{
	int		fd;
	int		end_map;
	char	*line;

	data->map.map_size_h = 0;
	data->map.map_size_l = 0;
	if (argc != 2)
	{	
		printf("Error\n");
		exit(0);
	}
	end_map = 1;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	while (end_map)
	{
		end_map = get_next_line(fd, &line);
		data->map.map_size_l = ft_strlen(line);
		data->map.map_size_h++;
		free(line);
	}
	data->map.map_size_l = ft_strlen(line) - 1;
}

void	ft_pars_map(char **argv, t_data *data)
{
	int		fd;
	int		end_map;
	int		i;
	char	*line;

	end_map = 1;
	i = 0;
	line = NULL;
	data->map.map_pars = malloc(sizeof(char *) * data->map.map_size_h);
	fd = open(argv[1], O_RDONLY);
	while (end_map)
	{
		end_map = get_next_line(fd, &line);
		data->map.map_pars[i] = line;
		i++;
	}	
}

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
			else if (data->map.map_pars[h][l] == 'C')
				data->coins.count++;
			l++;
		}
		l = 0;
		h++;
	}
}

void	ft_img_inint(t_data *data)
{
	int		img_w;
	int		img_h;

	data->player.img = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER, &img_w, &img_h);	
	data->map.img_floor = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR, &img_w, &img_h);
	data->map.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL, &img_w, &img_h);
	data->coins.img_coin_1 = mlx_xpm_file_to_image(data->mlx_ptr, COIN_1, &img_w, &img_h);
	data->coins.img_coin_2 = mlx_xpm_file_to_image(data->mlx_ptr, COIN_2, &img_w, &img_h);
	data->coins.img_coin_3 = mlx_xpm_file_to_image(data->mlx_ptr, COIN_3, &img_w, &img_h);
	data->coins.img_coin_4 = mlx_xpm_file_to_image(data->mlx_ptr, COIN_4, &img_w, &img_h);
	data->coins.img_coin_5 = mlx_xpm_file_to_image(data->mlx_ptr, COIN_5, &img_w, &img_h);
	data->coins.img_coin_6 = mlx_xpm_file_to_image(data->mlx_ptr, COIN_6, &img_w, &img_h);
	data->coins.img_coin_7 = mlx_xpm_file_to_image(data->mlx_ptr, COIN_7, &img_w, &img_h);
	data->coins.img_coin_8 = mlx_xpm_file_to_image(data->mlx_ptr, COIN_8, &img_w, &img_h);
	data->coins.img_coin_9 = mlx_xpm_file_to_image(data->mlx_ptr, COIN_9, &img_w, &img_h);
	data->coins.img_coin = data->coins.img_coin_5;
	data->exit.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT, &img_w, &img_h);
}

void ft_coin_animation(t_data *data)
{
	static int	t;

	if (t < 5)
		data->coins.img_coin = data->coins.img_coin_1;
	else if (5 < t && t < 10)
		data->coins.img_coin = data->coins.img_coin_2;
	else if (10 < t && t < 15)
		data->coins.img_coin = data->coins.img_coin_3;
	else if (15 < t && t < 20)
		data->coins.img_coin = data->coins.img_coin_4;
	else if (20 < t && t < 25)
		data->coins.img_coin = data->coins.img_coin_5;
	else if (25 < t && t < 30)
		data->coins.img_coin = data->coins.img_coin_6;
	else if (30 < t && t < 35)
		data->coins.img_coin = data->coins.img_coin_7;
	else if (35 < t && t < 40)
		data->coins.img_coin = data->coins.img_coin_8;
	else if (45 < t && t < 50)
		data->coins.img_coin = data->coins.img_coin_9;
	t++;
	if (t == 50)
	{
		t = 0;
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
					data->coins.img_coin, l * 32, h * 32);
			}
			if (data->map.map_pars[h][l] == 'E' && data->coins.count == 0)
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
					data->exit.img_exit, l * 32, h * 32);
			}
			l++;
		}
		l = 0;
		h++;
	}
	return (0);
}

int	ft_player_action(t_data *data)
{	
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player.img, \
		data->player.x, data->player.y);
	return (0);
}

int	ft_frame(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_render(data);
	ft_player_action(data);
	ft_coin_animation(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	ft_map_volidation(argc, argv, &data);
	ft_pars_map(argv, &data);
	ft_map_inint(&data);
	ft_img_inint(&data);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map.map_size_l * 32,\
		data.map.map_size_h * 32, "21 School");
	mlx_loop_hook(data.mlx_ptr, ft_frame, &data);
	mlx_key_hook(data.win_ptr, press_key, &data);
	mlx_clear_window(data.mlx_ptr, data.win_ptr);
	mlx_loop(data.mlx_ptr);	
	return (0);
}
