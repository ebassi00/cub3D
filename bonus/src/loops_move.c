/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:04:48 by ebassi            #+#    #+#             */
/*   Updated: 2022/12/09 14:10:04 by ebassi           ###   ########.fr       */
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
	if (key == SHIFT)
		game->move->shift = 1;
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
	if (key == SHIFT)
		game->move->shift = 0;
	return (0);
}

void	ft_move(t_game	*game, double move_x, double move_y)
{
	float	i;

	i = (game->pl_x + move_x);
	if (game->map[(int) game->pl_y][(int) i] == '0'
		|| game->map[(int) game->pl_y][(int) i] == 'd')
		game->pl_x += move_x;
	i = (game->pl_y + move_y);
	if (game->map[(int) i][(int) game->pl_x] == '0'
		|| game->map[(int) i][(int) game->pl_x] == 'd')
		game->pl_y += move_y;
}

void	ft_rotate(t_game *game, double dir)
{
	game->p_angle += dir;
	game->pl_dx = cos(deg_to_rad(game->p_angle));
	game->pl_dy = sin(deg_to_rad(game->p_angle));
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
		ft_move(game, cos(deg_to_rad(game->p_angle - 90))
			* MOV_SPEED, sin(deg_to_rad(game->p_angle - 90)) * MOV_SPEED);
	if (game->move->d == 1)
		ft_move(game, cos(deg_to_rad(game->p_angle + 90))
			* MOV_SPEED, sin(deg_to_rad(game->p_angle + 90)) * MOV_SPEED);
	if (game->move->arr_left == 1)
		ft_rotate(game, -ROT_SPEED);
	if (game->move->arr_right == 1)
		ft_rotate(game, ROT_SPEED);
	if (game->move->shift == 1)
		ft_door(game);
	return (0);
}
