/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:55:58 by ebassi            #+#    #+#             */
/*   Updated: 2022/12/09 18:50:30 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_game2(t_game *game)
{
	game->radius = 10.0 / 8.0;
	game->pl_x = 0.0;
	game->pl_y = 0.0;
	game->p_angle = 0.0;
	game->save_dist = 0.0;
	game->wall_height = 0;
	game->texture_pos_x = 0;
	game->flag = 0;
	game->pl_dx = cos(deg_to_rad(game->p_angle));
	game->pl_dy = sin(deg_to_rad(game->p_angle));
	game->fov = 60.0;
	game->screen_width = 960.0;
	game->screen_height = 720.0;
	game->ray_hit->increment_angle = game->fov / game->screen_width;
	game->y_text = 0;
	game->floor_color = 0;
	game->ceilling_color = 0;
}

t_game	*init_game(char *parsing_map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->ray_hit = init_ray();
	game->map_textures = init_textures();
	game->move = init_move();
	game->mlx = 0;
	game->win = 0;
	game->map = 0;
	game->saved = 0;
	game->height = 0;
	game->width = 0;
	init_game2(game);
	if (check_cub(parsing_map))
		check_map(parsing_map, game);
	else
		ft_exit("Error\nNon valid argument / non valid map\n");
	check_textures(game);
	return (game);
}

void	draw_image(t_game *game, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < 128)
	{
		j = 0;
		while (j < 128)
		{
			my_mlx_pixel_put(*game->img, x + j, y + i, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

int	deal_loop(t_game *game)
{
	ft_close_all_doors(game);
	mlx_mouse_hide();
	deal_key(game);
	raycasting(game);
	draw_minimap(game);
	ft_mouse(game);
	return (0);
}

char	*check_path(char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] == '.')
			return (ret_path(j, i, k, str));
		else
			return (0);
	}
	return (0);
}
