# include "lem_in.h"

int	is_path(char *str)
{
	int dashes;
	int i;

	dashes = 0;
	i = 0;
	if (str[0] && str[0] == '#')
		return (1);
	if (ft_arrlen(ft_strsplit(str, '-')) != 2)
		return (0);
	while (str[i])
	{
		if(str[i] == '-')
			dashes++;
		i++;
	}
	if (dashes > 1)
		return (0);
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
	int	j;

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
	int	is_reachable;

	queue = *queueptr;
	j = 0;
	is_reachable = 0;
	while(graph[index]->connections[j] != -1)
	{

		if (is_in_queue(queue, graph[index]->connections[j]))
		{
			remove_from_queue(queueptr, graph[index]->connections[j]);
			if (graph[graph[index]->connections[j]]->startend == 2)
				return 1;
			is_reachable += transverse_children(queueptr, graph[index]->connections[j], graph);
		}
		j++;
	}
	return is_reachable;;
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

int	two_newlines_index(char *str)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] =='\n')
		{
			j++;
			if (str[i + 1] && str[i + 1] == '\n')
				return (j);
		}
		i++;
	}
	return (j);
}

int	is_node(char *str)
{
	int spaces;
	int i;

	spaces = 0;
	i = 0;
	if (str[0] && str[0] == '#')
		return (1);
	if (str[0] && str[0] == 'L')
		return (0);
	if (ft_arrlen(ft_strsplit(str, ' ')) != 3)
		return (0);
	if (!ft_isnbr(ft_strsplit(str, ' ')[1])
	    ||!ft_isnbr(ft_strsplit(str, ' ')[2]))
		return (0);
	while (str[i])
	{
		if(str[i] == ' ')
			spaces++;
		i++;
	}
	if (spaces > 2)
		return (0);
	return (1);
}

int node_exists(char *path, char **names)
{
	int i;
	int exist;
	char *node1;
	char *node2;

	i = 0;
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

int	error_index(char *str)
{
	char **map;
	int index;
	int i;
	char **names;

	i = 1;
	map = ft_strsplit(str, '\n');
	index = two_newlines_index(str);
	names = (char**)ft_memalloc(ft_strlen(str));
	while (map[i] && is_node(map[i]))
	{
		names[i - 1] = ft_strdup(ft_strsplit(map[i], ' ')[0]);
		i++;
	}
	if (!map[i] || !is_path(map[i]))
		index = (index < i) ? index : i;
	while (map[i] && is_path(map[i]) && node_exists(map[i], names))
		i++;
	index = (index < i) ? index : i;
	return (index);
}

void	check_endpoints(char **map)
{
	int i;
	int starts;
	int ends;

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
 
int     main(int argc, char **argv)
{
	t_node **graph;
	t_ant **ants;
	int i;
	char *str;
	char **map;
	int j;
	
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
    
