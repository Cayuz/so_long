/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/20 15:53:36 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/03/20 17:49:42 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render(mlx_t *mlx, t_maplist *map)
{
	t_image *images;

	texture_init(mlx, images);
	background(mlx, map, images);
	traverse_map(map, images, mlx);
}

void	texture_init(mlx_t *mlx, t_image *image)
{
	player_texture(mlx, image);
	wall_texture(mlx, image);
	floor_texture(mlx, image);
	exit_texture(mlx, image);
	collectable_texture(mlx, image);
}

void	background(mlx_t *mlx, t_maplist *map, t_image *image)
{
	int	x;
	int y;
	t_maplist *temp;

	y = 0;
	temp = map;
	while(temp != NULL)
	{
		x = 0;
		while(temp->line[x] != '\0')
		{
			mlx_image_to_window(mlx, image->floor, x, y);
			x++;
		}
		y++;
		temp = temp->next;
	}
}

void	traverse_map(t_maplist *map_list, t_image *img, mlx_t *mlx)
{
	int			x;
	int			y;
	t_maplist	*temp;
	int	len;

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

void	display_img(mlx_t *mlx, int x, int y, char character, t_image *images)
{
	if (character == 'P')
		mlx_image_to_window(mlx, images->player, x , y);
	else if(character == '1')
		mlx_image_to_window(mlx, images->wall, x , y);
	else if(character == '0')
		mlx_image_to_window(mlx, images->floor, x , y);
	else if (character == 'C')
		mlx_image_to_window(mlx, images->collectable, x , y);
	else if (character == 'E')
		mlx_image_to_window(mlx, images->exit, x , y);
}
