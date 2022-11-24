/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:00:07 by timartin          #+#    #+#             */
/*   Updated: 2022/11/24 10:00:09 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"

void    get_img(t_win *win)
{
    win->img->back = mlx_xpm_file_to_image(win->mlx_ptr, "xpm/background.xpm", &win->map->width, &win->map->height);
}

void    game_window(t_win *win)
{
    win->mlx_ptr = mlx_init();
    win->win_ptr = mlx_new_window(win->mlx_ptr, win->map->width * 64, win->map->width * 64, "so_long");
    win->moves = 0;
    get_img(win);
}