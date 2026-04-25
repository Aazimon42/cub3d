/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 18:36:11 by edi-maio          #+#    #+#             */
/*   Updated: 2026/04/25 18:38:12 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"

void	print_error(char *message)
{
    write(2, "Error\n", 6);
    write(2, message, ft_strlen(message));
}

void    free2d(char **array)
{
    int i;

    if (!array)
        return;
    i = 0;
    while (array[i])
        free(array[i++]);
    free(array);
}

void    free_all(t_game *game)
{
    if (game->map)
        free2d(game->map);
    if (game->textures)
    {
        if (game->textures->no)
            mlx_destroy_image(game->mlxptr, game->textures->no->img);
        if (game->textures->so)
            mlx_destroy_image(game->mlxptr, game->textures->so->img);
        if (game->textures->ea)
            mlx_destroy_image(game->mlxptr, game->textures->ea->img);
        if (game->textures->we)
            mlx_destroy_image(game->mlxptr, game->textures->we->img);
        free(game->textures);
    }
    if (game->mlxwinptr)
        mlx_destroy_window(game->mlxptr, game->mlxwinptr);
    if (game->mlxptr)
        free(game->mlxptr);
}