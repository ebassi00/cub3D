/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:54:15 by ebassi            #+#    #+#             */
/*   Updated: 2022/12/09 18:49:07 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	deg_to_rad(double deg)
{
	return (deg * PI / 180);
}

double	find_mod(double a, double b)
{
	double	mod;

	if (a < 0)
		mod = -a;
	else
		mod = a;
	if (b < 0)
		b = -b;
	while (mod >= b)
		mod = mod - b;
	if (a < 0)
		return (-mod);
	return (mod);
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
	game->face = get_img(game, "./textures/face.xpm");
	game->text_n = ft_new_text(game, game->map_textures->north_texture);
	game->text_s = ft_new_text(game, game->map_textures->south_texture);
	game->text_w = ft_new_text(game, game->map_textures->west_texture);
	game->text_e = ft_new_text(game, game->map_textures->east_texture);
	game->text_d = ft_new_text(game, game->map_textures->door_texture);
	game->text_open_d = ft_new_text(game,
			game->map_textures->open_door_texture);
}
