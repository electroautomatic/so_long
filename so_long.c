/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:36:59 by mbalman           #+#    #+#             */
/*   Updated: 2021/10/04 17:28:15 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

typedef struct s_vars {
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	char	*image_path;
	void	*img;
	char	**map;
	int		map_size_l;
	int		map_size_h;
}			t_vars;

int	press_key(int key, t_vars *vars)
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
	//mlx_pixel_put(vars->mlx_ptr, vars->win_ptr, vars->x, vars->y, 0x0000FF00);
	return (0);
}

void	ft_map_volidation(int argc, char **argv, t_vars *vars)
{
	int		fd;
	int		end_map;
	char	*line;

	vars->map_size_h = 0;
	vars->map_size_l = 0;
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
		//printf("%s %d\n", line, ft_strlen(line));
		vars->map_size_l = ft_strlen(line);
		vars->map_size_h++;
	}	
}

void	ft_pars_map(char **argv, t_vars *vars)
{
	int		fd;
	int		end_map;
	int		i;
	char	*line;

	end_map = 1;
	i = 0;
	line = NULL;
	vars->map = malloc(sizeof(char *) * vars->map_size_h);
	fd = open(argv[1], O_RDONLY);
	while (end_map)
	{
		end_map = get_next_line(fd, &line);
		vars->map[i] = line;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		img_width;
	int		img_height;
	int		x = 0;
	int		y = 0;

	ft_map_volidation(argc, argv, &vars);
	ft_pars_map(argv, &vars);
	vars.x = 250;
	vars.y = 25;
	vars.image_path = "./grass-33.xpm";
	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, vars.map_size_l * 32, vars.map_size_h * 32, "21 School");
	while (y != vars.map_size_h)
	{
		while (x != vars.map_size_l)
		{
			vars.img = mlx_xpm_file_to_image(vars.mlx_ptr, vars.image_path, &img_width, &img_height);
			mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, vars.img, x * 32, y * 32);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_key_hook(vars.win_ptr, press_key, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
