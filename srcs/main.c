/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 09:36:20 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/06 21:36:55 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2 || (ft_strlen(av[1]) < 4
			|| ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 4)))
	{
		print_error("Program takes one .cub file as argument\n", NULL);
		return (1);
	}
	ft_bzero(&game, sizeof(t_game));
	if (parse_file(&game, av[1]) == -1)
	{
		free_all(&game);
		return (1);
	}
	start(&game);
	return (0);
}
