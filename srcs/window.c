/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:00:07 by timartin          #+#    #+#             */
/*   Updated: 2022/11/30 19:13:57 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"

void	put_img(t_win *win, void *img, int x, int y)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img, x * 64, y * 64);
}

void	get_img(t_win *win)
{
	win->img->back = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/back.xpm", &win->map->width, &win->map->height);
	win->img->wall = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/wall.xpm", &win->map->width, &win->map->height);
	win->img->collect = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/collect.xpm", &win->map->width, &win->map->height);
	win->img->exit_c = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/exit_c.xpm", &win->map->width, &win->map->height);
	win->img->exit_o = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/exit_o.xpm", &win->map->width, &win->map->height);
	win->img->player = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/ship_d.xpm", &win->map->width, &win->map->height);
	win->img->enemy = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/enemy.xpm", &win->map->width, &win->map->height);
}

void	game_window(t_win *win)
{
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window
		(win->mlx_ptr, win->map->width * 64, win->map->height * 64, "so_long");
	win->moves = 0;
	win->over = 0;
	win->over_lose = 0;
	get_img(win);
	draw_img(win);
}
