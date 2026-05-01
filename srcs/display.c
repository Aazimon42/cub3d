/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 21:19:10 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/01 23:41:16 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"


void    cast_rays(t_game *game)
{
    double  camera_x;
    double  ray_dir_x;
    double  ray_dir_y;
    double  plane_x;
    double  plane_y;
    int     x;

    plane_x = -game->dy * 0.66;
    plane_y = game->dx * 0.66;
    x = 0;
    while (x < WIDTH)
    {
        camera_x = 2 * x / (double)WIDTH - 1;
        ray_dir_x = game->dx + plane_x * camera_x;
        ray_dir_y = game->dy + plane_y * camera_x;

        dda(game, ray_dir_x, ray_dir_y, x);
        x++;
    }
}

void    start(t_game *game)
{
    void    *img;
    char    *imgptr;
    int     bpp;
    int     len;
    int     endian;

    game->mlxwinptr = mlx_new_window(game->mlxptr, WIDTH, HEIGHT, "Cub3D");
    if (!game->mlxwinptr)
        return ;
    img = mlx_new_image(game->mlxptr, WIDTH, HEIGHT);
    if (!img)
        return ;
    imgptr = mlx_get_data_addr(img, &bpp, &len, &endian);
    mlx_loop(game->mlxptr);
}
