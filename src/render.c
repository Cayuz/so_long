/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/20 15:53:36 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/04/18 16:04:32 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render(mlx_t *mlx, t_game *game)
{
	init_images(&game->images, mlx);
	background(mlx, game);
	render_map(game);
	set_depth(game->images);
}

void	background(mlx_t *mlx, t_game *game)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	while (game->array[i] && y < game->map->row_count)
	{
		x = 0;
		while (x < game->map->column_count)
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

void	render_map(t_game *game)
{
	int	x;
	int	y;
	int	len;
	int	i;

	i = 0;
	y = 0;
	len = ft_strlen(game->array[i]);
	while (game->array[i])
	{
		x = 0;
		while (x < len)
		{
			display_img(game, x, y, game->array[i][x]);
			x++;
		}
		y++;
		i++;
	}
}

void	display_img(t_game *game, int x, int y, char character)
{
	if (character == 'P')
	{
		if (mlx_image_to_window(game->mlx, game->images.player,
				x * TILE, y * TILE) < 0)
			error_msg("failed to load image");
	}
	else if (character == '1')
	{
		if (mlx_image_to_window(game->mlx, game->images.wall,
				x * TILE, y * TILE) < 0)
			error_msg("failed to load image");
	}
	else if (character == 'C')
	{
		if (mlx_image_to_window(game->mlx, game->images.collect,
				x * TILE, y * TILE) < 0)
			error_msg("failed to load image");
	}
	else if (character == 'E')
	{
		if (mlx_image_to_window(game->mlx, game->images.exit, x * TILE,
				y * TILE) || mlx_image_to_window(game->mlx,
				game->images.exit_closed, x * TILE, y * TILE) < 0)
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
