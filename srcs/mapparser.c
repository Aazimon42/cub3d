/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 09:36:37 by edi-maio          #+#    #+#             */
/*   Updated: 2026/05/06 21:38:02 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"

int	check_images(t_game *game)
{
	if (!(game->textures.no.img && game->textures.so.img
			&& game->textures.ea.img && game->textures.we.img
			&& game->textures.door.img))
	{
		print_error("One or more texture missing\n", game);
		return (0);
	}
	if (game->textures.no.width != 64 || game->textures.no.height != 64
		|| game->textures.so.width != 64 || game->textures.so.height != 64
		|| game->textures.ea.width != 64 || game->textures.ea.height != 64
		|| game->textures.we.width != 64 || game->textures.we.height != 64
		|| game->textures.door.width != 64 || game->textures.door.height != 64)
	{
		print_error("Textures should be 64x64\n", game);
		return (0);
	}
	if (game->ccolor.red == -1 || game->ccolor.blue == -1
		|| game->ccolor.green == -1 || game->fcolor.red == -1
		|| game->fcolor.blue == -1 || game->fcolor.green == -1)
	{
		print_error("Color parsing error\n", game);
		return (0);
	}
	return (1);
}

int	get_texture(char *line, int i, t_game *game)
{
	t_img	img;

	if (ft_strncmp(line, "NO", 2) && ft_strncmp(line, "SO", 2)
		&& ft_strncmp(line, "EA", 2) && ft_strncmp(line, "WE", 2))
		return (0);
	while (line && line[i] && line[i] != '.')
		i++;
	img.img = mlx_xpm_file_to_image(game->mlxptr, line + i,
			&img.width, &img.height);
	if (!img.img)
		print_error("Invalid texture path\n", game);
	if (!ft_strncmp(line, "NO", 2) && !game->textures.no.img)
		game->textures.no = img;
	else if (!ft_strncmp(line, "SO", 2) && !game->textures.so.img)
		game->textures.so = img;
	else if (!ft_strncmp(line, "EA", 2) && !game->textures.ea.img)
		game->textures.ea = img;
	else if (!ft_strncmp(line, "WE", 2) && !game->textures.we.img)
		game->textures.we = img;
	else
	{
		mlx_destroy_image(game->mlxptr, img.img);
		print_error("Double texture\n", game);
	}
	return (1);
}

int	parse_lines(char **content, t_game *game)
{
	int	i;

	game->ccolor.red = -1;
	game->ccolor.blue = -1;
	game->ccolor.green = -1;
	game->fcolor.red = -1;
	game->fcolor.blue = -1;
	game->fcolor.green = -1;
	game->rgbmode = 0;
	game->is_running = 0;
	game->active = 0;
	i = 0;
	while (content[i])
	{
		while (content[i][0] == '\n')
			i++;
		if (!parse_line(content[i], game) && !get_texture(content[i], 0, game))
			return (-1);
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
	int		i;

	tmp = get_content(name);
	game->content = ft_split(tmp, '\n');
	free(tmp);
	if (!game->content || !game->content[0])
		return (-1);
	game->mlxptr = mlx_init();
	if (!game->mlxptr)
		return (-1);
	game->textures.door.img = mlx_xpm_file_to_image(game->mlxptr,
			"textures/door.xpm", &game->textures.door.width,
			&game->textures.door.height);
	i = parse_lines(game->content, game);
	if (!check_images(game) || i == -1 || get_map(game, game->content, i) == -1)
		return (-1);
	init_doors(game);
	return (0);
}
