/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/12 15:50:44 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/03/29 14:51:06 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_keyhook(mlx_key_data_t keydata, void *data)
{
	t_game	*game;

	game = data;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP) || 
			mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_up();
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN) || 
			mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_down();
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT) || 
			mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left();
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT)|| 
			mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_right();
}

int main(int ac, char **av)
{
	t_game	game;
	mlx_t	*mlx;
	int		fd;

	if (ac != 2)
		error_msg("Program needs 2 arguments");
	ber_check(av[1]);
	fd = fd_check(av[1]);
	game.map = map_init(fd, &game);
	if (!(game.mlx = mlx_init(game.map->column_count * 64, game.map->row_count * 64, \
		"so_long", true)))
		error_msg("oops");
	render(&game.mlx, game.list, &game);
	mlx_key_hook(&game.mlx, &ft_keyhook, &game);
	mlx_loop(&game.mlx);
	return (EXIT_SUCCESS);
}

