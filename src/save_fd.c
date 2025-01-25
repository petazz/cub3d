/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:01:50 by misaguir          #+#    #+#             */
/*   Updated: 2025/01/17 18:33:33 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

void	save_player(char c, int y, int x, t_cub *game)
{
	game->player_view = c;
	game->y = y + 0.5;
	game->x = x + 0.5;
	game->player++;
}

void	save_map(t_cub *game, char *file, int i, int j)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = ft_strdup("");
	game->map = (char **)malloc(sizeof(char *) * (game->count_map));
	if (!game->map)
		error_msg("Error allocated malloc\n", game);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
		{
			if (i == game->count_line + 1)
			{
				game->map[j] = ft_strdup(line);
				j++;
			}
			else
				i++;
		}
	}
	game->map[j] = NULL;
	close(fd);
}

void	read_fd(char *file, t_cub *game)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_msg("Error: Open File\n", NULL);
	line = ft_strdup("");
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			ft_check_line(line, game);
		if (game->count_data == 6)
		{
			if(ft_strlen(line) > game->max)
				game->max = ft_strlen(line);
			game->count_map++;
		}
		else
			game->count_line++;
	}
	close(fd);
}
