/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 23:41:21 by malebrun          #+#    #+#             */
/*   Updated: 2026/05/02 07:36:04 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"

static int moveable(float x, float y, t_game *game)
{
    if (x < 0 || y < 0)
        return (0);
    int iy = (int)y;
    int ix = (int)x;
    
    int map_height = 0;
    while (game->map[map_height]) 
        map_height++;
    
    if (iy >= map_height)
        return (0);
        
    if (ix >= (int)ft_strlen(game->map[iy]))
        return (0);
        
    if (game->map[iy][ix] != '1' && game->map[iy][ix] != ' ')
        return (1);
    return (0);
}

static void move(int key, t_game *game)
{
    float   x;
    float   y;
    float   ms;

    ms = MOVESPEED + (BUFFRUN * game->is_running);
    x = 0;
    y = 0;
    if (key == FORWARD) {
        x = game->x + game->dx * ms;
        y = game->y + game->dy * ms;
    }
    else if (key == DOWN) {
        x = game->x - game->dx * ms;
        y = game->y - game->dy * ms;
    }
    else if (key == RIGHT) {
        x = game->x - game->dy * ms;
        y = game->y + game->dx * ms;
    }
    else if (key == LEFT) {
        x = game->x + game->dy * ms;
        y = game->y - game->dx * ms;
    }
    if (moveable(x, y, game)) {
        game->x = x;
        game->y = y;
        raycast(game);
    }
}

static void boolrun(t_game *game)
{
    if (game->is_running)
        game->is_running = 0;
    else
        game->is_running = 1;
}

int handle_input(int keycode, void *param)
{
    t_game  *game;

    game = (t_game *) param;
    if (keycode == ESCP)
        free_all(game);
    if (keycode == FORWARD)
        move(FORWARD, game);   
    if (keycode == DOWN)
        move(DOWN, game);
    if (keycode == LEFT)
        move(LEFT, game);  
    if (keycode == RIGHT)
        move(RIGHT, game);
    if (keycode == LSHIFT)
        boolrun(game);
    if (keycode == RANDOMIZE)
        set_random_texture(game);
    return (0);
}
