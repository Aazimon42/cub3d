/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 01:55:58 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/05 04:07:42 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"

static void    draw_minimap_cell(t_game *game, int x, int y, int color)
{
    int    i;
    int    j;

    i = 0;
    while (i < 10)
    {
        j = 0;
        while (j < 10)
            my_mlx_pixel_put(game, x + j++, y + i, color);
        i++;
    }
}

static void    draw_minimap_tiles(t_game *game, int ox, int oy)
{
    int    i;
    int    j;

    i = 0;
    while (i < MM_SIZE && game->map[oy + i])
    {
        j = 0;
        while (j < MM_SIZE && game->map[oy + i][ox + j])
        {
            if (game->map[oy + i][ox + j] == '1')
                draw_minimap_cell(game, j * 10, i * 10, 0x000000);
            else if (game->map[oy + i][ox + j] == 'D')
                draw_minimap_cell(game, j * 10, i * 10,
                    get_door_color(game, oy + i, ox + j));
            else
                draw_minimap_cell(game, j * 10, i * 10, 0xFFFFFF);
            j++;
        }
        i++;
    }
}

static void    draw_ray(t_game *game, int px, int py, float angle)
{
    int    k;

    k = 0;
    while (k < 20)
    {
        my_mlx_pixel_put(game,
            px + (int)(cosf(angle) * k),
            py + (int)(sinf(angle) * k),
            0x00FF00);
        k++;
    }
}

static void    draw_player(t_game *game, int px, int py)
{
    float    angle;
    int      i;
    int      j;

    angle = atan2f(game->dy, game->dx);
    i = -2;
    while (i <= 2)
    {
        j = -2;
        while (j <= 2)
            my_mlx_pixel_put(game, px + j++, py + i, 0xFF0000);
        i++;
    }
    draw_ray(game, px, py, angle - 0.5236f);
    draw_ray(game, px, py, angle + 0.5236f);
}

void    display_minimap(t_game *game)
{
    int    ox;
    int    oy;

    ox = (int)game->x - MM_SIZE / 2;
    oy = (int)game->y - MM_SIZE / 2;
    if (ox < 0)
        ox = 0;
    if (oy < 0)
        oy = 0;
    draw_minimap_tiles(game, ox, oy);
    draw_player(game,
        (int)((game->x - ox) * 10),
        (int)((game->y - oy) * 10));
}
