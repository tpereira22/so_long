/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:21:28 by timartin          #+#    #+#             */
/*   Updated: 2022/11/30 20:45:29 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"

void	img_w(t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img->player);
	win->img->player = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/ship_w.xpm", &win->map->width, &win->map->height);
}

void	img_a(t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img->player);
	win->img->player = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/ship_a.xpm", &win->map->width, &win->map->height);
}

void	img_s(t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img->player);
	win->img->player = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/ship_s.xpm", &win->map->width, &win->map->height);
}

void	img_d(t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img->player);
	win->img->player = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/ship_d.xpm", &win->map->width, &win->map->height);
}
