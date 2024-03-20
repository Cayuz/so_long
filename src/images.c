/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/20 17:10:09 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/03/20 17:11:15 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_init(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*player;
	
	player = mlx_load_png("./sprites/foxdown.png");
	if (!player)
		error_msg("failed to load png");
	image->player = mlx_texture_to_image(mlx, player);
	mlx_delete_texture(player);
}

void	wall_init(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*wall;
	
	wall = mlx_load_png("./sprites/foxdown.png");
	if (!wall)
		error_msg("failed to load png");
	image->wall = mlx_texture_to_image(mlx, wall);
	mlx_delete_texture(wall);
}

void	floor_init(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*floor;
	
	floor = mlx_load_png("./sprites/foxdown.png");
	if (!floor)
		error_msg("failed to load png");
	image->floor = mlx_texture_to_image(mlx, floor);
	mlx_delete_texture(floor);
}

void	exit_init(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*exit;
	
	exit = mlx_load_png("./sprites/foxdown.png");
	if (!exit)
		error_msg("failed to load png");
	image->exit = mlx_texture_to_image(mlx, exit);
	mlx_delete_texture(exit);
}

void	collectable_init(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*collectable;
	
	collectable = mlx_load_png("./sprites/foxdown.png");
	if (!collectable)
		error_msg("failed to load png");
	image->collectable = mlx_texture_to_image(mlx, collectable);
	mlx_delete_texture(collectable);
}
