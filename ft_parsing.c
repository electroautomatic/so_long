/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:36:41 by mbalman           #+#    #+#             */
/*   Updated: 2021/10/08 18:08:46 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_next_line(int fd, char **line)
{
	int		rd;
	int		i;
	char	ch;
	char	*buffer;

	rd = 1;
	i = 0;
	ch = 0;
	buffer = malloc(100000);
	*line = buffer;
	while ((rd > 0) && (ch != '\n'))
	{
		rd = read(fd, &ch, 1);
		buffer[i++] = ch;
	}
	buffer[i] = '\0';
	return (rd);
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

void	ft_img_inint(t_data *data)
{
	int		w;
	int		h;

	data->player.img = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER, &w, &h);
	data->map.img_floor = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR, &w, &h);
	data->map.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL, &w, &h);
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
	data->exit.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT, &w, &h);
	data->enmy.img_1 = mlx_xpm_file_to_image(data->mlx_ptr, "s/enemies/Enemies2.xpm", &w, &h);
	data->enmy.img_2 = mlx_xpm_file_to_image(data->mlx_ptr, "s/enemies/Enemies3.xpm", &w, &h);
	data->enmy.img = data->enmy.img_1;
}
