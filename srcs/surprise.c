/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surprise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 09:37:04 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/05 06:44:30 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"

int rrint(void)
{
    struct timeval tv;
    static unsigned int seed;

    gettimeofday(&tv, NULL);

    seed ^= tv.tv_usec;
    seed = seed * 1103515245 + 12345;

    return (seed % 255);
}

void	boolrun(t_game *game)
{
	if (game->is_running)
		game->is_running = 0;
	else
		game->is_running = 1;
}

void	boolrgb(t_game *game)
{
	if (game->rgbmode)
		game->rgbmode = 0;
	else
		game->rgbmode = 1;
}