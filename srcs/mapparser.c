/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:02:40 by malebrun          #+#    #+#             */
/*   Updated: 2026/04/26 19:10:26 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"

int	check_images(t_game *game)
{
	if (!(game->textures.no.img && game->textures.so.img
		&& game->textures.ea.img && game->textures.we.img))
	{
		print_error("One or more texture missing\n");
		return (0);
	}
	if (game->textures.no.width != 64 || game->textures.no.height != 64
		|| game->textures.so.width != 64 || game->textures.so.height != 64
		|| game->textures.ea.width != 64 || game->textures.ea.height != 64
		|| game->textures.we.width != 64 || game->textures.we.height != 64)
	{
		print_error("Textures should be 64x64\n");
		return (0);
	}
	return (1);
}

int	get_textures(t_game *game, char **content)
{
	int	i;

	i = 0;
	game->textures.no.img = NULL;
	game->textures.so.img = NULL;
	game->textures.ea.img = NULL;
	game->textures.we.img = NULL;
	while (content[i] && content[i][0] == '\n')
		i++;
	if (content[i] && ft_strlen(content[i]) > 2 && !ft_strncmp(content[i], "NO", 2))
		game->textures.no.img = mlx_xpm_file_to_image(game->mlxptr, content[i] + 3,
			&game->textures.no.width, &game->textures.no.height);
	i++;
	while (content[i] && content[i][0] == '\n')
		i++;
	if (content[i] && ft_strlen(content[i]) > 2 && !ft_strncmp(content[i], "SO", 2))
		game->textures.so.img = mlx_xpm_file_to_image(game->mlxptr, content[i] + 3,
			&game->textures.so.width, &game->textures.so.height);
	i++;
	while (content[i] && content[i][0] == '\n')
		i++;
	if (content[i] && ft_strlen(content[i]) > 2 && !ft_strncmp(content[i], "EA", 2))
		game->textures.ea.img = mlx_xpm_file_to_image(game->mlxptr, content[i] + 3,
			&game->textures.ea.width, &game->textures.ea.height);
	i++;
	while (content[i] && content[i][0] == '\n')
		i++;
	if (content[i] && ft_strlen(content[i]) > 2 && !ft_strncmp(content[i], "WE", 2))
		game->textures.we.img = mlx_xpm_file_to_image(game->mlxptr, content[i] + 3,
			&game->textures.we.width, &game->textures.we.height);
	i++;
	return (i);
}

char *get_content(char *name)
{
	int	fd;
	char *line;
	char *content;
	char *tmp;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	content = NULL;
	while(line)
	{
		tmp = content;
		content = ft_strjoin(content, line);
		free(line);
		free(tmp);
		if (!content)
			return (NULL);
		line = get_next_line(fd);
	}
	close(fd);
	return (content);
}

int parse_file(t_game *game, char *name)
{
	char	*tmp;
	char	**content;
	int		i;

	tmp = get_content(name);
	content = ft_split(tmp, '\n');
	free(tmp);
	if (!content || !content[0])
		return (-1);
	printf("content good\n");
	game->mlxptr = mlx_init();
	if (!game->mlxptr)
		return (-1);
	game->mlxwinptr = NULL;
	i = get_textures(game, content);
	if (!check_images(game))
		return (-1);
	printf("textures good\n");
	game->map = content;
	ParseRGBLine(content, game, i);
	printf("%d, %d, %d\n", game->fcolor->red, game->fcolor->green, game->fcolor->blue);
	free2d(content);
	return (0);
}
