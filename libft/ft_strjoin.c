/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:04:30 by edi-maio          #+#    #+#             */
/*   Updated: 2026/04/25 19:16:39 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;

	if (!s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	i = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	while (s1[0])
	{
		str[i] = s1[0];
		s1++;
		i++;
	}
	while (s2[0])
	{
		str[i] = s2[0];
		s2++;
		i++;
	}
	str[i] = 0;
	return (str);
}
