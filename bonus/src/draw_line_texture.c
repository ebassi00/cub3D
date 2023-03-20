/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:28:07 by ebassi            #+#    #+#             */
/*   Updated: 2022/12/09 14:42:13 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_data img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.ll + x * (img.bpp / 8));
	*(unsigned int *)dst = color;
}

int	text_pixel_put(int x, int y, t_text *text)
{
	char	*src;
	int		color;

	src = text->addr + (y * text->ll + x * (text->bpp / 8));
	color = *(unsigned int *)src;
	return (color);
}

void	get_text_start(t_game *game, double *y_incrementer,
	double save_dist, int *y_text)
{
	int	wheight;
	int	wall_height;

	wheight = (int)(game->screen_height / 2 / save_dist);
	*y_incrementer = (wheight * 2.0) / 64.0;
	if (save_dist >= 1)
	{
		*y_text = 0;
		return ;
	}
	save_dist = 1;
	wall_height = (int)(game->screen_height / 2 / save_dist);
	*y_text = (wheight - game->screen_height / 2) / *y_incrementer;
	*y_incrementer = (wall_height * 2) / (64.0 - *y_text * 2);
}

void	decide_texture(int orientation, t_game *game, int x, int y)
{
	if (orientation == 1)
		my_mlx_pixel_put(*game->img, x, y,
			text_pixel_put(game->texture_pos_x, game->y_text, game->text_w));
	else if (orientation == 2)
		my_mlx_pixel_put(*game->img, x, y,
			text_pixel_put(game->texture_pos_x, game->y_text, game->text_n));
	else if (orientation == 3)
		my_mlx_pixel_put(*game->img, x, y,
			text_pixel_put(game->texture_pos_x, game->y_text, game->text_s));
	else if (orientation == 4)
		my_mlx_pixel_put(*game->img, x, y,
			text_pixel_put(game->texture_pos_x, game->y_text, game->text_e));
	else if (orientation == 6)
		my_mlx_pixel_put(*game->img, x, y,
			text_pixel_put(game->texture_pos_x, game->y_text, game->text_d));
}

void	draw_line(t_game *game, int x, int orientation)
{
	double	y;
	double	y_incrementer;
	double	d;

	y = -1;
	y_incrementer = 0;
	get_text_start(game, &y_incrementer, game->save_dist, &game->y_text);
	while (++y < game->screen_height / 2 - game->wall_height)
		my_mlx_pixel_put(*game->img, x, y, game->ceilling_color);
	d = y;
	while (y < game->screen_height / 2 + game->wall_height)
	{
		d += y_incrementer;
		while (y < d && y < 720)
		{
			decide_texture(orientation, game, x, y);
			y++;
		}
		game->y_text++;
	}
	while (++y < game->screen_height)
		my_mlx_pixel_put(*game->img, x, y, game->floor_color);
}
