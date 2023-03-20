/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:21:40 by ebassi            #+#    #+#             */
/*   Updated: 2022/12/08 17:49:46 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		rays[0] = game->pl_x;
		rays[1] = game->pl_y;
		ray_cos = cos(deg_to_rad(ray_angle)) / game->ray_hit->ray_precision;
		ray_sin = sin(deg_to_rad(ray_angle)) / game->ray_hit->ray_precision;
		while (game->map[(int)rays[1]][(int)rays[0]] != '1')
		{
			rays[0] += ray_cos;
			rays[1] += ray_sin;
		}
		get_distance(game, rays, ray_angle);
		game->texture_pos_x = find_mod((64.0 * (rays[0] + rays[1])), 64.0);
		draw_line(game, ray_count, get_orientation(game, ray_angle, rays));
		ray_angle += game->ray_hit->increment_angle;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
}

int	deal_key(t_game *game)
{
	double	ldx;
	double	ldy;

	ldx = cos(deg_to_rad(game->p_angle));
	ldy = sin(deg_to_rad(game->p_angle));
	if (game->move->w == 1)
		ft_move(game, game->pl_dx * MOV_SPEED, game->pl_dy * MOV_SPEED);
	if (game->move->s == 1)
		ft_move(game, -(game->pl_dx * MOV_SPEED), -(game->pl_dy * MOV_SPEED));
	if (game->move->a == 1)
		ft_move(game, cos(deg_to_rad(game->p_angle - 90)) * MOV_SPEED,
			sin(deg_to_rad(game->p_angle - 90)) * MOV_SPEED);
	if (game->move->d == 1)
		ft_move(game, cos(deg_to_rad(game->p_angle + 90)) * MOV_SPEED,
			sin(deg_to_rad(game->p_angle + 90)) * MOV_SPEED);
	if (game->move->arr_left == 1)
		ft_rotate(game, -ROT_SPEED);
	if (game->move->arr_right == 1)
		ft_rotate(game, ROT_SPEED);
	return (0);
}
