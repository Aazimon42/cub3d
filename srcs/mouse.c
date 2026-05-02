/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 07:15:43 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/02 07:32:33 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"

void rotate_player(t_game *game, double angle)
{
    double old_dx = game->dx;
    game->dx = game->dx * cos(angle) - game->dy * sin(angle);
    game->dy = old_dx * sin(angle) + game->dy * cos(angle);
    
    double old_plane_x = game->plane_x;
    game->plane_x = game->plane_x * cos(angle) - game->plane_y * sin(angle);
    game->plane_y = old_plane_x * sin(angle) + game->plane_y * cos(angle);
}

int handle_mouse(int x, int y, t_game *game)
{
    int delta_x;
    double rot_speed;

    (void)y;
    delta_x = x - (WIDTH / 2);
    if (delta_x != 0)
    {
        rot_speed = delta_x * MOUSE_SENS;
        rotate_player(game, rot_speed);
        mlx_mouse_move(game->mlxptr, game->mlxwinptr, WIDTH / 2, HEIGHT / 2);
        raycast(game);
    }
    return (0);
}