/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:09:34 by ebassi            #+#    #+#             */
/*   Updated: 2022/12/09 18:47:53 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_orientation(t_game *game, double ray_angle, double *rays, int flag)
{
	int	dx;
	int	dy;

	dx = rays[0] - cos(deg_to_rad(ray_angle)) / game->ray_hit->ray_precision;
	dy = rays[1] - sin(deg_to_rad(ray_angle)) / game->ray_hit->ray_precision;
	if (flag == 1)
		return (6);
	if (dy == (int)rays[1] && dx < (int)rays[0])
		return (1);
	else if (dy == (int)rays[1] && dx > (int)rays[0])
		return (2);
	else if (dx == (int)rays[0] && dy < (int)rays[1])
		return (3);
	else if (dx == (int)rays[0] && dy > (int)rays[1])
		return (4);
	return (5);
}

void	get_distance(t_game *game, double *rays, double ray_angle)
{
	double	distance;

	distance = sqrt(pow(game->pl_x - rays[0], 2)
			+ pow(game->pl_y - rays[1], 2));
	distance = distance * cos(deg_to_rad(ray_angle - game->p_angle));
	game->save_dist = distance;
	if (distance < 1)
		distance = 1;
	game->wall_height = (int)(game->screen_height / 2 / distance);
}

void	check_textures(t_game *game)
{
	game->map_textures->north_texture
		= check_path(game->map_textures->north_texture);
	game->map_textures->south_texture
		= check_path(game->map_textures->south_texture);
	game->map_textures->west_texture
		= check_path(game->map_textures->west_texture);
	game->map_textures->east_texture
		= check_path(game->map_textures->east_texture);
	if (!game->map_textures->north_texture
		|| !game->map_textures->south_texture
		|| !game->map_textures->west_texture
		|| !game->map_textures->east_texture)
		ft_exit("Error\n");
	if (!check_color(game->map_textures->floor_color)
		|| !check_color(game->map_textures->ceilling_color))
		ft_exit("Error\n");
}

int	ft_door(t_game *game)
{
	if (game->map[(int)game->pl_y + 1][(int)game->pl_x] == 'd')
		game->map[(int)game->pl_y + 1][(int)game->pl_x] = 'D';
	else if (game->map[(int)game->pl_y][(int)game->pl_x + 1] == 'd')
		game->map[(int)game->pl_y][(int)game->pl_x + 1] = 'D';
	else if (game->map[(int)game->pl_y - 1][(int)game->pl_x] == 'd')
		game->map[(int)game->pl_y - 1][(int)game->pl_x] = 'D';
	else if (game->map[(int)game->pl_y][(int)game->pl_x - 1] == 'd')
		game->map[(int)game->pl_y][(int)game->pl_x - 1] = 'D';
	if (game->map[(int)game->pl_y + 1][(int)game->pl_x] == 'D')
		game->map[(int)game->pl_y + 1][(int)game->pl_x] = 'd';
	else if (game->map[(int)game->pl_y][(int)game->pl_x + 1] == 'D')
		game->map[(int)game->pl_y][(int)game->pl_x + 1] = 'd';
	else if (game->map[(int)game->pl_y - 1][(int)game->pl_x] == 'D')
		game->map[(int)game->pl_y - 1][(int)game->pl_x] = 'd';
	else if (game->map[(int)game->pl_y][(int)game->pl_x - 1] == 'D')
		game->map[(int)game->pl_y][(int)game->pl_x - 1] = 'd';
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
		ft_exit("Error\nInvalid number of arguments!");
	game = init_game(argv[1]);
	fill_matrix(game, argv[1]);
	if (!check_validity(game))
		ft_exit("Error\nNon valid map\n");
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 960, 720, "Wolfenstein 3D");
	game->img = init_data();
	ft_init_img(game);
	ft_init_minimap(game);
	init_text(game);
	get_ceilling(game);
	get_floor(game);
	mlx_hook(game->win, 2, 0, ft_on, game);
	mlx_hook(game->win, 3, 0, ft_off, game);
	mlx_loop_hook(game->mlx, deal_loop, game);
	mlx_loop(game->mlx);
	free_all(game);
	return (1);
}
