/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 18:21:00 by fschuber          #+#    #+#             */
/*   Updated: 2016/10/29 17:01:13 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			is_in_queue(int *queue, int index)
{
	int		i;

	i = 0;
	while (queue[i] != -1)
	{
		if (queue[i] == index)
			return (1);
		else
			i++;
	}
	return (0);
}

int			transverse_children(int **queueptr, int index, t_node **graph)
{
	int		*queue;
	int		j;
	int		is_reachable;

	queue = *queueptr;
	j = 0;
	is_reachable = 0;
	while (graph[index]->connections[j] != -1)
	{
		if (is_in_queue(queue, graph[index]->connections[j]))
		{
			remove_from_queue(queueptr, graph[index]->connections[j]);
			if (graph[graph[index]->connections[j]]->startend == 2)
				return (1);
			is_reachable += transverse_children(queueptr,
					graph[index]->connections[j], graph);
		}
		j++;
	}
	return (is_reachable);
}

int			is_reachable(t_node **graph)
{
	int		i;
	int		*queue;
	int		j;
	int		is_reachable;

	i = -1;
	is_reachable = 0;
	queue = malloc(sizeof(int) * (ft_nodearrlen(graph) + 1));
	while (++i < ft_nodearrlen(graph))
		queue[i] = i;
	queue[i] = -1;
	i = get_startend(graph, 1);
	j = 0;
	while (graph[i]->connections[j] != -1)
	{
		remove_from_queue(&queue, graph[i]->connections[j]);
		if (graph[graph[i]->connections[j]]->startend == 2)
			return (1);
		is_reachable += transverse_children(&queue,
				graph[i]->connections[j], graph);
		j++;
	}
	return (is_reachable);
}

void		check_endpoints(char **map)
{
	int		i;
	int		starts;
	int		ends;

	i = 0;
	starts = 0;
	ends = 0;
	while (map[i])
	{
		if (!ft_strcmp(map[i], "##start"))
			starts++;
		else if (!ft_strcmp(map[i], "##end"))
			ends++;
		i++;
	}
	if (starts != 1 || ends != 1)
		error();
}

int			main(int argc, char **argv)
{
	t_node	**graph;
	t_ant	**ants;
	int		i;
	char	*str;
	char	**map;

	str = malloc(sizeof(char) * 100001);
	read(0, str, 100000);
	map = ft_strsplit(str, '\n');
	map[error_index(str)] = NULL;
	graph = read_graph(map);
	check_endpoints(map);
	if (!is_reachable(graph))
		error();
	ants = create_ants(map[0], get_startend(graph, 1));
	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
	walk_anthill(ants, graph);
	return (0);
}
