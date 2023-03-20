/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:11:30 by ebassi            #+#    #+#             */
/*   Updated: 2022/12/09 18:45:34 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_ray_wall(t_game *game, double *rays, double ray_cos, double ray_sin)
{
	while (game->map[(int)rays[1]][(int)rays[0]] == '0'
		|| game->map[(int)rays[1]][(int)rays[0]] == 'd')
	{
		rays[0] += ray_cos;
		rays[1] += ray_sin;
		if (game->map[(int)rays[1]][(int)rays[0]] == 'D')
			game->flag = 1;
	}
}

void	raycasting(t_game *game)
{
	double	ray_angle;
	double	rays[2];
	double	ray_cos;
	double	ray_sin;
	int		ray_count;

	ray_angle = game->p_angle - game->fov / 2;
	ray_count = -1;
	while (++ray_count < game->screen_width)
	{
		game->flag = 0;
		rays[0] = game->pl_x;
		rays[1] = game->pl_y;
		ray_cos = cos(deg_to_rad(ray_angle)) / game->ray_hit->ray_precision;
		ray_sin = sin(deg_to_rad(ray_angle)) / game->ray_hit->ray_precision;
		get_ray_wall(game, rays, ray_cos, ray_sin);
		get_distance(game, rays, ray_angle);
		game->texture_pos_x = find_mod((64.0 * (rays[0] + rays[1])), 64.0);
		draw_line(game, ray_count, get_orientation(game, ray_angle,
				rays, game->flag));
		ray_angle += game->ray_hit->increment_angle;
	}
	face(game, 256);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
}
