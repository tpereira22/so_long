/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:01:27 by timartin          #+#    #+#             */
/*   Updated: 2022/11/28 15:01:29 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "so_long.h"
#include "../libft/libft.h"

void    map_cpy(t_win *win)
{
    int i;
    int j;

    win->mapcpy = malloc((win->map->height + 1) * sizeof(char *));
    if(!win->mapcpy)
        return ;
    i = 0;
    while (win->mapstr[i])
    {
        j = 0;
        win->mapcpy[i] = malloc((win->map->width + 1) * sizeof(char *));
        while (win->mapstr[i][j])
        {
            win->mapcpy[i][j] = win->mapstr[i][j];
            j++;
        }
        win->mapcpy[i][j] = '\0';
        i++;
    }
    win->mapcpy[i] = '\0';
}

void    get_path(char **mapcpy, int y, int x)
{
    // int i;
    // int j;

    // i = 0;
    // while (mapcpy[i])
    // {
    //     j = 0;
    //     while (mapcpy[i][j])
    //     {
    //         ft_putchar_fd(mapcpy[i][j], 1);
    //         j++;
    //     }
    //     ft_putchar_fd(10, 1);
    //     i++;
    // }
    // ft_putchar_fd(10, 1);
    // sleep(1);
    if (mapcpy[y][x] && (mapcpy[y][x + 1] == '0' || mapcpy[y][x + 1] == 'C'))
    {
        mapcpy[y][x + 1] = 'P';
        get_path(mapcpy, y, x + 1);
    }
    if (mapcpy[y][x] && (mapcpy[y][x - 1] == '0' || mapcpy[y][x - 1] == 'C'))
    {
        mapcpy[y][x - 1] = 'P';
        get_path(mapcpy, y, x - 1);
    }
    if (mapcpy[y][x] && (mapcpy[y + 1][x] == '0' || mapcpy[y + 1][x] == 'C'))
    {
        mapcpy[y + 1][x] = 'P';
        get_path(mapcpy, y + 1, x);
    }
    if (mapcpy[y][x] && (mapcpy[y - 1][x] == '0' || mapcpy[y - 1][x] == 'C'))
    {
        mapcpy[y - 1][x] = 'P';
        get_path(mapcpy, y - 1, x);
    }
}

int path_find(t_win *win)
{
    int y;
    int x;
    int i;
    int j;

    y = 0;
    while (y < win->map->height)
    {
        x = 0;
        while (x < win->map->width)
        {
            if (win->mapstr[y][x] == 'P')
            {
                i = y;
                j = x;
                break;
            }
            x++;
        }
        y++;
    }
    map_cpy(win);
    get_path(win->mapcpy, i, j);
    y = 0;
    while (win->mapcpy[y])
    {
        x = 0;
        while (win->mapcpy[y][x])
        {
            if (win->mapcpy[y][x] == 'C')
                return (0);
            x++;
        }
        y++;
    }
    if (win->mapcpy[win->map->exit_y][win->map->exit_x + 1] == 'P' ||
        win->mapcpy[win->map->exit_y][win->map->exit_x - 1] == 'P' ||
        win->mapcpy[win->map->exit_y + 1][win->map->exit_x] == 'P' ||
        win->mapcpy[win->map->exit_y - 1][win->map->exit_x] == 'P')
        return (1);
    return (0);
}
