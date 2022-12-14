/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:45:43 by timartin          #+#    #+#             */
/*   Updated: 2022/11/30 20:47:38 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"

void	free_map(char **mapstr)
{
	int	i;

	i = 0;
	while (mapstr[i])
	{
		free(mapstr[i]);
		i++;
	}
	free(mapstr);
}

int	exit_game(t_win *win)
{
	free_map(win->mapstr);
	mlx_destroy_image(win->mlx_ptr, win->img->wall);
	mlx_destroy_image(win->mlx_ptr, win->img->back);
	mlx_destroy_image(win->mlx_ptr, win->img->player);
	mlx_destroy_image(win->mlx_ptr, win->img->collect);
	mlx_destroy_image(win->mlx_ptr, win->img->exit_c);
	mlx_destroy_image(win->mlx_ptr, win->img->exit_o);
	free(win->mlx_ptr);
	exit(0);
}

int	exit_esc(int keycode, t_win *win)
{
	if (keycode == ESC)
		exit_game(win);
	return (0);
}

int	read_key(int keycode, t_win *win)
{
	if (win->over)
		exit_game(win);
	else if (win->over_lose)
		exit_game(win);
	else if (keycode == W)
		move_w(win);
	else if (keycode == A)
		move_a(win);
	else if (keycode == S)
		move_s(win);
	else if (keycode == D)
		move_d(win);
	return (0);
}
