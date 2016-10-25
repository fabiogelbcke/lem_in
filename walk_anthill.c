/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_anthill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 17:51:30 by fschuber          #+#    #+#             */
/*   Updated: 2016/10/25 19:28:37 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			get_smallest_distance(t_node **graph, int *queue)
{
	int		i;
	int		smaller;
	int		distance;

	i = 0;
	smaller = -1;
	distance = 99999;
	while (queue[i] != -1)
	{
		if (graph[queue[i]]->distance < distance)
		{
			distance = graph[queue[i]]->distance;
			smaller = i;
		}
		i++;
	}
	return (smaller);
}

int			dijkstra(t_node **graph, t_ant *ant, int start, int target)
{
	int		*queue;
	int		i;
	int		j;

	i = -1;
	if (ant->position == target)
		return (-1);
	queue = malloc(sizeof(int) * (ft_nodearrlen(graph) + 1));
	while (++i < ft_nodearrlen(graph))
		queue[i] = i;
	queue[i] = -1;
	set_up_graph(graph, start, target);
	while (queue[0] != -1)
	{
		i = get_smallest_distance(graph, queue);
		j = queue[i];
		remove_from_queue(&queue, j);
		i = 0;
		while (graph[j]->connections[i] != -1)
		{
			if (graph[j]->distance + graph[graph[j]->connections[i]]->weight
				< graph[graph[j]->connections[i]]->distance)
			{
				graph[graph[j]->connections[i]]->prev = j;
				(graph[graph[j]->connections[i]]->distance =
				graph[j]->distance + graph[graph[j]->connections[i]]->weight);
			}
			i++;
		}
	}
	i = target;
	while (graph[i]->prev != start)
		i = graph[i]->prev;
	return (i);
}

void		reset_weights(t_node **graph, t_ant **ants)
{
	int		i;

	i = 0;
	while (graph[i])
	{
		graph[i]->weight = 1;
		i++;
	}
	i = 0;
	while (ants[i])
	{
		graph[ants[i]->position]->weight++;
		i++;
	}
}

void		move_ant(t_ant *ant, t_node **graph)
{
	int		pos;

	pos = dijkstra(graph, ant, ant->position, get_startend(graph, 2));
	if (pos < 0)
		return ;
	if (pos >= 0 && (graph[pos]->weight == 1 || pos == get_startend(graph, 2)))
	{
		graph[ant->position]->weight--;
		ant->position = pos;
		graph[pos]->weight++;
		ft_putstr("L");
		ft_putnbr(ant->number + 1);
		ft_putstr("-");
		ft_putstr(graph[pos]->name);
		ft_putstr(" ");
	}
	else
		graph[pos]->weight++;
}

void		walk_anthill(t_ant **ants, t_node **graph)
{
	int		start;
	int		i;

	start = get_startend(graph, 1);
	while (!are_ants_in_finish(ants, get_startend(graph, 2)))
	{
		i = 0;
		reset_weights(graph, ants);
		while (ants[i])
		{
			move_ant(ants[i], graph);
			i++;
		}
		ft_putstr("\n");
	}
}
