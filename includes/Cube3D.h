/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 17:30:06 by malebrun          #+#    #+#             */
/*   Updated: 2026/04/25 17:40:03 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H


typedef struct s_rgb
{
	int red;
	int	green;
	int	blue;
} t_rgb;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
} t_img;

typedef struct s_texture
{
	t_img	*north;
	t_img	*south;
	t_img	*east;
	t_img	*west;
} t_texture;

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
};
#endif
