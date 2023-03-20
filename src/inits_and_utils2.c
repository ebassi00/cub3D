/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_and_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:38:54 by ebassi            #+#    #+#             */
/*   Updated: 2022/12/09 16:01:43 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_cub(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
	{
		if (filename[i] == '.')
		{
			if (filename[i + 1] == 'c' && filename[i + 2] \
				== 'u' && filename[i + 3] == 'b' && !filename[i + 4])
				return (1);
			else
				break ;
		}
		i++;
	}
	return (0);
}

t_textures	*init_textures(void)
{
	t_textures	*res;

	res = malloc(sizeof(t_textures));
	res->ceilling_color = 0;
	res->east_texture = 0;
	res->floor_color = 0;
	res->north_texture = 0;
	res->south_texture = 0;
	res->west_texture = 0;
	return (res);
}

t_ray	*init_ray(void)
{
	t_ray	*res;

	res = malloc(sizeof(t_ray));
	res->increment_angle = 0;
	res->x = 0;
	res->y = 0;
	res->ray_precision = 256;
	return (res);
}

void	ft_init_img(t_game *game)
{
	game->img->img = mlx_new_image(game->mlx,
			(int)game->screen_width, (int)game->screen_height);
	game->img->addr = mlx_get_data_addr(game->img->img,
			&game->img->bpp, &game->img->ll, &game->img->e);
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
