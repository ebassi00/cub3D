/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:33:05 by masebast          #+#    #+#             */
/*   Updated: 2022/12/09 14:59:46 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_draw_tile(t_game *game, double origin_x, double origin_y, int color)
{
	int	measure;
	int	index_x;
	int	index_y;

	measure = 20;
	index_y = 0;
	while (index_y < measure)
	{
		index_x = 0;
		while (index_x < measure)
		{
			if (origin_x + index_x < game->minimap->width && origin_y + index_y
				< game->minimap->height && origin_x + index_x >= 0
				&& origin_y + index_y >= 0)
				my_mlx_pixel_put(*game->minimap->img, origin_x + index_x,
					origin_y + index_y, color);
			index_x++;
		}
		index_y++;
	}
}

void	ft_slide_map(t_game *game)
{
	int		index_x;
	int		index_y;
	double	measure;

	measure = 20;
	index_y = 0;
	while (game->map[index_y])
	{
		index_x = 0;
		while (game->map[index_y][index_x])
		{
			if (game->map[index_y][index_x] == '1')
				ft_draw_tile(game, ft_x(game, index_x, measure),
					ft_y(game, index_y, measure), 0x303030);
			else if (game->map[index_y][index_x] == '0')
				ft_draw_tile(game, ft_x(game, index_x, measure),
					ft_y(game, index_y, measure), 0x101010);
			index_x++;
		}
		index_y++;
	}
}

void	ft_compose_map(t_game *game)
{
	int	scanner_x;
	int	scanner_y;

	ft_slide_map(game);
	scanner_x = 0;
	while (scanner_x <= game->minimap->width)
	{
		scanner_y = 0;
		while (scanner_y <= game->minimap->height)
		{
			if (scanner_x > (game->minimap->width / 2) - 4
				&& scanner_x < (game->minimap->width / 2) + 4
				&& scanner_y > (game->minimap->height / 2) - 4
				&& scanner_y < (game->minimap->height / 2) + 4)
				my_mlx_pixel_put(*game->minimap->img, scanner_x,
					scanner_y, 0x505050);
			scanner_y++;
		}
		scanner_x++;
	}
}

void	ft_init_minimap(t_game *game)
{
	game->minimap = malloc (sizeof(t_minimap));
	game->minimap->width = game->screen_width / 4.0;
	game->minimap->height = game->screen_height / 4.0;
	game->minimap->margin = 10.0;
	game->minimap->origin_x = game->minimap->margin;
	game->minimap->origin_y = game->screen_height - game->minimap->height
		- game->minimap->margin;
	game->minimap->mini_player_x = game->minimap->margin
		+ (game->minimap->width / 2.0);
	game->minimap->mini_player_y = game->screen_height - game->minimap->margin
		- (game->minimap->height / 2.0);
	game->minimap->img = malloc (sizeof(t_data));
	game->minimap->img->img = mlx_new_image(game->mlx,
			(int)game->minimap->width, (int)game->minimap->height);
	game->minimap->img->addr = mlx_get_data_addr(game->minimap->img->img,
			&game->minimap->img->bpp, &game->minimap->img->ll,
			&game->minimap->img->e);
	ft_compose_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->minimap->img->img,
		game->minimap->origin_x, game->minimap->origin_y);
	free(game->minimap->img->addr);
	free(game->minimap->img->img);
	free(game->minimap->img);
	free(game->minimap);
}

void	draw_minimap(t_game *game)
{
	ft_init_minimap(game);
}
