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

int get_path(t_win *win, char **mapstr, int y, int x)
{
    int exit_counter;
    int collect_counter;
    int i;
    int j;

    exit_counter = 0;
    collect_counter = 0;
    while (exit_counter != 1 || collect_counter != win->map->collect)
    {
        i = 0;
        while (mapstr[i])
        {
            j = 0;
            while (mapstr[i][j])
            {
                ft_putchar_fd(mapstr[i][j], 1);
                j++;
            }
            ft_putchar_fd(10, 1);
            i++;
        }
        ft_putchar_fd(10, 1);
        sleep(1);
        if (mapstr[y][x + 1] != '1')
        {
            if (mapstr[y][x + 1] == 'E')
            { 
                exit_counter = 1;
                x += 1;
            }
            else if (mapstr[y][x + 1] == 'C')
            {
                collect_counter += 1;
                x += 1;
            }
            else if (mapstr[y][x + 1] == '0')
            {
                mapstr[y][x + 1] = 'P';
                mapstr[y][x] = '2';
                x += 1;
            }
        }
        else if (mapstr[y - 1][x] != '1')
        {
            if (mapstr[y - 1][x] == 'E')
            {
                exit_counter = 1;
                y -= 1;
            }
            else if (mapstr[y - 1][x] == 'C')
            {
                mapstr[y - 1][x] = 'P';
                mapstr[y][x] = '2';
                collect_counter += 1;
                y -= 1;
            }
            else if (mapstr[y - 1][x] == '0')
            {
                mapstr[y - 1][x] = 'P';
                mapstr[y][x] = '2';
                y -= 1;
            }
        }
        else if (mapstr[y + 1][x] != '1')
        {
            if (mapstr[y + 1][x] == 'E')
            {
                exit_counter = 1;
                y += 1;
            }
            else if (mapstr[y + 1][x] == 'C')
            {   
                collect_counter += 1;
                y += 1;
            }
            else if (mapstr[y + 1][x] == '0')
            {
                mapstr[y + 1][x] = 'P';
                mapstr[y][x] = '2';
                y += 1;
            }
        }
        else if (mapstr[y][x - 1] != '1')
        {
            if (mapstr[y][x - 1] == 'E')
            {
                exit_counter = 1;
                x -= 1;
            }
            else if (mapstr[y][x - 1] == 'C')
            {
                collect_counter += 1;
                x -= 1;
            }
            else if (mapstr[y][x - 1] == '0')
            {
                mapstr[y][x - 1] = 'P';
                mapstr[y][x] = '2';
                x -= 1;
            }
        }
    }
    if (exit_counter == 1 && collect_counter == win->map->collect)
        return (1);
    else
        return (0);
}

int path_find(t_win *win, char **mapstr)
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
            if (mapstr[y][x] == 'P')
            {
                i = y;
                j = x;
                break;
            }
            x++;
        }
        y++;
    }
    ft_putnbr_fd(j, 1);
    ft_putchar_fd(10, 1);
    ft_putnbr_fd(i, 1);
    ft_putchar_fd(10, 1);
    if (get_path(win, mapstr, i, j))
        return (1);
    else
        return (0);
}
