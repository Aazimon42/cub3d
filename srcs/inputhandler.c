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

#define FORWARD 119
#define LEFT 97
#define RIGHT 100
#define DOWN 115
#define ESCP 65307

int handle_input(int keycode, void *param)
{
    t_game  *game;

    game = (t_game *) param;
    if (keycode == ESCP)
        free_all(game);
    if (keycode == FORWARD)
        printf("devant");    
    if (keycode == DOWN)
        printf("derriere");
    if (keycode == LEFT)
        printf("gauche");    
    if (keycode == RIGHT)
        printf("droite");
    return (1 * 1 *1 *1 *1 *1 *1);
} 