/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various_inits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:20:00 by ebassi            #+#    #+#             */
/*   Updated: 2022/12/09 17:28:23 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	deal_loop(t_game *game)
{
	deal_key(game);
	raycasting(game);
	return (0);
}

t_move	*init_move(void)
{
	t_move	*res;

	res = malloc (sizeof(t_move));
	res->a = 0;
	res->d = 0;
	res->s = 0;
	res->w = 0;
	res->arr_left = 0;
	res->arr_right = 0;
	return (res);
}

t_text	*ft_new_text(t_game *game, char *filename)
{
	t_text	*res;

	if (open(filename, O_RDONLY) == -1)
		ft_exit("Error\n");
	res = malloc (sizeof(t_text));
	res->img = mlx_xpm_file_to_image(game->mlx, filename, &res->w, &res->h);
	res->addr = mlx_get_data_addr(res->img, &res->bpp, &res->ll, &res->e);
	return (res);
}

void	init_text(t_game *game)
{
	game->text_n = ft_new_text(game, game->map_textures->north_texture);
	game->text_s = ft_new_text(game, game->map_textures->south_texture);
	game->text_w = ft_new_text(game, game->map_textures->west_texture);
	game->text_e = ft_new_text(game, game->map_textures->east_texture);
}

void	init_game2(t_game *game)
{
	game->pl_x = 0.0;
	game->pl_y = 0.0;
	game->p_angle = 0.0;
	game->texture_pos_x = 0;
	game->save_dist = 0;
	game->wall_height = 0;
	game->pl_dx = cos(deg_to_rad(game->p_angle));
	game->pl_dy = sin(deg_to_rad(game->p_angle));
	game->fov = 60.0;
	game->screen_width = 960.0;
	game->screen_height = 720.0;
	game->ray_hit->increment_angle = game->fov / game->screen_width;
}
