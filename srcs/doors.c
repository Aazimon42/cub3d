/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 01:36:40 by malebrun          #+#    #+#             */
/*   Updated: 2026/05/05 06:03:00 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"

static t_rgb    create_rrgb( void )
{
	t_rgb   rvalue;

	rvalue.red = rrint() % 256;
	rvalue.green = rrint() % 256;
	rvalue.blue = rrint() % 256;
	return (rvalue);
}

static t_door  createdoor(int y, int x)
{
    t_door  rvalue;

    rvalue.y = y;
    rvalue.x = x;
    rvalue.color = create_rrgb();
    return (rvalue);
}

void    init_doors(t_game *game)
{
    int i;
    int j;
    int count;
    int k;

    count = 0;
    i = -1;
    while(game->map[++i])
    {
        j = -1;
        while(game->map[i][++j])
            if (game->map[i][j] == 'D')
                count++;
    }
    game->door_count = count;
    game->doors = malloc(sizeof(t_door) * count);
    if (!game->doors)
        return ;
    i = -1;
    k = 0;
    while(game->map[++i])
    {
        j = -1;
        while(game->map[i][++j])
            if (game->map[i][j] == 'D')
                game->doors[k++] = createdoor(i, j);
    }
}

static int is_similar(t_rgb a, t_rgb b)
{
    int dr;
    int dg;
    int db;

    dr = a.red - b.red;
    dg = a.green - b.green;
    db = a.blue - b.blue;
    return ((dr * dr + dg * dg + db * db) < (67 * 67));
}

void    open_doors(t_game *game)
{
    int     i;
    float   dx;
    float   dy;

    i = 0;
    while (i < game->door_count)
    {
        dx = game->x - game->doors[i].x;
        dy = game->y - game->doors[i].y;
        if ((dx * dx + dy * dy) <= 8.0f
                && is_similar(game->doors[i].color, game->ccolor))
        {
            game->map[game->doors[i].y][game->doors[i].x] = '0';
            game->doors[i].x = -1;
            game->doors[i].y = -1;
        }
        i++;
    }
}