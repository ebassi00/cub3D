/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:27:32 by ebassi            #+#    #+#             */
/*   Updated: 2022/12/09 14:21:33 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*fill_matrix_wnumbers(char *map_line, char *res);

void	alloc_matrix(t_game *game)
{
	int	i;

	i = 0;
	game->map = malloc (sizeof(char **) * game->height + 1);
	game->map[game->height] = NULL;
	while (i < game->height)
	{
		game->map[i] = malloc (sizeof(char *) * game->width + 1);
		game->map[i][game->width] = '\0';
		i++;
	}
}

void	replace_spaces(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->height)
	{
		i = 0;
		while (i < game->width)
		{
			if (game->map[j][i] == ' ' || game->map[j][i] == 0)
				game->map[j][i] = '1';
			i++;
		}
		j++;
	}
}

int	prova(char *res, int fd, t_game *game)
{
	int	i;
	int	saved2;

	i = 0;
	saved2 = 0;
	res = get_next_line(fd);
	while (saved2 != game->saved)
	{
		free(res);
		res = get_next_line(fd);
		saved2++;
	}
	while (res != NULL)
	{
		game->map[i] = fill_matrix_wnumbers(game->map[i], res);
		i++;
		free(res);
		res = get_next_line(fd);
	}
	return (i);
}

int	fill_matrix(t_game *game, char *filename)
{
	int		fd;
	char	*res;
	int		i;

	res = NULL;
	if (!game->height || !game->width)
		return (0);
	alloc_matrix(game);
	fd = open(filename, O_RDONLY);
	i = prova(res, fd, game);
	replace_spaces(game);
	free(res);
	game->map[i] = NULL;
	return (1);
}

char	*fill_matrix_wnumbers(char *map_line, char *res)
{
	int	i;

	i = 0;
	while (res[i] && res[i] != '\n')
	{
		map_line[i] = res[i];
		i++;
	}
	return (map_line);
}
