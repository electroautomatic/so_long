/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:43:56 by mbalman           #+#    #+#             */
/*   Updated: 2021/10/11 19:26:13 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_check_map_simbol(t_data *data)
{
	int	l;
	int	h;

	l = 0;
	h = 0;
	while (h < data->map.map_size_h)
	{
		while (l < data->map.map_size_l)
		{
			if (data->map.map_pars[h][l] != '1' \
			&& data->map.map_pars[h][l] != '0' \
			&& data->map.map_pars[h][l] != 'P' \
			&& data->map.map_pars[h][l] != 'E' \
			&& data->map.map_pars[h][l] != 'C' \
			&& data->map.map_pars[h][l] != 'Z')
			{	
				printf("Error\n %c is not correct map symbol\n", \
					data->map.map_pars[h][l]);
				exit (0);
			}
			l++;
		}
		l = 0;
		h++;
	}
}

int	ft_check_frame(t_data *data)
{
	int	l;
	int	h;

	l = 0;
	h = 0;
	while (l < data->map.map_size_l)
	{	
		if (data->map.map_pars[0][l] != '1')
			data->map.flag_error++;
		if (data->map.map_pars[data->map.map_size_h - 1][l] != '1')
			data->map.flag_error++;
		l++;
	}
	while (h < data->map.map_size_h)
	{	
		if (data->map.map_pars[h][0] != '1')
			data->map.flag_error++;
		if (data->map.map_pars[h][data->map.map_size_l - 1] != '1')
			data->map.flag_error++;
		h++;
	}
	return (data->map.flag_error);
}

void	ft_check_map(t_data *data)
{
	if (data->coins.count < 1 || data->exit.count < 1 \
		|| data->player.count != 1)
	{	
		printf("Error \nMap must consist minimum 1 coin, 1 exit and 1 player.\n");
		exit (0);
	}	
	if (ft_check_frame(data) != 0)
	{
		printf("Error map frame\n");
		exit (0);
	}
	ft_check_map_simbol(data);
}
