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

int rrint(void)
{
    struct timeval tv;
    static unsigned int seed;

    gettimeofday(&tv, NULL);

    seed ^= tv.tv_usec;
    seed = seed * 1103515245 + 12345;

    return (seed % 255);
}