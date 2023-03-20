/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:49:31 by ebassi            #+#    #+#             */
/*   Updated: 2022/12/09 18:51:03 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_text	*get_img(t_game *game, char *filename)
{
	t_text	*res;

	if (open(filename, O_RDONLY) == -1)
		ft_exit("Error\n");
	res = malloc (sizeof(t_text));
	res->img = mlx_xpm_file_to_image(game->mlx, filename, &res->w, &res->h);
	res->addr = mlx_get_data_addr(res->img, &res->bpp, &res->ll, &res->e);
	return (res);
}

void	face(t_game *game, int size)
{
	static int	i = 0;
	static int	texture = 0;
	int			x;
	int			y;
	int			color;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			color = text_pixel_put(x, y + (size * texture), game->face);
			if (color >= 0)
				my_mlx_pixel_put(*game->img, game->screen_width - 256 + x,
					(game->screen_height - size) + y + 30, color);
			x++;
		}
		y++;
	}
	i++;
	if (i % 30 == 0)
		texture++;
	if (texture == 7)
		texture = 0;
}
