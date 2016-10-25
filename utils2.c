/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 19:05:03 by fschuber          #+#    #+#             */
/*   Updated: 2016/10/25 19:06:40 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		add_connection(t_node **graph, char *node1, char *node2)
{
	int		i;
	int		j;
	int		k;

	i = indexofnode(graph, node1);
	j = indexofnode(graph, node2);
	k = 0;
	while (graph[i]->connections[k] != -1)
		k++;
	graph[i]->connections[k] = j;
	k = 0;
	while (graph[j]->connections[k] != -1)
		k++;
	graph[j]->connections[k] = i;
}

void		add_connections(t_node **graph, char **map)
{
	int		i;
	char	**nodes;

	i = 0;
	while (map[i] && (map[i][0] == '#'
		|| ft_arrlen(ft_strsplit(map[i], ' ')) == 3))
		i++;
	if (!map[i])
		error();
	while (map[i])
	{
		nodes = ft_strsplit(map[i], '-');
		if (is_path(map[i])
			&& ft_arrlen(nodes) == 2
			&& indexofnode(graph, nodes[0]) != -1
			&& indexofnode(graph, nodes[1]) != -1)
		{
			add_connection(graph, nodes[0], nodes[1]);
		}
		i++;
	}
}

t_node		**read_graph(char **map)
{
	t_node	**graph;
	int		no_nodes;
	int		is_start_finish;
	int		i;
	int		j;

	is_start_finish = 0;
	no_nodes = alloc_graph(map, &graph);
	init_nodes(&graph, map, no_nodes);
	add_connections(graph, map);
	return (graph);
}

int			get_startend(t_node **graph, int startend)
{
	int		i;

	i = 0;
	while (graph[i])
	{
		if (graph[i]->startend == startend)
			return (i);
		i++;
	}
	error();
	return (0);
}

void		remove_from_queue(int **queueptr, int index)
{
	int		i;
	int		*queue;
	int		j;

	i = 0;
	j = -1;
	queue = *queueptr;
	while (queue[i] != -1)
	{
		if (queue[i] == index)
			j = i;
		i++;
	}
	if (j != -1)
	{
		queue[j] = queue[i - 1];
		queue[i - 1] = -1;
	}
}
