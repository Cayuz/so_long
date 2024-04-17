/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/20 15:53:36 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/04/17 17:47:25 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render(mlx_t *mlx, t_game *game)
{
	init_images(&game->images, mlx);
	background(mlx, game);
	render_map(game, game->images, mlx);
	set_depth(game->images);
}

void	background(mlx_t *mlx, t_game *game)
{
	int		x;
	int		y;
	int	i = 0;

	y = 0;
	while(game->array[i] && y < game->map->row_count)
	{
	x = 0;
	while(x < game->map->column_count)
	{
		if (mlx_image_to_window(mlx, game->images.floor,
				x * TILE, y * TILE) < 0)
			error_msg("failed to load image");
		x++;
	}
	y++;
	i++;
		
	}

}

void	render_map(t_game *game, t_image img, mlx_t *mlx)
{
	int		x;
	int		y;
	int		len;
	int		i = 0;

	y = 0;
	len = ft_strlen(game->array[i]);
	while(game->array[i])
	{
		printf("render = %s\n", game->array[i]);
		i++;
	}
	i = 0;
	while(game->array[i])
	{
		x = 0;
		while(x < len)
		{
			display_img(mlx, x, y, game->array[i][x], img);
			x++;
		}
		y++;
		i++;
	}
}

void	display_img(mlx_t *mlx, int x, int y, char character, t_image image)
{
	if (character == 'P')
	{
		if (mlx_image_to_window(mlx, image.player, x * TILE, y * TILE) < 0)
			error_msg("failed to load image");
	}
	else if(character == '1')
	{	
		if (mlx_image_to_window(mlx, image.wall, x * TILE, y * TILE) < 0)
			error_msg("failed to load image");
	}
	else if (character == 'C')
	{
		if (mlx_image_to_window(mlx, image.collect, x * TILE, y * TILE) < 0)
			error_msg("failed to load image");
	}
	else if (character == 'E')
	{
		if (mlx_image_to_window(mlx, image.exit, x * TILE, y * TILE) ||
		mlx_image_to_window(mlx, image.exit_closed, x * TILE, y * TILE) < 0)
			error_msg("failed to load image");
	}
}

void	set_depth(t_image images)
{
	instance_loop(1, images.floor);
	instance_loop(3, images.wall);
	instance_loop(3, images.exit_closed);
	instance_loop(3, images.collect);
	instance_loop(4, images.player);
	instance_loop(1, images.exit);
}
