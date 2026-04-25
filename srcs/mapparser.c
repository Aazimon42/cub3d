/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:02:40 by malebrun          #+#    #+#             */
/*   Updated: 2026/04/25 17:53:37 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

char **get_content(char *name)
{
	int	fd;
	char *line;
	char *content;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	content = NULL;
	while(line)
	{
		content = ft_strjoin(content, line);
		free(line);
		if (!content)
			return (NULL);
		line = get_next_line(fd);
	}
	return (ft_split(content, '\n'));
}

int parse_file(char *name)
{
	char	**content;
	t_game	game;

	content = get_content(name);
	if (!content || !content[0])
		return (-1);

}
