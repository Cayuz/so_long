/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/20 15:53:36 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/04/04 19:35:55 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render(mlx_t *mlx, t_list *map, t_game *game)
{
	init_images(&game->images, mlx);
	background(mlx, game);
	render_map(map, game->images, mlx);
	set_depth(game->images);
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
					x * TILE, y * TILE) < 0)
				error_msg("failed to load image");
			x++;
		}
		y++;
		temp = temp->next;
	}
}

void	render_map(t_list *map_list, t_image img, mlx_t *mlx)
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
		mlx_image_to_window(mlx, image.player, x * TILE, y * TILE);
	else if(character == '1')
		mlx_image_to_window(mlx, image.wall, x * TILE, y * TILE);
	else if(character == '0')
		mlx_image_to_window(mlx, image.floor, x * TILE, y * TILE);
	else if (character == 'C')
		mlx_image_to_window(mlx, image.collect, x * TILE, y * TILE);
	else if (character == 'E')
		mlx_image_to_window(mlx, image.exit, x * TILE, y * TILE);
}

void	set_depth(t_image images)
{
	instance_loop(1, images.floor);
	instance_loop(2, images.wall);
	instance_loop(2, images.exit);
	instance_loop(2, images.collect);
	instance_loop(3, images.player);

}

void	instance_loop(int depth, mlx_image_t *image)
{
	size_t	i;

	i = 0;
	while(i < image->count)
	{
		mlx_set_instance_depth(&image->instances[i], depth);
		i++;
	}
}
