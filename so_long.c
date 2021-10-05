/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:36:59 by mbalman           #+#    #+#             */
/*   Updated: 2021/10/05 20:05:55 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	press_key(int key, t_data *vars)
{
	(void)vars;
	printf("Hello World! Press key %d\n", key);
	if (key == 124)
		(vars->x) = (vars->x) + 4;
	else if (key == 123)
		(vars->x) = (vars->x) - 4;
	else if (key == 126)
		(vars->y) = (vars->y) - 4;
	else if (key == 125)
		(vars->y) = (vars->y) + 4;
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

void	ft_render(t_data *data)
{
	int		img_width;
	int		img_height;
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
				data->map.img = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR, &img_width, &img_height);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->map.img, l * 32, h * 32);
			}
			else if (data->map.map_pars[h][l] == '1')
			{
				data->map.img = mlx_xpm_file_to_image(data->mlx_ptr, WALL, &img_width, &img_height);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->map.img, l * 32, h * 32);
			}
			if (data->map.map_pars[h][l] == 'P')
			{
				data->map.img = mlx_xpm_file_to_image(data->mlx_ptr, PlAYER, &img_width, &img_height);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->map.img, l * 32, h * 32);
			}
			l++;
		}
		l = 0;
		h++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_map_volidation(argc, argv, &data);
	ft_pars_map(argv, &data);
	// data.map.img_path_floor = FLOOR;
	// data.map.ing_pach_wall = WALL;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map.map_size_l * 32, data.map.map_size_h * 32, "21 School");
	ft_render(&data);
	mlx_key_hook(data.win_ptr, press_key, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
