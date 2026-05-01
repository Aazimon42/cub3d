/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 21:19:10 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/01 23:31:00 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"




void    start(t_game *game)
{
    void    *img;
    //char    *imgptr;
    //int     bpp;
    //int     len;
    //int     endian;

    game->mlxwinptr = mlx_new_window(game->mlxptr, 1920, 1080, "Cub3D");
    if (!game->mlxwinptr)
        return ;
    img = mlx_new_image(game->mlxptr, 1920, 1080);
    if (!img)
        return ;
    //imgptr = mlx_get_data_addr(img, &bpp, &len, &endian);
    mlx_hook(game->mlxwinptr, 17, 0, free_all_void, game);
    mlx_hook(game->mlxwinptr, 2, 1L << 0, handle_input, game);
    mlx_loop(game->mlxptr);
}