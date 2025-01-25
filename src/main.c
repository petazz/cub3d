/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:24:40 by misaguir          #+#    #+#             */
/*   Updated: 2025/01/17 18:35:13 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

static void	init_cub(t_cub *game)
{
	ft_bzero(game, sizeof(t_cub));
}

int	main(int argc, char **argv)
{
	t_cub	game;

	init_cub(&game);
	if (argc != 2)
		error_msg("Error: Arguments Incorrect\n", NULL);
	check_extension(argv[1]);
	read_fd(argv[1], &game);
	check_info(&game);
	valid_info(game.ceiling, &game);
	valid_info(game.floor, &game);
	game.arr_ceiling = valid_numbers(game.ceiling, &game, 0);
	game.arr_floor = valid_numbers(game.floor, &game, 0);
	save_map(&game, argv[1], 0, 0);
	check_caracter_map(game.map, &game);
	check_valid_position_player(game.map, &game);
	check_map(game.map, &game, 0, 0);
	set_paths(&game);
	game.radian_view = set_view(&game);
	init_mlx(&game);
	free_struc(&game);
}
