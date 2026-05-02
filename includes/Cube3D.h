/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 17:30:06 by malebrun          #+#    #+#             */
/*   Updated: 2026/05/02 09:19:16 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"

# define WIDTH 1920
# define HEIGHT 1080

# define FORWARD 119
# define LEFT 97
# define RIGHT 100
# define DOWN 115
# define ESCP 65307
# define LSHIFT 65505
# define MOVESPEED 0.1
# define BUFFRUN 2
# define MOUSE_SENS 0.0001

typedef struct s_ray
{
	int		tex_x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
}	t_ray;

typedef struct s_dda
{
    int     map_x;
    int     map_y;
    double  side_dist_x;
    double  side_dist_y;
    double  delta_dist_x;
    double  delta_dist_y;
    double  perp_dist;
    int     step_x;
    int     step_y;
    int     side;
    int     hit;
}   t_dda;

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		endian;
	int		len;
	int		bpp;
}	t_img;

typedef struct s_texture
{
	t_img	no;
	t_img	so;
	t_img	ea;
	t_img	we;
}	t_texture;

typedef struct s_game
{
	char		**map;
	float		x;
	float		y;
	double		plane_x;
	double		plane_y;
	float		dx;
	float		dy;
	void		*mlxptr;
	void		*mlxwinptr;
	t_img		img;
	char		startdirection;
	int			is_running;
	t_rgb		fcolor;
	t_rgb		ccolor;
	t_texture	textures;
}	t_game;

void	print_error(char *message);
int		parse_file(t_game *game, char *name);
int		free_all(t_game *game);
int		ParseLine(char *line, t_game *game);
void    free2d(char **array);
int 	get_map(t_game *game, char **content, int i);
void    start(t_game *game);
int		handle_input(int keycode, void *param);
char    **ft_strdup2(char **array);
void    raycast(t_game *game);
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
int		get_pixel(t_game *game, t_ray *ray, t_dda *dda, int tex_y);
void	prep_dda(t_game *game, t_ray *ray, t_dda *dda);
void	exec_dda(t_game *game, t_dda *dda);
int		create_trgb(t_rgb *rgb);
int		handle_mouse(int x, int y, t_game *game);

#endif
