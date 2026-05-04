/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 09:36:37 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/05 01:31:31 by edi-maio         ###   ########.fr       */
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
	if (game->ccolor.red == -1 || game->ccolor.blue == -1
		|| game->ccolor.green == -1 || game->fcolor.red == -1
		|| game->fcolor.blue == -1 || game->fcolor.green == -1)
	{
		print_error("Color parsing error\n");
		return (0);
	}
	return (1);
}

int	get_textures(t_game *game, char *line)
{
	if (line && ft_strlen(line) > 2 && !ft_strncmp(line, "NO", 2)
			&& !game->textures.no.img)
		game->textures.no.img = mlx_xpm_file_to_image(game->mlxptr, line + 3,
				&game->textures.no.width, &game->textures.no.height);
	else if (line && ft_strlen(line) > 2 && !ft_strncmp(line, "SO", 2)
			&& !game->textures.so.img)
		game->textures.so.img = mlx_xpm_file_to_image(game->mlxptr, line + 3,
				&game->textures.so.width, &game->textures.so.height);
	else if (line && ft_strlen(line) > 2 && !ft_strncmp(line, "EA", 2)
			&& !game->textures.ea.img)
		game->textures.ea.img = mlx_xpm_file_to_image(game->mlxptr, line + 3,
				&game->textures.ea.width, &game->textures.ea.height);
	else if (line && ft_strlen(line) > 2 && !ft_strncmp(line, "WE", 2)
			&& !game->textures.we.img)
		game->textures.we.img = mlx_xpm_file_to_image(game->mlxptr, line + 3,
				&game->textures.we.width, &game->textures.we.height);
	else
		return (0);
	return (1);
}

int	parse_lines(char **content, t_game *game)
{
	int	i;

	game->textures.no.img = NULL;
	game->textures.so.img = NULL;
	game->textures.ea.img = NULL;
	game->textures.we.img = NULL;
	game->ccolor.red = -1;
	game->ccolor.blue = -1;
	game->ccolor.green = -1;
	game->fcolor.red = -1;
	game->fcolor.blue = -1;
	game->fcolor.green = -1;
	game->rgbmode = 0;
	i = 0;
	while (content[i])
	{
		while (content[i][0] == '\n')
			i++;
		if (!parse_line(content[i], game) && !get_textures(game, content[i]))
			return (0);
		if (game->textures.no.img && game->textures.so.img
			&& game->textures.ea.img && game->textures.we.img
			&& game->ccolor.red != -1 && game->fcolor.red != -1)
			break ;
		i++;
	}
	return (i + 1);
}

char	*get_content(char *name)
{
	int		fd;
	char	*line;
	char	*content;
	char	*tmp;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	content = NULL;
	while (line)
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

int	parse_file(t_game *game, char *name)
{
	char	*tmp;
	char	**content;
	int		i;

	tmp = get_content(name);
	content = ft_split(tmp, '\n');
	free(tmp);
	if (!content || !content[0])
		return (-1);
	game->mlxptr = mlx_init();
	if (!game->mlxptr)
		return (-1);
	i = parse_lines(content, game);
	if (i == -1 || !check_images(game))
		return (-1);
	if (get_map(game, content, i) == -1)
		return (-1);
	free2d(content);
	return (0);
}
