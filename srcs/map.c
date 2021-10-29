/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dunstan <dunstan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:28:14 by drohanne          #+#    #+#             */
/*   Updated: 2021/10/29 23:28:26 by dunstan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*init_map(char *argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		ft_exit();
	get_heght_width(&map, argv);
	return (map);
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
