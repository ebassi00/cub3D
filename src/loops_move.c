/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:18:02 by ebassi            #+#    #+#             */
/*   Updated: 2022/12/08 16:10:20 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_on(int key, t_game *game)
{
	if (key == 53 || key == 17)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_destroy_window(game->mlx, game->win);
		exit (0);
	}
	if (key == UP)
		game->move->w = 1;
	if (key == DOWN)
		game->move->s = 1;
	if (key == RIGHT)
		game->move->d = 1;
	if (key == LEFT)
		game->move->a = 1;
	if (key == ARR_LEFT)
		game->move->arr_left = 1;
	if (key == ARR_RIGHT)
		game->move->arr_right = 1;
	return (0);
}

int	ft_off(int key, t_game *game)
{
	if (key == 53 || key == 17)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_destroy_window(game->mlx, game->win);
		exit (0);
	}
	if (key == UP)
		game->move->w = 0;
	if (key == DOWN)
		game->move->s = 0;
	if (key == RIGHT)
		game->move->d = 0;
	if (key == LEFT)
		game->move->a = 0;
	if (key == ARR_LEFT)
		game->move->arr_left = 0;
	if (key == ARR_RIGHT)
		game->move->arr_right = 0;
	return (0);
}

void	ft_move(t_game	*game, double move_x, double move_y)
{
	float	i;

	i = (game->pl_x + move_x);
	if (game->map[(int) game->pl_y][(int) i] != '1')
		game->pl_x += move_x;
	i = (game->pl_y + move_y);
	if (game->map[(int) i][(int) game->pl_x] != '1')
		game->pl_y += move_y;
}

void	ft_rotate(t_game *game, double dir)
{
	game->p_angle += dir;
	game->pl_dx = cos(deg_to_rad(game->p_angle));
	game->pl_dy = sin(deg_to_rad(game->p_angle));
}
