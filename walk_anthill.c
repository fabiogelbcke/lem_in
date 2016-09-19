
#include "lem_in.h"

void	set_up_graph(t_node **graph, int start, int end)
{
	int i;

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

int get_smallest_distance(t_node **graph, int *queue)
{
	int i;
	int smaller;
	int distance;

	i = 0;
	smaller = -1;
	distance = 9999;
	while (queue[i] != -1)
	{
		//ft_putnbr(i);
		if (graph[queue[i]]->distance < distance)
		{
			distance = graph[queue[i]]->distance;
			smaller = i;
		}
		i++;
	}
	return smaller;
}

void	dijkstra(t_node **graph, t_ant *ant, int start, int target)
{
	int	*queue;
	int	i;
	int	j;

	i = -1;
	queue = malloc(sizeof(int) * (ft_nodearrlen(graph) + 1));
	while (++i < ft_nodearrlen(graph))
		queue[i] = i;
	queue[i] = -1;
	set_up_graph(graph, start, target);
	while (queue[0] != -1)
	{
		i = 0;
		j = get_smallest_distance(graph, queue);
		//ft_putstr("depois");
		j = queue[j];
		remove_from_queue(&queue, j);
		while (graph[j]->connections[i] != -1)
		{
			if (graph[j]->distance + graph[graph[j]->connections[i]]->weight <= graph[graph[j]->connections[i]]->distance)
			{
				graph[graph[j]->connections[i]]->prev = j;
				graph[graph[j]->connections[i]]->distance = graph[j]->distance + graph[graph[j]->connections[i]]->weight;
			}
			i++;
		}
	}
	i = target;
	graph[graph[i]->prev]->weight++;
	while (graph[i]->prev != -1)
	{
		ft_putstr(graph[i]->name);
		ft_putchar('\n');
		i = graph[i]->prev;
	}
	ft_putstr(graph[i]->name);
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putchar('\n');
}

void	walk_anthill(t_ant **ants, t_node **graph)
{
	int start;
	int i;

	start = get_startend(graph, 1);
	i = 0;
}

