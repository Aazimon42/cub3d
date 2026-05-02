/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 09:35:58 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/02 09:36:05 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"

void	prep_dda(t_game *game, t_ray *ray, t_dda *dda)
{
	dda->delta_dist_x = fabs(1 / ray->ray_dir_x);
	dda->delta_dist_y = fabs(1 / ray->ray_dir_y);
	dda->map_x = (int)game->x;
	dda->map_y = (int)game->y;
	dda->hit = 0;
	if (ray->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (game->x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - game->x) * dda->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (game->y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - game->y) * dda->delta_dist_y;
	}
}

void	exec_dda(t_game *game, t_dda *dda)
{
	while (dda->hit == 0)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		if (game->map[dda->map_y][dda->map_x] == '1')
			dda->hit = 1;
		if (dda->map_y < 0 || dda->map_x < 0 || !game->map[dda->map_y]
			|| dda->map_x >= (int)ft_strlen(game->map[dda->map_y]))
		{
			dda->hit = 1;
			break ;
		}
		if (game->map[dda->map_y][dda->map_x] == '1')
			dda->hit = 1;
	}
	if (dda->side == 0)
		dda->perp_dist = (dda->side_dist_x - dda->delta_dist_x);
	else
		dda->perp_dist = (dda->side_dist_y - dda->delta_dist_y);
}
