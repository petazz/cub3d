/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:18:41 by misaguir          #+#    #+#             */
/*   Updated: 2025/01/27 17:30:52 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

void	free_texture(t_cub *game)
{
	int	i;

	i = -1;
	if (game->texture_wall_e)
		mlx_delete_texture(game->texture_wall_e);
	if (game->texture_wall_n)
		mlx_delete_texture(game->texture_wall_n);
	if (game->texture_wall_w)
		mlx_delete_texture(game->texture_wall_w);
	if (game->texture_wall_s)
		mlx_delete_texture(game->texture_wall_s);
	if (game->torch)
	{
		while (++i < 80)
		{
			if (game->torch->frames[i])
				mlx_delete_texture(game->torch->frames[i]);
		}
		free(game->torch);
	}
	return ;
}

void	free_struc(t_cub *game)
{
	if (game->north)
		free(game->north);
	if (game->south)
		free(game->south);
	if (game->west)
		free(game->west);
	if (game->east)
		free(game->east);
	if (game->floor)
		free(game->floor);
	if (game->ceiling)
		free(game->ceiling);
	if (game->arr_ceiling)
		free(game->arr_ceiling);
	if (game->arr_floor)
		free(game->arr_floor);
	if (game->map)
		free_matrix(game->map);
	free_texture(game);
	return ;
}

void	error_msg(char *str, t_cub *game)
{
	if (game)
		free_struc(game);
	ft_putstr_fd(str, 2);
	exit(1);
}
