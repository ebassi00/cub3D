/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:12:02 by masebast          #+#    #+#             */
/*   Updated: 2022/12/09 14:19:01 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_mouse(t_game *game)
{
	int	delta;
	int	x_center;
	int	y_center;
	int	mouse_x;
	int	mouse_y;

	x_center = game->screen_width / 2;
	y_center = game->screen_height / 2;
	mlx_mouse_get_pos(game->win, &mouse_x, &mouse_y);
	delta = x_center - mouse_x;
	if (delta > 0)
		ft_rotate(game, -ROT_SPEED * delta / 10);
	else if (delta < 0)
		ft_rotate(game, ROT_SPEED * -delta / 10);
	mlx_mouse_move(game->win, x_center, y_center);
}
