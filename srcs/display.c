/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 21:19:10 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/02 09:21:21 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"

int	get_pixel(t_game *game, t_ray *ray, t_dda *dda, int tex_y)
{
	char	*dst;
	int		color;
	t_img	*tex;

	if (dda->side == 0 && ray->ray_dir_x > 0)
		tex = &game->textures.ea;
	else if (dda->side == 0 && ray->ray_dir_x < 0)
		tex = &game->textures.we;
	else if (dda->side == 1 && ray->ray_dir_y > 0)
		tex = &game->textures.so;
	else
		tex = &game->textures.no;
    dst = tex->addr + (tex_y * tex->len + ray->tex_x * (tex->bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = game->img.addr + (y * game->img.len + x * (game->img.bpp / 8));
	*(unsigned int*)dst = color;
}

void    start(t_game *game)
{
    game->textures.no.addr = mlx_get_data_addr(game->textures.no.img, &game->textures.no.bpp, &game->textures.no.len, &game->textures.no.endian);
    game->textures.so.addr = mlx_get_data_addr(game->textures.so.img, &game->textures.so.bpp, &game->textures.so.len, &game->textures.so.endian);
    game->textures.ea.addr = mlx_get_data_addr(game->textures.ea.img, &game->textures.ea.bpp, &game->textures.ea.len, &game->textures.ea.endian);
    game->textures.we.addr = mlx_get_data_addr(game->textures.we.img, &game->textures.we.bpp, &game->textures.we.len, &game->textures.we.endian);
    game->mlxwinptr = mlx_new_window(game->mlxptr, WIDTH, HEIGHT, "Cub3D");
    if (!game->mlxwinptr)
        return ;
    game->img.img = mlx_new_image(game->mlxptr, WIDTH, HEIGHT);
    if (!game->img.img)
        return ;
    game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.len, &game->img.endian);
    mlx_put_image_to_window(game->mlxptr, game->mlxwinptr, game->img.img, 0, 0);
    mlx_hook(game->mlxwinptr, 17, 0, free_all, game);
    mlx_hook(game->mlxwinptr, 2, 1L << 0, handle_input, game);
    mlx_mouse_hide(game->mlxptr, game->mlxwinptr);
    mlx_hook(game->mlxwinptr, 6, 1L << 6, handle_mouse, game);
    raycast(game);
    mlx_loop(game->mlxptr);
}
