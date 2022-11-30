/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:20:53 by timartin          #+#    #+#             */
/*   Updated: 2022/11/30 20:53:17 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"

void	draw_moves(t_win *win)
{
	char	*str;

	str = ft_itoa(win->moves);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 20, 20, 0xffffff, "Moves: ");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 60, 20, 0xffffff, str);
	free(str);
}

void	draw_exit(t_win *win, int x, int y)
{
	if (win->map->collect)
		put_img(win, win->img->exit_c, x, y);
	else
		put_img(win, win->img->exit_o, x, y);
}

void	draw_player(t_win *win, int x, int y)
{
	win->map->player_x = x;
	win->map->player_y = y;
	if (win->over)
	{
		put_img(win, win->img->back, x, y);
		mlx_string_put
			(win->mlx_ptr, win->win_ptr, 20, 40, 0xffffff, "YOU WIN !");
	}
	else if (win->over_lose)
	{
		put_img(win, win->img->back, x, y);
		mlx_string_put
			(win->mlx_ptr, win->win_ptr, 20, 40, 0xffffff, "YOU LOSE !");
	}
	else
		put_img(win, win->img->player, x, y);
}

void	draw_img(t_win *win)
{
	int	i;
	int	j;

	i = -1;
	while (win->mapstr[++i])
	{
		j = -1;
		while (win->mapstr[i][++j])
		{
			if (win->mapstr[i][j] == '1')
				put_img(win, win->img->wall, j, i);
			else if (win->mapstr[i][j] == '0')
				put_img(win, win->img->back, j, i);
			else if (win->mapstr[i][j] == 'C')
				put_img(win, win->img->collect, j, i);
			else if (win->mapstr[i][j] == 'P')
				draw_player(win, j, i);
			else if (win->mapstr[i][j] == 'E')
				draw_exit(win, j, i);
			else if (win->mapstr[i][j] == 'X')
				put_img(win, win->img->enemy, j, i);
		}
	}
	draw_moves(win);
}
