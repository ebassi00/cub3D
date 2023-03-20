/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:54:10 by ebassi            #+#    #+#             */
/*   Updated: 2022/12/09 17:26:41 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_things(t_game *game, int saved, int saved2, int fd)
{
	char	*trimmed_res;
	char	*res;

	res = get_next_line(fd);
	while (saved2 != saved)
	{
		free(res);
		res = get_next_line(fd);
		saved2++;
	}
	trimmed_res = ft_strtrim(res, "\n");
	game->width = (int)ft_strlen(trimmed_res);
	while (res != 0)
	{
		if ((int)ft_strlen(trimmed_res) > game->width)
			game->width = ft_strlen(trimmed_res);
		game->height++;
		free(res);
		res = get_next_line(fd);
	}
	game->saved = saved;
	free(trimmed_res);
	free(res);
}

void	free_color_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	get_floor(t_game *game)
{
	int		color;
	char	**matrix;
	int		i;

	i = 0;
	color = 0;
	matrix = ft_split(game->map_textures->floor_color, ',');
	while (matrix[i] != NULL)
	{
		if (ft_atoi(matrix[i]) < 0 || ft_atoi(matrix[i]) > 255)
			ft_exit("Error\n");
		if (i == 0)
			color += ft_atoi(matrix[i]) * 65536;
		else if (i == 1)
			color += ft_atoi(matrix[i]) * 256;
		else
			color += ft_atoi(matrix[i]);
		i++;
	}
	free_color_matrix(matrix);
	game->floor_color = color;
}

void	get_ceilling(t_game *game)
{
	int		color;
	char	**matrix;
	int		i;

	i = 0;
	color = 0;
	matrix = ft_split(game->map_textures->ceilling_color, ',');
	while (matrix[i] != NULL)
	{
		if (ft_atoi(matrix[i]) < 0 || ft_atoi(matrix[i]) > 255)
			ft_exit("Error\n");
		if (i == 0)
			color += ft_atoi(matrix[i]) * 65536;
		else if (i == 1)
			color += ft_atoi(matrix[i]) * 256;
		else
			color += ft_atoi(matrix[i]);
		i++;
	}
	free_color_matrix(matrix);
	game->ceilling_color = color;
}

int	check_color(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] == ',')
			i++;
		else if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}
