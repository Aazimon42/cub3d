/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 17:30:06 by malebrun          #+#    #+#             */
/*   Updated: 2026/05/01 23:35:35 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
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
	int			fov;
	float		dx;
	float		dy;
	void		*mlxptr;
	void		*mlxwinptr;
	char		startdirection;
	t_rgb		fcolor;
	t_rgb		ccolor;
	t_texture	textures;
}	t_game;

void	print_error(char *message);
int		parse_file(t_game *game, char *name);
void    free_all(t_game *game);
int		ParseLine(char *line, t_game *game);
void    free2d(char **array);
int 	get_map(t_game *game, char **content, int i);
void    start(t_game *game);

#endif
