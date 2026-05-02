/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surprise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 08:38:02 by malebrun          #+#    #+#             */
/*   Updated: 2026/05/02 08:38:30 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D"

void    set_random_texture(t_game *game)
{
    struct timeval  tv;
    int             i;

    i = 0;
    while(game->texturesets[i])
        i++;
    if (i == 0)
        return ;
    gettimeofday(&tv, NULL);
    game->current = tv.tv_usec % i;
}