/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:07:04 by ebassi            #+#    #+#             */
/*   Updated: 2022/12/08 18:10:02 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	ft_y(t_game *game, double index, int measure)
{
	return ((game->minimap->height / 2) + (game->pl_y * measure)
		- (index * measure) - measure);
}

double	ft_x(t_game *game, double index, int measure)
{
	return ((game->minimap->width / 2) + (game->pl_x * measure)
		- (index * measure) - measure);
}

int	ft_find_ray_x(t_game *game, float increase, float start_angle)
{
	return (game->minimap->width / 2 + increase
		* (cos(deg_to_rad(start_angle)) * (-1)));
}

int	ft_find_ray_y(t_game *game, float increase, float start_angle)
{
	return (game->minimap->height / 2 + increase
		* (sin(deg_to_rad(start_angle)) * (-1)));
}

int	ft_check_on_map(t_game *game, int angle_x, int angle_y)
{
	if (game->map[angle_y / 20][angle_x / 20] == '1')
		return (0);
	else
		return (1);
}
