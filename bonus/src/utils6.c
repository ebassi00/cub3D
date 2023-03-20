/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:32:50 by ebassi            #+#    #+#             */
/*   Updated: 2022/12/09 17:40:46 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		else if (i == 0)
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
		else if (i == 0)
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

int	check_text2(t_game *game)
{
	if (!game->map_textures->north_texture)
		return (0);
	if (!game->map_textures->south_texture)
		return (0);
	if (!game->map_textures->west_texture)
		return (0);
	if (!game->map_textures->east_texture)
		return (0);
	if (!game->map_textures->floor_color)
		return (0);
	if (!game->map_textures->ceilling_color)
		return (0);
	return (1);
}
