/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/20 17:10:09 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/03/26 15:58:10 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player(mlx_t *mlx, t_image *image)
{
	image->textures.player = mlx_load_png("./sprites/foxdown.png");
	if (!image->textures.player)
		error_msg("failed to load png");
	image->player = mlx_texture_to_image(mlx, image->textures.player);
	mlx_delete_texture(image->textures.player);
}

void	walls(mlx_t *mlx, t_image *image)
{
	image->textures.wall = mlx_load_png("./sprites/wall.png");
	if (!image->textures.wall)
		error_msg("failed to load png");
	image->wall = mlx_texture_to_image(mlx, image->textures.wall);
	mlx_delete_texture(image->textures.wall);
	}

void	floors(mlx_t *mlx, t_image *image)
{
	image->textures.floor = mlx_load_png("./sprites/grass.png");
	if (!image->textures.floor)
		error_msg("failed to load png");
	image->floor = mlx_texture_to_image(mlx, image->textures.floor);
	mlx_delete_texture(image->textures.floor);
}

void	exits(mlx_t *mlx, t_image *image)
{
	image->textures.exit = mlx_load_png("./sprites/exit.png");
	if (!image->textures.exit)
		error_msg("failed to load png");
	image->exit = mlx_texture_to_image(mlx, image->textures.exit);
	mlx_delete_texture(image->textures.exit);
}

void	collect(mlx_t *mlx, t_image *image)
{
	image->textures.collectable = mlx_load_png("./sprites/collectable.png");
	if (!image->textures.collectable)
		error_msg("failed to load png");
	image->collectable = mlx_texture_to_image(mlx, image->textures.collectable);
	mlx_delete_texture(image->textures.collectable);
}
