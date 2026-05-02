/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 23:41:21 by malebrun          #+#    #+#             */
/*   Updated: 2026/05/01 23:41:23 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"

static int moveable(float x, float y, t_game *game)
{
    if (game->map[(int)y] && game->map[(int)y][(int)x] && game->map[(int)y][(int)x] != '1')
        return (1);
    return (0);
}

static void move(int angle, t_game *game)
{
    double theta;
    float   x;
    float   y;
    float   ms;

    theta = (game->dx + angle) * M_PI / 180.0;
    ms = MOVESPEED + (BUFFRUN * game->isrunning);
    x = game->x + cos(theta) * ms;
    y = game->y + sin(theta) * ms;
    if (moveable(x, y, game))
    {
        game->y = y;
        game->x = x;
    }
}

static void boolrun(t_game *game)
{
    if (game->isrunning)
        game->isrunning = 0;
    else
        game->isrunning = 1;
}

int handle_input(int keycode, void *param)
{
    t_game  *game;

    game = (t_game *) param;
    if (keycode == ESCP)
        free_all(game);
    if (keycode == FORWARD)
        move(0, game);   
    if (keycode == DOWN)
        move(180, game);
    if (keycode == LEFT)
        move(270, game);  
    if (keycode == RIGHT)
        move(90, game);
    if (keycode == LSHIFT)
        boolrun(game);
    return (1 * 1 *1 *1 *1 *1 *1);
}
