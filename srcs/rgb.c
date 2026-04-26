/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 17:54:39 by malebrun          #+#    #+#             */
/*   Updated: 2026/04/26 19:58:51 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"


static void skipto(char *line, int *i, char toskip)
{
	while (line[*i] && line[*i] != toskip)
		(*i)++;
	if (line[*i] == toskip)
		(*i)++;
}

static int isint(char *text, char after)
{
	int i = 0;
	int has_digit = 0;

	if (text[i] == ',')
		i++;
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

int	ParseLine(char *line, t_game *game)
{
	t_rgb colors;
	int i;

	i = 1;
	if (line[i] != ' ')
		return(0);
	if (!line[i] || !isint(&line[i], ','))
		return(0);
	colors.red = ft_atoi(&line[i]);
	skipto(line, &i, ',');
	if (!line[i] || !isint(&line[i], ','))
		return(0);
	colors.green = ft_atoi(&line[i]);
	skipto(line, &i, ',');
	if (!line[i] || !isint(&line[i], '\0'))
		return(0);
	colors.blue = ft_atoi(&line[i]);
	if (colors.red < 0 || colors.red > 255 || colors.green < 0
		|| colors.green > 255 || colors.blue < 0 || colors.blue > 255)
	{
		print_error("color value need to be in between 0 and 255");
		return (-1);
	}
	if (line[0] == 'F')
		game->fcolor = &colors;
	else 
		game->ccolor = &colors;
	return (1);
}

int ParseRGBLine(char **content, t_game *game, int i)
{
	while (content[i] && content[i][0] == '\n')
		i++;
	if (!content[i])
		return (-1);
	if (!(content[i][0] == 'F' && (ParseLine(content[i], game))))
		return (-1);
	i++;
	while (content[i] && content[i][0] == '\n')
		i++;
	if (!content[i])
		return (-1);
	if (!(content[i][0] == 'C' && (ParseLine(content[i], game))))
		return (-1);
	return (i + 1);
}
