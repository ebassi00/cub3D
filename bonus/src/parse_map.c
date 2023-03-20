/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:11:31 by ebassi            #+#    #+#             */
/*   Updated: 2022/12/09 17:40:30 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_things(t_game *game, int saved, int saved2, int fd)
{
	char	*trimmed_res;
	char	*res;

	res = get_next_line(fd);
	while (saved2 != saved)
	{
		free(res);
		res = get_next_line(fd);
		saved2++;
	}
	trimmed_res = ft_strtrim(res, "\n");
	game->width = (int)ft_strlen(trimmed_res);
	while (res != 0)
	{
		if ((int)ft_strlen(trimmed_res) > game->width)
			game->width = ft_strlen(trimmed_res);
		game->height++;
		free(res);
		res = get_next_line(fd);
	}
	game->saved = saved;
	free(trimmed_res);
	free(res);
}

int	get_width_height(t_game *game, int saved, char *parsing_map)
{
	int		fd;
	int		saved2;

	saved2 = 0;
	fd = open(parsing_map, O_RDONLY);
	if (!fd)
		return (0);
	get_things(game, saved, saved2, fd);
	close(fd);
	return (1);
}

int	is_begin_map(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1')
		return (1);
	return (0);
}

int	check_text(char *res, t_game *game)
{
	if (res[0] == 'N' && res[1] == 'O')
		game->map_textures->north_texture = ft_strtrim(&res[3], "\n");
	else if (res[0] == 'S' && res[1] == 'O')
		game->map_textures->south_texture = ft_strtrim(&res[3], "\n");
	else if (res[0] == 'W' && res[1] == 'E')
		game->map_textures->west_texture = ft_strtrim(&res[3], "\n");
	else if (res[0] == 'E' && res[1] == 'A')
		game->map_textures->east_texture = ft_strtrim(&res[3], "\n");
	else if (res[0] == 'F')
		game->map_textures->floor_color = ft_strtrim(&res[2], "\n");
	else if (res[0] == 'C')
		game->map_textures->ceilling_color = ft_strtrim(&res[2], "\n");
	else if (res[0] == 'D')
		game->map_textures->door_texture = ft_strtrim(&res[2], "\n");
	else if (res[0] == 'd')
		game->map_textures->open_door_texture = ft_strtrim(&res[2], "\n");
	else if (is_begin_map(res))
		return (0);
	return (1);
}

int	check_map(char *parsing_map, t_game *game)
{
	int		fd;
	char	*res;
	int		saved;

	fd = open(parsing_map, O_RDONLY);
	res = 0;
	saved = 0;
	if (fd == -1)
		ft_exit("Error\n");
	res = get_next_line(fd);
	while (res != 0)
	{
		if (!check_text(res, game))
			break ;
		free(res);
		res = get_next_line(fd);
		saved++;
	}
	free(res);
	close(fd);
	if (!check_text2(game))
		ft_exit("Error\n");
	if (get_width_height(game, saved, parsing_map))
		return (1);
	return (1);
}
