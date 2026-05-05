/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 09:37:04 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/05 07:34:51 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"

int	rrint(void)
{
	struct timeval		tv;
	static unsigned int	seed;

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

int	validrgb(t_rgb colors)
{
	if (colors.red < 0 || colors.red > 255 || colors.green < 0
		|| colors.green > 255 || colors.blue < 0 || colors.blue > 255)
	{
		print_error("colors should be between 0 and 255\n");
		return (0);
	}
	return (1);
}

void	get_limits(int line_h, int limits[2])
{
	limits[0] = -line_h / 2 + HEIGHT / 2;
	limits[1] = line_h / 2 + HEIGHT / 2;
	if (limits[0] < 0)
		limits[0] = 0;
	if (limits[1] >= HEIGHT)
		limits[1] = HEIGHT - 1;
}
