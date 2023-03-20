/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:44:39 by ebassi            #+#    #+#             */
/*   Updated: 2022/12/09 14:36:47 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	val_height_width(t_game *game, int i)
{
	while (i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	get_p_angle(char c, t_game *game)
{
	if (c == 'N')
		game->p_angle = 270.0;
	else if (c == 'S')
		game->p_angle = 90.0;
	else if (c == 'W')
		game->p_angle = 180.0;
	else if (c == 'E')
		game->p_angle = 0.0;
}

int	val_pl(int i, t_game *game, int j)
{
	int	num_player;

	num_player = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'W' \
				|| game->map[i][j] == 'E')
			{
				get_p_angle(game->map[i][j], game);
				game->map[i][j] = '0';
				game->pl_x = j + 0.5;
				game->pl_y = i + 0.5;
				num_player++;
			}
			j++;
		}
		i++;
	}
	if (num_player != 1)
		return (0);
	return (1);
}

int	check_validity(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!val_height_width(game, i) || !val_pl(i, game, j))
	{
		free_all(game);
		return (0);
	}
	return (1);
}
