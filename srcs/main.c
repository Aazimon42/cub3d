/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 18:33:25 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/02 00:27:49 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"

int main(int ac, char **av)
{
    t_game game;

    if (ac != 2)
    {
        print_error("Program takes one .cub file as argument\n");
        return (1);
    }
    if (parse_file(&game, av[1]) == -1)
    {
        free_all(&game);
        return (1);
    }
    start(&game);
    return (0);
}