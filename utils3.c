/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 19:19:36 by fschuber          #+#    #+#             */
/*   Updated: 2016/11/14 18:50:43 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			two_newlines_index(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			j++;
			if (str[i + 1] && str[i + 1] == '\n')
				return (j);
		}
		i++;
	}
	if (i > 0 && str[i - 1] != '\n')
		j++;
	return (j);
}

int			is_node(char *str)
{
	int		spaces;
	int		i;

	spaces = 0;
	i = 0;
	if (str[0] && str[0] == '#')
		return (1);
	if (str[0] && str[0] == 'L')
		return (0);
	if (ft_arrlen(ft_strsplit(str, ' ')) != 3)
		return (0);
	if (!ft_isnbr(ft_strsplit(str, ' ')[1])
		|| !ft_isnbr(ft_strsplit(str, ' ')[2]))
		return (0);
	while (str[i])
	{
		if (str[i] == ' ')
			spaces++;
		i++;
	}
	if (spaces > 2)
		return (0);
	return (1);
}

int			node_exists(char *path, char **names)
{
	int		i;
	int		exist;
	char	*node1;
	char	*node2;

	i = 0;
	if (path[0] == '#')
	{
		if (!ft_strcmp(path, "##start") || !ft_strcmp(path, "##end"))
			return (0);
		else
			return (1);
	}
	node1 = ft_strsplit(path, '-')[0];
	node2 = ft_strsplit(path, '-')[1];
	exist = 0;
	while (names[i])
	{
		if (!ft_strcmp(node1, names[i])
			|| !ft_strcmp(node2, names[i]))
			exist++;
		i++;
	}
	return (exist == 2);
}

int			error_index(char *str)
{
	char	**map;
	int		index;
	int		i;
	char	**names;

	i = 1;
	map = ft_strsplit(str, '\n');
	index = two_newlines_index(str);
	names = (char**)ft_memalloc(ft_strlen(str));
	while (map[i] && is_node(map[i]))
	{
		if (is_in(names, ft_strdup(ft_strsplit(map[i], ' ')[0])))
			index = (index < i) ? index : i;
		names[i - 1] = ft_strdup(ft_strsplit(map[i], ' ')[0]);
		i++;
	}
	if (!map[i] || (!is_path(map[i], names) && map[i][0] != '#'))
		index = (index < i) ? index : i;
	while (map[i] && (is_path(map[i], names) || map[i][0] == '#'))
		i++;
	index = (index < i) ? index : i;
	return (index);
}

void		set_up_graph(t_node **graph, int start, int end)
{
	int		i;

	i = 0;
	while (graph[i])
	{
		graph[i]->distance = 9999;
		if (i == start)
			graph[i]->distance = 0;
		graph[i]->prev = -1;
		i++;
	}
}
