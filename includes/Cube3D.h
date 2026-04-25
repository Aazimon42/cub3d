/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 17:30:06 by malebrun          #+#    #+#             */
/*   Updated: 2026/04/25 18:43:03 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

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
	t_img	*no;
	t_img	*so;
	t_img	*ea;
	t_img	*we;
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
	t_rgb		*fcolor;
	t_rgb		*ccolor;
	t_texture	*textures;
}	t_game;
#endif
