/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:19:47 by timartin          #+#    #+#             */
/*   Updated: 2022/11/29 15:19:50 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"

void    move_w(t_win *win)
{
    img_w(win);
    if (win->mapstr[win->map->player_y - 1][win->map->player_x] != '1' && (win->mapstr[win->map->player_y - 1][win->map->player_x] != 'E' || !win->map->collect))
    {
        if (win->mapstr[win->map->player_y - 1][win->map->player_x] == 'C')
        {
            win->map->collect--;
            win->mapstr[win->map->player_y][win->map->player_x] = '0';
            win->map->player_y--;
            win->mapstr[win->map->player_y][win->map->player_x] = 'P';
        }
        else if (win->mapstr[win->map->player_y - 1][win->map->player_x] == '0')
        {
            win->mapstr[win->map->player_y][win->map->player_x] = '0';
            win->map->player_y--;
            win->mapstr[win->map->player_y][win->map->player_x] = 'P';
        }
        else
            win->over = 1;
        win->moves++;
        mlx_clear_window(win->mlx_ptr, win->win_ptr);
    }
    draw_img(win);
}

void    move_a(t_win *win)
{
    img_a(win);
    if (win->mapstr[win->map->player_y][win->map->player_x - 1] != '1' && (win->mapstr[win->map->player_y][win->map->player_x - 1] != 'E' || !win->map->collect))
    {
        if (win->mapstr[win->map->player_y][win->map->player_x - 1] == 'C')
        {
            win->map->collect--;
            win->mapstr[win->map->player_y][win->map->player_x] = '0';
            win->map->player_x--;
            win->mapstr[win->map->player_y][win->map->player_x] = 'P';
        }
        else if (win->mapstr[win->map->player_y][win->map->player_x - 1] == '0')
        {
            win->mapstr[win->map->player_y][win->map->player_x] = '0';
            win->map->player_x--;
            win->mapstr[win->map->player_y][win->map->player_x] = 'P';
        }
        else
            win->over = 1;
        win->moves++;
        mlx_clear_window(win->mlx_ptr, win->win_ptr);
    }
    draw_img(win);
}

void    move_s(t_win *win)
{
    img_s(win);
    if (win->mapstr[win->map->player_y + 1][win->map->player_x] != '1' && (win->mapstr[win->map->player_y + 1][win->map->player_x] != 'E' || !win->map->collect))
    {
        if (win->mapstr[win->map->player_y + 1][win->map->player_x] == 'C')
        {
            win->map->collect--;
            win->mapstr[win->map->player_y][win->map->player_x] = '0';
            win->map->player_y++;
            win->mapstr[win->map->player_y][win->map->player_x] = 'P';
        }
        else if (win->mapstr[win->map->player_y + 1][win->map->player_x] == '0')
        {
            win->mapstr[win->map->player_y][win->map->player_x] = '0';
            win->map->player_y++;
            win->mapstr[win->map->player_y][win->map->player_x] = 'P';
        }
        else
            win->over = 1;
        win->moves++;
        mlx_clear_window(win->mlx_ptr, win->win_ptr);
    }
    draw_img(win);
}

void    move_d(t_win *win)
{
    img_d(win);
    if (win->mapstr[win->map->player_y][win->map->player_x + 1] != '1' && (win->mapstr[win->map->player_y][win->map->player_x + 1] != 'E' || !win->map->collect))
    {
        if (win->mapstr[win->map->player_y][win->map->player_x + 1] == 'C')
        {
            win->map->collect--;
            win->mapstr[win->map->player_y][win->map->player_x] = '0';
            win->map->player_x++;
            win->mapstr[win->map->player_y][win->map->player_x] = 'P';
        }
        else if (win->mapstr[win->map->player_y][win->map->player_x + 1] == '0')
        {
            win->mapstr[win->map->player_y][win->map->player_x] = '0';
            win->map->player_x++;
            win->mapstr[win->map->player_y][win->map->player_x] = 'P';
        }
        else
            win->over = 1;
        win->moves++;
        mlx_clear_window(win->mlx_ptr, win->win_ptr);
    }
    draw_img(win);
}