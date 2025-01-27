/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:01:20 by pgonzal2          #+#    #+#             */
/*   Updated: 2025/01/27 16:10:41 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

void	draw_rectangle(t_cub *game)
{
	int	x;
	int	y;

	x = game->rect_x;
	y = game->rect_y;
	while (y < game->rect_y + game->rect_heigth)
	{
		x = game->rect_x;
		while (x < game->rect_x + game->rect_width)
		{
			mlx_put_pixel(game->minimap, x, y, rgb(120, 120, 120, 255));
			x++;
		}
		y++;
	}
}

void	create_player(t_cub *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->player_img = mlx_new_image(game->mlx, 100, 100);
	while (x <= 10)
	{
		y = 0;
		while (y <= 10)
		{
			mlx_put_pixel(game->player_img, x, y, rgb(255, 0, 0, 255));
			y++;
		}
		x++;
	}
	mlx_image_to_window(game->mlx, game->player_img, 0, 0);
}

void	draw_player(void *data)
{
	int		player_x;
	int		player_y;
	double	scale_y;
	double	scale_x;
	t_cub	*game;

	game = (t_cub *)data;
	scale_x = (double)MINIMAP_WIDTH / game->max;
	scale_y = (double)MINIMAP_HEIGHT / game->count_map;
	player_x = (int)(game->x * scale_x);
	player_y = (int)(game->y * scale_y);
	game->player_img->instances[0].x = player_x;
	game->player_img->instances[0].y = player_y;
}

void	minimap(t_cub *game, int i, int j)
{
	game->minimap = mlx_new_image(game->mlx, MINIMAP_WIDTH, MINIMAP_HEIGHT);
	if (!game->minimap)
		error_msg("Error to upload the image\n", game);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
			{
				game->rect_x = j * (MINIMAP_WIDTH / game->max);
				game->rect_y = i * (MINIMAP_HEIGHT / game->count_map);
				game->rect_width = MINIMAP_WIDTH / game->max;
				game->rect_heigth = MINIMAP_HEIGHT / game->count_map;
				draw_rectangle(game);
			}
			j++;
		}
		i++;
	}
	mlx_image_to_window(game->mlx, game->minimap, 10, 10);
	create_player(game);
}
