/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:36:45 by timartin          #+#    #+#             */
/*   Updated: 2022/11/30 21:30:40 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"

void	print_moves(t_win *win)
{
	win->moves++;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(win->moves, 1);
	ft_putchar_fd(10, 1);
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
}

int	check_square(int height, int width)
{
	if (height < 3 || (height && height == width))
	{
		ft_putstr_fd("Error\nInvalid Map Size !\n", 1);
		return (0);
	}
	else
		return (1);
}

int	check_assets(char **mapstr, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height - 1)
	{
		j = -1;
		while (++j < map->width - 1)
		{
			if (mapstr[i][j] == 'P')
				map->player++;
			else if (mapstr[i][j] == 'C')
				map->collect++;
			else if (mapstr[i][j] == 'E')
			{
				map->exit++;
				map->exit_y = i;
				map->exit_x = j;
			}
		}
	}
	if (map->player != 1 || map->collect == 0 || map->exit != 1)
		return (0);
	else
		return (1);
}
