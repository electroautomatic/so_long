/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:36:59 by mbalman           #+#    #+#             */
/*   Updated: 2021/10/06 19:42:22 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	press_key(int key, t_data *data)
{
	printf("Hello World! Press key %d\n", key);
	if (key == 2)
		(data->player.x) = (data->player.x) + 32;
	else if (key == 0)
		(data->player.x) = (data->player.x) - 32;
	else if (key == 13)
		(data->player.y) = (data->player.y) - 32;
	else if (key == 1)
		(data->player.y) = (data->player.y) + 32;
	else if (key == 53)
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
	int	l;
	int	h;

	l = 0;
	h = 0;
	while (h != data->map.map_size_h)
	{
		while (l != data->map.map_size_l)
		{
			if (data->map.map_pars[h][l] == 'P')
			{
				data->player.x = l * 32;
				data->player.y = h * 32;
			}
			l++;
		}
		l = 0;
		h++;
	}
}

int	ft_render(t_data *data)
{
	int		img_w;
	int		img_h;
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
				data->map.img = mlx_xpm_file_to_image(data->mlx_ptr, \
					FLOOR, &img_w, &img_h);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
					data->map.img, l * 32, h * 32);
				//free(data->map.img);
			}
			else if (data->map.map_pars[h][l] == '1')
			{
				data->map.img = mlx_xpm_file_to_image(data->mlx_ptr, \
					WALL, &img_w, &img_h);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
					data->map.img, l * 32, h * 32);
				//free(data->map.img);
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
	int		img_width;
	int		img_height;

	data->player.img = mlx_xpm_file_to_image(data->mlx_ptr, \
		PLAYER, &img_width, &img_height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player.img, \
		data->player.x, data->player.y);
	return (0);
}

int	ft_frame(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_render(data);
	ft_player_action(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_map_volidation(argc, argv, &data);
	ft_pars_map(argv, &data);
	ft_map_inint(&data);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map.map_size_l * 32, data.map.map_size_h * 32, "21 School");
	mlx_loop_hook(data.mlx_ptr, ft_frame, &data);
	mlx_key_hook(data.win_ptr, press_key, &data);
	mlx_clear_window(data.mlx_ptr, data.win_ptr);
	mlx_loop(data.mlx_ptr);	
	return (0);
}
