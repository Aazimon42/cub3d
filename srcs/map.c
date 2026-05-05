/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 09:36:29 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/05 03:14:23 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"

int	check_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != ' ' && map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E'
				&& map[i][j] != 'W' && map[i][j] != 'D' && map[i][j] != '\n')
			{
				print_error("Invalid character in map\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_closed_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				if (i == 0 || !map[i + 1] || j == 0 || !map[i][j + 1]
					|| (int)ft_strlen(map[i - 1]) <= j || map[i - 1][j] == ' ' || map[i + 1][j] == ' '
					|| map[i][j - 1] == ' ' || (int)ft_strlen(map[i + 1]) <= j || map[i + 1][j] == ' ')
				{
					print_error("Map not closed\n");
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_player(t_game *game)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
			{
				game->startdirection = game->map[i][j];
				player_count++;
				game->x = j;
				game->y = i;
			}
			j++;
		}
		i++;
	}
	if (player_count != 1)
	{
		print_error("There should be exactly one player in the map\n");
		return (0);
	}
	return (1);
}

void	set_direction(t_game *game)
{
	if (game->startdirection == 'S')
	{
		game->dx = 0;
		game->dy = 1;
		game->plane_x = -0.66;
		game->plane_y = 0;
	}
	else if (game->startdirection == 'E')
	{
		game->dx = 1;
		game->dy = 0;
		game->plane_x = 0;
		game->plane_y = 0.66;
	}
	else if (game->startdirection == 'W')
	{
		game->dx = -1;
		game->dy = 0;
		game->plane_x = 0;
		game->plane_y = -0.66;
	}
}

int	get_map(t_game *game, char **content, int i)
{
	while (content[i] && content[i][0] == '\n')
		i++;
	if (!content[i])
		return (-1);
	game->map = ft_strdup2(content + i);
	if (!check_map(game->map))
		return (-1);
	if (!check_closed_map(game->map))
		return (-1);
	if (!check_player(game))
		return (-1);
	if (game->startdirection == 'N')
	{
		game->dx = 0;
		game->dy = -1;
		game->plane_x = 0.66;
		game->plane_y = 0;
	}
	else
		set_direction(game);
	return (0);
}
