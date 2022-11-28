/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:10:47 by timartin          #+#    #+#             */
/*   Updated: 2022/11/02 18:10:48 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define ESC  65307
# define S      115
# define D      100
# define W      119
# define A      97

typedef struct s_img
{
    void    *back;
    void    *wall;
    void    *player;
    void    *collect;
    void    *exit_c;
    void    *exit_o;

}   t_img;

typedef struct s_map
{
    int height;
    int width;
    int player;
    int collect;
    int exit;
}   t_map;

typedef struct s_win
{
    void    *mlx_ptr;
    void    *win_ptr;
    char    **mapstr;
    t_map   *map;
    t_img   *img;
    int     moves;
}   t_win;

//so_long.c
int     ft_check_map(char *str);
void    map_error(t_win *win);

//maps.c
char    **ft_read_map(char *str);

//window.c
void    game_window(t_win *win);
void    get_img(t_win *win);
void    put_img(t_win *win, void *img, int x, int y);

//check_map.c
int check_errors(char **mapstr, t_map *map, t_win *win);
int check_walls(t_win win);
int check_map_size(char **mapstr, t_map *map);
int check_letters(char **mapstr, t_map *map);

//path_find.c
int path_find(t_win *win, char **mapstr);
int get_path(t_win *win, char **mapstr, int y, int x);

//draw.c
void    draw_img(t_win *win);

//hooks.c
int read_key(int keycode, t_win *win);
int exit_game(t_win *win);
void    free_map(char **mapstr);

#endif