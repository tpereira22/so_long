/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:19:48 by timartin          #+#    #+#             */
/*   Updated: 2022/11/09 17:19:50 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

char    **ft_read_map(char *str)
{
    int fd;
    char **fullmap;
    char *temp_map;
    char *temp;
    char *line;

    fd = open(str, O_RDONLY);
    if (fd == -1)
        return (NULL);
    temp_map = malloc(sizeof(char));
    temp_map[0] = '\0';
    while ((line = get_next_line(fd)))
    {
        temp = temp_map;
        temp_map = ft_strjoin(temp_map, line);
        free(line);
        free(temp);
    
    }
    fullmap = ft_split(temp_map, '\n');
    free(temp_map);
    close(fd);
    return (fullmap);
}