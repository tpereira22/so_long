/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:20:53 by timartin          #+#    #+#             */
/*   Updated: 2022/11/24 13:20:55 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"

void    draw_img(t_win *win)
{
    int i;
    int j;

    i = 0;
    while (win->mapstr[i])
    {
        j = 0;
        while (win->mapstr[i][j])
        {
            if (win->mapstr[i][j] == '1')
                put_img(win, win->img->wall, j, i);
            else if (win->mapstr[i][j] == '0')
                put_img(win, win->img->back, j, i);
            else if (win->mapstr[i][j] == 'C')
                put_img(win, win->img->collect, j, i);
            else if (win->mapstr[i][j] == 'P')
                put_img(win, win->img->player, j, i);
            // else if (win->mapstr[i][j] == 'E')
            //     put_img(win, win->img->exit_c, j, i);
            j++;
        }
        i++;
    }
}