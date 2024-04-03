/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/20 15:53:36 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/04/03 14:47:29 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render(mlx_t *mlx, t_list *map, t_game *game)
{
	init_images(&game->images, mlx);
	background(mlx, game);
	traverse_map(map, game->images, mlx);
}

void	background(mlx_t *mlx, t_game *game)
{
	int		x;
	int		y;
	t_list	*temp;

	y = 0;
	temp = game->list;
	while(temp != NULL && y < game->map->row_count)
	{
		x = 0;
		while(x < game->map->column_count)
		{
			if (mlx_image_to_window(mlx, game->images.floor,
					x * TILE_SIZE, y * TILE_SIZE) < 0)
				error_msg("failed to load image");
			x++;
		}
		y++;
		temp = temp->next;
	}
}

void	traverse_map(t_list *map_list, t_image img, mlx_t *mlx)
{
	int		x;
	int		y;
	int		len;
	t_list	*temp;

	y = 0;
	len = ft_strlen(map_list->line);
	temp = map_list;
	while(temp != NULL)
	{
		x = 0;
		while(x < len)
		{
			display_img(mlx, x, y, temp->line[x], img);
			x++;
		}
		y++;
		temp = temp->next;
	}
}

void	display_img(mlx_t *mlx, int x, int y, char character, t_image image)
{
	if (character == 'P')
		mlx_image_to_window(mlx, image.player, x * TILE_SIZE, y * TILE_SIZE);
	else if(character == '1')
		mlx_image_to_window(mlx, image.wall, x * TILE_SIZE, y * TILE_SIZE);
	else if(character == '0')
		mlx_image_to_window(mlx, image.floor, x * TILE_SIZE, y * TILE_SIZE);
	else if (character == 'C')
		mlx_image_to_window(mlx, image.collect, x * TILE_SIZE, y * TILE_SIZE);
	else if (character == 'E')
		mlx_image_to_window(mlx, image.exit, x * TILE_SIZE, y * TILE_SIZE);
}
