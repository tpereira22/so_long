/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:11:17 by timartin          #+#    #+#             */
/*   Updated: 2022/11/24 11:11:19 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"

int check_map_size(char **mapstr, t_map *map)
{
    int height;
    int width;
    int temp_width;

    height = 0;
    width = 0;
    temp_width = 0;
    while (mapstr[height])
    {
        width = 0;
        while (mapstr[height][width])
            width++;
        if (height && temp_width != width)
            return (0);
        temp_width = width;
        height++;
    }
    if (height < 3 || (height && height == width))
        return (0);
    map->height = height;
    map->width = width;
    return (1);
}

int check_walls(t_win win)
{
    int i;

    i = 0;
    while (i < win.map->width)
    {
        if (win.mapstr[0][i] != '1' || win.mapstr[win.map->height - 1][i] != '1')
            return(0);
        i++;
    }
    i = 0;
    while (i < win.map->height)
    {
        if (win.mapstr[i][0] != '1' || win.mapstr[i][win.map->width - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

int check_letters(char **mapstr, t_map *map)
{
    int i;
    int j;

    map->player = 0;
    map->collect = 0;
    map->exit = 0;
    i = 0;
    while (i < map->height - 1)
    {
        j = 0;
        while (j < map->width - 1)
        {
            if (mapstr[i][j] == 'P')
                map->player++;
            else if (mapstr[i][j] == 'C')
                map->collect++;
            else if (mapstr[i][j] == 'E')
                map->exit++;
            j++;
        }
        i++;
    }
    if (map->player != 1 || map->collect == 0 || map->exit != 1)
        return (0);
    return (1);
}

int check_errors(char **mapstr, t_map *map, t_win *win)
{
    int i;
    int j;

    if (!mapstr)
        return (0);
    i = 0;
    while (mapstr[i])
    {
        j = 0;
        while (mapstr[i][j])
        {
            if (mapstr[i][j] != '0' && mapstr[i][j] != '1' && mapstr[i][j] != 'C' && mapstr[i][j] != 'E' && mapstr[i][j] != 'P')
                return (0);
            j++;
        }
        i++;
    }
    if (check_map_size(mapstr, map) && check_walls(*win))
        return (1);
    return (0);
}