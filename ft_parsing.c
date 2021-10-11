/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:36:41 by mbalman           #+#    #+#             */
/*   Updated: 2021/10/11 13:13:12 by mbalman          ###   ########.fr       */
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

void	ft_chek_name_map(char **argv)
{
	int	l;

	l = ft_strlen(argv[1]);
	if (argv[1][l - 1 ] == 'r' && argv[1][l - 2] == 'e' \
	&& argv[1][l - 3] == 'b' && argv[1][l - 4] == '.')
		return ;
	else
	{
		printf("Error Bad map name\n");
		exit (0);
	}
}

void	ft_chek_map_evalible(int fd)
{
	if (fd == -1)
	{
		printf("Error\nMap file not found\n");
		exit (0);
	}
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
		printf("Error arguments\n");
		exit(0);
	}
	ft_chek_name_map(argv);
	end_map = 1;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	ft_chek_map_evalible(fd);
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
		if ((data->map.map_size_l + 1) != ft_strlen(line))
		{
			printf("Error count symbol in line\n");
			exit (0);
		}
		data->map.map_pars[i] = line;
		i++;
	}	
}
