/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:46:19 by ebassi            #+#    #+#             */
/*   Updated: 2022/12/09 17:32:49 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_exit(char *str)
{
	ft_putstr_fd(str, 0);
	exit(0);
}

void	free_all(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game);
}

char	*ret_path(int j, int i, int k, char *str)
{
	char	*path;

	j = i;
	while (str[j])
	{
		if (str[j] == ' ')
			break ;
		j++;
	}
	path = malloc(sizeof(char) * (j - i + 1));
	while (i < j)
	{
		path[k] = str[i];
		i++;
		k++;
	}
	path[k] = '\0';
	free(str);
	return (path);
}
