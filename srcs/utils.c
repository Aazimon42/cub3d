/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 09:37:11 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/02 09:37:29 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"

void	print_error(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
}

char	**ft_strdup2(char **array)
{
	char	**dup;
	int		i;

	i = 0;
	while (array[i])
		i++;
	dup = malloc(sizeof(char *) * (i + 1));
	if (!dup)
		return (NULL);
	dup[i] = NULL;
	i = 0;
	while (array[i])
	{
		dup[i] = ft_strdup(array[i]);
		if (!dup[i])
		{
			free2d(dup);
			return (NULL);
		}
		i++;
	}
	return (dup);
}

void	free2d(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

int	free_all(t_game *game)
{
	if (!game)
		return (0);
	if (game->map)
		free2d(game->map);
	if (game->textures.no.img)
		mlx_destroy_image(game->mlxptr, game->textures.no.img);
	if (game->textures.so.img)
		mlx_destroy_image(game->mlxptr, game->textures.so.img);
	if (game->textures.ea.img)
		mlx_destroy_image(game->mlxptr, game->textures.ea.img);
	if (game->textures.we.img)
		mlx_destroy_image(game->mlxptr, game->textures.we.img);
	if (game->mlxwinptr)
		mlx_destroy_window(game->mlxptr, game->mlxwinptr);
	mlx_destroy_display(game->mlxptr);
	if (game->mlxptr)
		free(game->mlxptr);
	exit(0);
	return (0);
}
