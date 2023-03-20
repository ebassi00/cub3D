/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:59:37 by masebast          #+#    #+#             */
/*   Updated: 2022/12/09 14:19:41 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_close_all_doors(t_game *game)
{
	int	index_line;
	int	index_row;

	index_line = 0;
	while (game->map[index_line])
	{
		index_row = 0;
		while (game->map[index_line][index_row])
		{
			if (game->map[index_line][index_row] == 'd'
				&& ((int)game->pl_x > index_row + 1
					|| (int)game->pl_x < index_row - 1)
				&& ((int)game->pl_y > index_line + 1
					|| (int)game->pl_y < index_line - 1))
					game->map[index_line][index_row] = 'D';
			index_row++;
		}
		index_line++;
	}
}
