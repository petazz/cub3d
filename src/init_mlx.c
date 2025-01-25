/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:23:47 by misaguir          #+#    #+#             */
/*   Updated: 2025/01/23 21:31:14 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

void	paint_all(t_cub *game, int x, int y)
{
	int	rgb_ceiling;
	int	rgb_floor;

	rgb_ceiling = rgb(game->arr_ceiling[0], game->arr_ceiling[1],
			game->arr_ceiling[2], 255);
	rgb_floor = rgb(game->arr_floor[0], game->arr_floor[1],
			game->arr_floor[2], 255);
	while (MAP_HEIGHT / 2 > y)
	{
		x = 0;
		while (MAP_WIDTH > x++)
			mlx_put_pixel(game->cub_img, x, y, rgb_ceiling);
		y++;
	}
	while (MAP_HEIGHT > y)
	{
		x = 0;
		while (MAP_WIDTH > x++)
			mlx_put_pixel(game->cub_img, x, y, rgb_floor);
		y++;
	}
}

void	init_mlx(t_cub *game)
{
	t_ray	ray[MAP_WIDTH];

	game->ray = ray;
	game->mlx = mlx_init(MAP_WIDTH,
			MAP_HEIGHT, "cub3D", false);
	game->cub_img = mlx_new_image(game->mlx, MAP_WIDTH, MAP_HEIGHT);
	init_torch(game);
	load_textures(game);
	paint_all(game, 0, 0);
	mlx_image_to_window(game->mlx, game->cub_img, 0, 0);
	ray_casting(game->ray, game);
	mlx_key_hook(game->mlx, &key_press, game);
	mlx_loop_hook(game->mlx, &mouse_move, game);
	mlx_loop_hook(game->mlx, &loop_animation, game);
	minimap(game);
	mlx_loop_hook(game->mlx, &draw_player, game);
	mlx_loop(game->mlx);
}
