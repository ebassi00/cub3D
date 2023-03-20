/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:00:14 by ebassi            #+#    #+#             */
/*   Updated: 2022/12/09 18:49:43 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../libft/libft.h"
# include "../../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

# define PI 3.141592653589793238
# define MOV_SPEED 0.07
# define ROT_SPEED 3
# define FOV 60
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ARR_LEFT 123
# define ARR_RIGHT 124
# define SHIFT 257

typedef struct s_ray {
	double	increment_angle;
	int		ray_precision;
	double	x;
	double	y;
}	t_ray;

typedef struct s_move {
	int	w;
	int	s;
	int	a;
	int	d;
	int	arr_left;
	int	arr_right;
	int	shift;
	int	open_door;
}	t_move;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		e;
}	t_data;

typedef struct s_text {
	int		w;
	int		h;
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		e;
}	t_text;

typedef struct s_textures {
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	char	*door_texture;
	char	*open_door_texture;
	char	*floor_color;
	char	*ceilling_color;
}	t_textures;

typedef struct s_minimap {
	int				width;
	int				height;
	double			margin;
	double			origin_x;
	double			origin_y;
	double			mini_player_x;
	double			mini_player_y;
	struct s_data	*img;
}	t_minimap;

typedef struct s_game {
	char				**map;
	void				*mlx;
	void				*win;
	int					height;
	int					width;
	double				radius;
	double				screen_width;
	double				screen_height;
	double				save_dist;
	int					saved;
	int					texture_pos_x;
	int					wall_height;
	int					flag;
	int					y_text;
	int					ceilling_color;
	int					floor_color;
	double				pl_x;
	double				pl_y;
	double				pl_dx;
	double				pl_dy;
	double				p_angle;
	double				fov;
	struct s_ray		*ray_hit;
	struct s_textures	*map_textures;
	struct s_data		*img;
	struct s_move		*move;
	struct s_minimap	*minimap;
	struct s_minimap	*cat;
	t_text				*face;
	t_text				*text_n;
	t_text				*text_s;
	t_text				*text_w;
	t_text				*text_e;
	t_text				*text_d;
	t_text				*text_open_d;
}	t_game;

int			check_map(char *parsing_map, t_game *game);
int			fill_matrix(t_game *game, char *filename);
int			check_cub(char *filename);
void		free_all(t_game *game);
int			ft_exit(char *str);
int			check_validity(t_game *game);
t_textures	*init_textures(void);
t_ray		*init_ray(void);
void		ft_init_img(t_game *game);
void		my_mlx_pixel_put(t_data img, int x, int y, int color);
t_data		*init_data(void);
double		deg_to_rad(double deg);
void		draw_line(t_game *game, int x, int orientation);
void		ft_init_minimap(t_game *game);
void		draw_minimap(t_game *game);
int			text_pixel_put(int x, int y, t_text *text);
void		ft_mouse(t_game *game);
void		ft_rotate(t_game *game, double dir);
void		ft_close_all_doors(t_game *game);
double		ft_y(t_game *game, double index, int measure);
double		ft_x(t_game *game, double index, int measure);
int			ft_find_ray_x(t_game *game, float increase, float start_angle);
int			ft_find_ray_y(t_game *game, float increase, float start_angle);
int			ft_check_on_map(t_game *game, int angle_x, int angle_y);
double		find_mod(double a, double b);
double		deg_to_rad(double deg);
t_move		*init_move(void);
t_text		*ft_new_text(t_game *game, char *filename);
void		init_text(t_game *game);
t_game		*init_game(char *parsing_map);
int			deal_key(t_game *game);
void		ft_rotate(t_game *game, double dir);
void		ft_move(t_game	*game, double move_x, double move_y);
int			ft_off(int key, t_game *game);
int			ft_on(int key, t_game *game);
int			ft_door(t_game *game);
int			deal_loop(t_game *game);
void		raycasting(t_game *game);
void		get_distance(t_game *game, double *rays, double ray_angle);
int			get_orientation(t_game *game, double ray_angle, double *rays,
				int flag);
void		get_ceilling(t_game *game);
void		get_floor(t_game *game);
int			check_color(char *str);
char		*check_path(char *str);
char		*ret_path(int j, int i, int k, char *str);
void		check_textures(t_game *game);
int			check_text2(t_game *game);
void		face(t_game *game, int size);
t_text		*get_img(t_game *game, char *filename);

#endif