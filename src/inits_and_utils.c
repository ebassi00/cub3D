/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:02:16 by ebassi            #+#    #+#             */
/*   Updated: 2022/12/07 18:08:45 by ebassi           ###   ########.fr       */
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

void	my_mlx_pixel_put(t_data img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.ll + x * (img.bpp / 8));
	*(unsigned int *)dst = color;
}

t_data	*init_data(void)
{
	t_data	*res;

	res = malloc (sizeof(t_data));
	res->addr = 0;
	res->bpp = 0;
	res->e = 0;
	res->img = 0;
	res->ll = 0;
	return (res);
}
