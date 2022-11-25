/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:45:43 by timartin          #+#    #+#             */
/*   Updated: 2022/11/25 14:45:52 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"

void    free_map(char **mapstr)
{
    int i;

    i = 0;
    while (mapstr[i])
    {
        free(mapstr[i]);
        i++;
    }
    free(mapstr);
}

int exit_game(t_win *win)
{
    free_map(win->mapstr);
    mlx_destroy_image(win->mlx_ptr, win->img->wall);
    mlx_destroy_image(win->mlx_ptr, win->img->back);
    mlx_destroy_image(win->mlx_ptr, win->img->player);
    mlx_destroy_image(win->mlx_ptr, win->img->collect);
    //mlx_destroy_image(win->mlx_ptr, win->img->exit_c);
    free(win->mlx_ptr);
    exit(0);
}

int read_key(int keycode, t_win *win)
{
    if (keycode == ESC)
        exit_game(win);
    return (0);
}