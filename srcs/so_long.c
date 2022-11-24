/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:46:58 by timartin          #+#    #+#             */
/*   Updated: 2022/11/02 15:47:00 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

void    map_error(t_win *win)
{
    if (win->mapstr)
        free(win->mapstr);
    write(1, "Error\nInvalid Map", 17);
    exit(1);
}

int ft_check_map(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    if (str[i - 1] == 'r' && str[i - 2] == 'e' && str[i - 3] == 'b' && str[i - 4] == '.' && str[i - 5])
        return (1);
    else
        return (0);
}

int main(int argc, char **argv)
{
    t_win win;

    if (argc == 2 && ft_check_map(argv[1]))
    {
        win.mapstr = ft_read_map(argv[1]);
        win.map = malloc(sizeof(t_map));
        win.img = malloc(sizeof(t_img));
        if (check_errors(win.mapstr, win.map, &win))
        {
            game_window(&win);
        }
        else
            map_error(&win);
    }
    else 
    {
        write(1, "Invalid Number of Arguments or Map File !", 41);
        write(1, "\n", 1);
        exit(1);
    }
    return(0);
}
