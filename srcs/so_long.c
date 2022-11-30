/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:46:58 by timartin          #+#    #+#             */
/*   Updated: 2022/11/30 19:25:10 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

void	map_error(t_win *win)
{
	int	i;

	if (win->mapstr)
	{
		i = 0;
		while (win->mapstr[i])
		{
			free(win->mapstr[i]);
			i++;
		}
		free(win->mapstr);
	}
	exit(1);
}

int	ft_check_map_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == 'r' && str[i - 2] == 'e' && str[i - 3] == 'b'
		&& str[i - 4] == '.' && str[i - 5])
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_win	win;

	if (argc == 2 && ft_check_map_name(argv[1]))
	{
		win.mapstr = ft_read_map(argv[1]);
		win.map = malloc(sizeof(t_map));
		win.img = malloc(sizeof(t_img));
		if (check_map_format(win.mapstr, win.map, &win))
		{
			game_window(&win);
			mlx_key_hook(win.win_ptr, exit_esc, &win);
			mlx_hook(win.win_ptr, 02, (1L << 0), read_key, &win);
			mlx_hook(win.win_ptr, 17, 0, exit_game, &win);
			mlx_loop(win.mlx_ptr);
		}
		else
			map_error(&win);
	}
	else
	{
		ft_putstr_fd("Error\nInvalid Number of Arguments or Map File !\n", 1);
		exit(1);
	}
	return (0);
}
