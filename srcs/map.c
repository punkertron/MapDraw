/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dunstan <dunstan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:28:14 by drohanne          #+#    #+#             */
/*   Updated: 2021/11/03 00:24:47 by dunstan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/includes/libft.h"

void	map_fill(char **line, t_map **map, int i)
{
	char	**split;
	int		a;

	a = 0;
	split = ft_split(*line, ' ');
	if (split[0] == NULL)
		exit(1);
	if ((*map)->width == -1)
	{
		while (split[a])
			a++;
		(*map)->width = a;
	}
	fill_map(split, map, i);
	free_split(split);
	free(*line);
}

void	default_map(t_map **map)
{
	(*map)->shift_x = 500;
	(*map)->shift_y = 150;
	(*map)->angle = 0.523599;
}

void	free_split(char **split)
{
	int	a;

	a = 0;
	while (split[a])
	{
		free(split[a]);
		a++;
	}
	free(split[a]);
	free(split);
}

void	fill_map(char **split, t_map **map, int i)
{
	int	a;

	(*map)->cord[i] = malloc(sizeof(int) * (*map)->width);
	if ((*map)->cord[i] == NULL)
		ft_exit();
	a = 0;
	while (a < (*map)->width)
	{
		(*map)->cord[i][a] = ft_atoi((const char *)split[a]);
		a++;
	}
}

void	free_map(t_map **map)
{
	int	a;

	a = 0;
	while (a < (*map)->height)
	{
		free((*map)->cord[a]);
		a++;
	}
	free((*map)->cord);
	free(*map);
}
