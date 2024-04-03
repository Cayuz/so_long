/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/12 15:50:44 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/04/03 18:39:43 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_keyhook(mlx_key_data_t keydata, void *data)
{
	t_game	*game;

	game = data;
	(void) keydata;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP) || 
			mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_up(game, game->array);
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN) || 
			mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_down(game, game->array);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT) || 
			mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left(game, game->array);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT)|| 
			mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_right(game, game->array);
}

int main(int ac, char **av)
{
	t_game	game;
	int		fd;

	if (ac != 2)
		error_msg("Program needs 2 arguments");
	ber_check(av[1]);
	fd = fd_check(av[1]);
	game.map = map_init(fd, &game);
	if (!(game.mlx = mlx_init(game.map->column_count * 64, game.map->row_count * 64, \
		"so_long", true)))
		error_msg("oops");
	render(game.mlx, game.list, &game);
	game.array = list_to_array(game.list, game.map);
	mlx_key_hook(game.mlx, &ft_keyhook, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}

