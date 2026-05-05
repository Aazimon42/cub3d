/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 09:36:58 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/05 06:40:41 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"

int	create_trgb(t_rgb *rgb, t_game *game)
{
	if (game->rgbmode)
	{
		rgb->red = rrint();
		rgb->green = rrint();
		rgb->blue = rrint();
	}
	return (0 << 24 | rgb->red << 16 | rgb->green << 8 | rgb->blue);
}

static void	skipto(char *line, int *i, char toskip)
{
	while (line[*i] && line[*i] != toskip)
		(*i)++;
	if (line[*i] == toskip)
		(*i)++;
}

static int	isint(char *text, char after)
{
	int	i;
	int	has_digit;

	i = 0;
	has_digit = 0;
	while (text[i] && text[i] == ' ')
		i++;
	while (text[i] && text[i] >= '0' && text[i] <= '9')
	{
		has_digit = 1;
		i++;
	}
	if (!has_digit)
		return (0);
	if (text[i] == after)
		return (1);
	return (0);
}

int	parse_line(char *line, t_game *game)
{
	t_rgb	colors;
	int		i;

	i = 1;
	if (line[i] != ' ')
		return (0);
	if (!line[i] || !isint(&line[i], ','))
		return (0);
	colors.red = ft_atoi(&line[i]);
	skipto(line, &i, ',');
	if (!line[i] || !isint(&line[i], ','))
		return (0);
	colors.green = ft_atoi(&line[i]);
	skipto(line, &i, ',');
	if (!line[i] || !isint(&line[i], '\0'))
		return (0);
	colors.blue = ft_atoi(&line[i]);
	if (colors.red < 0 || colors.red > 255 || colors.green < 0
		|| colors.green > 255 || colors.blue < 0 || colors.blue > 255)
	{
		print_error("color value need to be in between 0 and 255");
		return (0);
	}
	if (line[0] == 'F' && game->fcolor.red == -1)
		game->fcolor = colors;
	else if (line[0] == 'C' && game->ccolor.red == -1)
		game->ccolor = colors;
	else
		return (0);
	return (1);
}

void	gradient(t_game *game)
{
	int		target;
	float	t;
	int		steps;
	int		i;

	game->active = 1;
	target = rrint() << 16 | rrint() << 8 | rrint();
	steps = 20;
	i = 0;
	while (i <= steps)
	{
		t = (float)i / steps;
		game->ccolor.red = (int)(((game->ccolor.red) * (1 - t)
					+ (target >> 16 & 0xFF) * t));
		game->ccolor.green = (int)(((game->ccolor.green) * (1 - t)
					+ (target >> 8 & 0xFF) * t));
		game->ccolor.blue = (int)(((game->ccolor.blue) * (1 - t)
					+ (target & 0xFF) * t));
		game->pccolor = create_trgb(&game->ccolor, game);
		game->pfcolor = game->pccolor;
		raycast(game);
		mlx_do_sync(game->mlxptr);
		i++;
	}
	game->active = 0;
}
