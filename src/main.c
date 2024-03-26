/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/12 15:50:44 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/03/26 16:22:29 by cavan-vl      ########   odam.nl         */
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
	game.map = map_init(fd, &game, game.map);
	if (!(mlx = mlx_init(game.map->column_count * 32, game.map->row_count * 32, \
		"so_long", false)))
		error_msg("oops");
	render(mlx, game.list, &game);
	return (EXIT_SUCCESS);
}
// static mlx_image_t* image;

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
// 	return (r << 24 | g << 16 | b << 8 | a);
// }

// void ft_randomize(void* param)
// {
// 	(void)param;
// 	uint32_t lightGreen = ft_pixel(144, 238, 144, 255); // Light green color

// 	for (uint32_t i = 0; i < image->width; ++i)
// 	{
// 		for (uint32_t y = 0; y < image->height; ++y)
// 			mlx_put_pixel(image, i, y, lightGreen);
// 	}
// }

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


	// mlx_t*	mlx;

	// if (!(mlx = mlx_init(WIDTH, HEIGHT, "so_long", true)))
	// {
	// 	puts(mlx_strerror(mlx_errno));
	// 	return(EXIT_FAILURE);
	// }
	// if (!(image = mlx_new_image(mlx, 128, 128)))
	// {
	// 	mlx_close_window(mlx);
	// 	puts(mlx_strerror(mlx_errno));
	// 	return(EXIT_FAILURE);
	// }
	// if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	// {
	// 	mlx_close_window(mlx);
	// 	puts(mlx_strerror(mlx_errno));
	// 	return(EXIT_FAILURE);
	// }
	// mlx_loop_hook(mlx, ft_randomize, mlx);
	// mlx_loop_hook(mlx, ft_keyhook, mlx);
	// mlx_loop(mlx);
	// mlx_terminate(mlx);