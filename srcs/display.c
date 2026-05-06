/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 09:36:08 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/06 21:26:47 by edi-maio         ###   ########.fr       */
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
	else if (dda->side == 1 && ray->ray_dir_y < 0)
		tex = &game->textures.no;
	if (dda->hit == 2)
		tex = &game->textures.door;
	dst = tex->addr + (tex_y * tex->len + ray->tex_x * (tex->bpp / 8));
	if (dda->hit == 2 && *(unsigned int *)dst == 16777215)
		return (get_door_color(game, dda->map_y, dda->map_x));
	color = *(unsigned int *)dst;
	return (color);
}

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = game->img.addr + (y * game->img.len + x * (game->img.bpp / 8));
	*(unsigned int *)dst = color;
}

int	set_data(t_game	*g)
{
	g->pccolor = create_trgb(&g->ccolor, g);
	g->pfcolor = create_trgb(&g->fcolor, g);
	g->textures.no.addr = mlx_get_data_addr(g->textures.no.img,
			&g->textures.no.bpp, &g->textures.no.len, &g->textures.no.endian);
	g->textures.so.addr = mlx_get_data_addr(g->textures.so.img,
			&g->textures.so.bpp, &g->textures.so.len, &g->textures.so.endian);
	g->textures.ea.addr = mlx_get_data_addr(g->textures.ea.img,
			&g->textures.ea.bpp, &g->textures.ea.len, &g->textures.ea.endian);
	g->textures.we.addr = mlx_get_data_addr(g->textures.we.img,
			&g->textures.we.bpp, &g->textures.we.len, &g->textures.we.endian);
	g->textures.door.addr = mlx_get_data_addr(g->textures.door.img,
			&g->textures.door.bpp, &g->textures.door.len,
			&g->textures.door.endian);
	g->mlxwinptr = mlx_new_window(g->mlxptr, WIDTH, HEIGHT, "Cub3D");
	if (!g->mlxwinptr)
		return (0);
	g->img.img = mlx_new_image(g->mlxptr, WIDTH, HEIGHT);
	if (!g->img.img)
		return (0);
	g->img.addr = mlx_get_data_addr(g->img.img, &g->img.bpp,
			&g->img.len, &g->img.endian);
	return (1);
}

void	start(t_game *game)
{
	if (!set_data(game))
	{
		print_error("Failed to initialize graphics\n", game);
		free_all(game);
	}
	mlx_put_image_to_window(game->mlxptr, game->mlxwinptr, game->img.img, 0, 0);
	mlx_hook(game->mlxwinptr, 17, 0, free_all, game);
	mlx_hook(game->mlxwinptr, 2, 1L << 0, handle_input, game);
	mlx_hook(game->mlxwinptr, 6, 1L << 6, handle_mouse, game);
	mlx_mouse_hide(game->mlxptr, game->mlxwinptr);
	mlx_loop_hook(game->mlxptr, raycast, game);
	mlx_loop(game->mlxptr);
}
