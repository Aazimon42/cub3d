/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 09:36:52 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/02 09:41:43 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"

void	init_ray(t_ray *ray, t_game *game, int x)
{
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->ray_dir_x = game->dx + game->plane_x * ray->camera_x;
	ray->ray_dir_y = game->dy + game->plane_y * ray->camera_x;
}

void	render_vertical_line(t_game *game, t_ray *ray, t_dda *dda, int x, int limits[2])
{
	int		y;
	int		color;
	double	step;
	double	tex_pos;
	int		line_h;

	step = 1.0 * 64 / line_h;
	line_h = (int)(HEIGHT / dda->perp_dist);
	tex_pos = (limits[0] - HEIGHT / 2 + line_h / 2) * step;
	y = -1;
	while (++y < HEIGHT)
	{
		if (y < limits[0])
			my_mlx_pixel_put(game, x, y, create_trgb(&game->ccolor));
		else if (y >= limits[0] && y <= limits[1])
		{
			color = get_pixel(game, ray, dda, (int)tex_pos & 63);
			my_mlx_pixel_put(game, x, y, color);
			tex_pos += step;
		}
		else
			my_mlx_pixel_put(game, x, y, create_trgb(&game->fcolor));
	}
}

void	draw_textured_column(t_game *game, t_ray *ray, t_dda *dda, int x)
{
	int		line_h;
	int		draw_limits[2];
	double	wall_x;

	line_h = (int)(HEIGHT / dda->perp_dist);
	draw_limits[0] = -line_h / 2 + HEIGHT / 2;
	draw_limits[1] = line_h / 2 + HEIGHT / 2;
	if (dda->side == 0)
		wall_x = game->y + dda->perp_dist * ray->ray_dir_y;
	else
		wall_x = game->x + dda->perp_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	ray->tex_x = (int)(wall_x * 64.0);
	render_vertical_line(game, ray, dda, x, draw_limits);
}

void	raycasting_logic(t_game *game, t_ray *ray, int x)
{
	t_dda	dda;

	prep_dda(game, ray, &dda);
	exec_dda(game, &dda);
	if (dda.side == 0)
		dda.perp_dist = (dda.side_dist_x - dda.delta_dist_x);
	else
		dda.perp_dist = (dda.side_dist_y - dda.delta_dist_y);
	draw_textured_column(game, ray, &dda, x);
}

void	raycast(t_game *game)
{
	int		i;
	t_ray	ray;

	i = 0;
	while (i < WIDTH)
	{
		init_ray(&ray, game, i);
		raycasting_logic(game, &ray, i);
		i++;
	}
	mlx_put_image_to_window(game->mlxptr, game->mlxwinptr, game->img.img, 0, 0);
}
