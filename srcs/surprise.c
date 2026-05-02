/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surprise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 09:37:04 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/02 09:37:47 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"

void	set_random_texture(t_game *game)
{
	struct timeval  tv;
	int			 i;

	i = 0;
	while(game->texturesets[i])
		i++;
	if (i == 0)
		return ;
	gettimeofday(&tv, NULL);
	game->current = tv.tv_usec % i;
}
