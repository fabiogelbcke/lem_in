# include "lem_in.h"

int is_path(char *str)
{
	char **split;

	split = ft_strsplit(str, '-');
	if (ft_arrlen(split) != 2)
		return (0);
	else if (!ft_isnbr(split[0]) || !ft_isnbr(split[1]))
		return (0);
	else
		return (1);
}

void	add_connection(t_node **graph, char *node1, char *node2)
{
	int i;
	int j;
	int k;

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

void	add_connections(t_node **graph, char **map)
{
	int i;
	char **nodes;

	i = 0;
	while (map[i] && (map[i][0] == '#' || ft_arrlen(ft_strsplit(map[i], ' ')) == 3))
		i++;
	if (!map[i])
		error();
	while (map[i])
	{

		nodes = ft_strsplit(map[i], '-');
		if (is_path(map[i]) && ft_arrlen(nodes) == 2 && indexofnode(graph, nodes[0]) != -1
			    && indexofnode(graph, nodes[1]) != -1)
		{
			add_connection(graph, nodes[0], nodes[1]);
		}
		i++;
	}
}



t_node  **read_graph(char **map)
{
	t_node      **graph;
	int         no_nodes;
	int		is_start_finish;
	int		i;
	int		j;
	
	is_start_finish = 0;
	no_nodes = alloc_graph(map, &graph);
	init_nodes(&graph, map, no_nodes);
	add_connections(graph, map);
	return graph;
}



int		get_startend(t_node **graph, int startend)
{
	int	i;

	i = 0;
	while (graph[i])
	{
		if (graph[i]->startend == startend)
			return i;
		i++;
	}
	error();
	return (0);
}

void		remove_from_queue(int **queueptr, int index)
{
	int	i;
	int	*queue;

	i = 0;
	queue = *queueptr;
	while (queue[i] != -1)
		i++;
	queue[index] = queue[i - 1];
	queue[i - 1] = -1;
}

int		is_in_queue(int	*queue, int index)
{
	int i;

	i = 0;
	while (queue[i] != -1)
	{
		if (queue[i] == index)
			return 1;
		else
			i++;
	}
	return (0);
}

int		transverse_children(int **queueptr, int index, t_node **graph)
{
	int	*queue;
	int	j;

	queue = *queueptr;
	j = 0;
	while(graph[index]->connections[j] != -1)
	{
		if (is_in_queue(queue, graph[index]->connections[j]))
		{
			remove_from_queue(queueptr, graph[index]->connections[j]);
			if (graph[graph[index]->connections[j]]->startend == 2)
				return 1;
			return transverse_children(queueptr, graph[index]->connections[j], graph);
		}
		j++;
	}
	return 0;
}

int		is_reachable(t_node **graph)
{
	int	i;
	int	*queue;
	int	j;
	int	is_reachable;

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
			return 1;
		is_reachable += transverse_children(&queue, graph[i]->connections[j], graph);
		j++;
	}
	return is_reachable;
}
 
int     main(int argc, char **argv)
{
	t_node **graph;
	t_ant *ants;
	int no_of_nodes;
	char *str;
	char **map;
	
	str = malloc(sizeof(char) * 10001);
	read(0, str, 10000);
	map = ft_strsplit(str, '\n');
	//no_of_nodes = check_input(argc, map);
	graph = read_graph(map);
	if (!is_reachable(graph))
		error();
	ants = create_ants(map[0]);
	return (0);
}
    
