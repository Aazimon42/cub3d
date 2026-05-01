/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 21:19:10 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/02 00:15:16 by edi-maio         ###   ########.fr       */
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

    game->mlxwinptr = mlx_new_window(game->mlxptr, WIDTH, HEIGHT, "Cub3D");
    if (!game->mlxwinptr)
        return ;
    img = mlx_new_image(game->mlxptr, WIDTH, HEIGHT);
    if (!img)
        return ;
    //imgptr = mlx_get_data_addr(img, &bpp, &len, &endian);
    mlx_hook(game->mlxwinptr, 17, 0, free_all, game);
    mlx_hook(game->mlxwinptr, 2, 1L << 0, handle_input, game);
    mlx_loop(game->mlxptr);
}
