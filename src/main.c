/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/12 15:50:44 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/03/28 19:42:52 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (!(mlx = mlx_init(game.map->column_count * 64, game.map->row_count * 64, \
		"so_long", true)))
		error_msg("oops");
	render(mlx, game.list, &game);
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}

// void ft_keyhook(void* param)
// {
// 	mlx_t* mlx = param;

// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		image->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		image->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		image->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		image->instances[0].x += 5;
// }
