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



<<<<<<< HEAD
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
=======
>>>>>>> 759e8111e8f272d9b056183d62dd9dc09ff60181

void    start(t_game *game)
{
    void    *img;
    //char    *imgptr;
    //int     bpp;
    //int     len;
    //int     endian;

    game->mlxwinptr = mlx_new_window(game->mlxptr, WIDTH, HEIGHT, "Cub3D");
    if (!game->mlxwinptr)
        return ;
    img = mlx_new_image(game->mlxptr, WIDTH, HEIGHT);
    if (!img)
        return ;
    //imgptr = mlx_get_data_addr(img, &bpp, &len, &endian);
    mlx_hook(game->mlxwinptr, 17, 0, free_all_void, game);
    mlx_hook(game->mlxwinptr, 2, 1L << 0, handle_input, game);
    mlx_loop(game->mlxptr);
}
