# include "lem_in.h"

t_ant		*create_ants(char *no_of_ants_str)
{
	int		i;
	t_ant		*ants;
	int		no_of_ants;
	
	if (no_of_ants_str && ft_isnbr(no_of_ants_str))
	{
		no_of_ants = ft_atoi(no_of_ants_str);
		ants = (t_ant*)malloc(sizeof(t_ant) * (no_of_ants + 1));
		for (i = 0; i < no_of_ants; i++)
		{
			ants[i].number = i;
			ants[i].position = 0;
		}
		return (ants);
	}
	perror("Number of ants is not valid or nonexistant");
	exit(1);
}

int             ft_arrlen(char **arr)
{
	int         i;
	
	i = 0;
	while (arr[i])
		i++;
	return(i);
}

int		alloc_graph(char **map, t_node ***graphptr)
{
	char        *no_of_nodes;
	t_node      **graph;
	int         i;
	int	    j;
	
	i = 1;
	j = 1;
	graph = *graphptr;
	while (map[i])
	{
		if (map[i][0] != '#' &&
		    ft_arrlen(ft_strsplit(map[i], ' ')) != 3) // check if are numbers
			break;
		if (map[i][0] != '#')
			j++;
		i++;
	}
	graph = (t_node**)malloc(sizeof(t_node*) * j);
	graph[j] = NULL;
	return (j - 1);
}

t_node **init_nodes(t_node ***graphptr, char **map, int no_nodes)
{
	t_node	**graph;
	int	i;
	int	j;
	int	startend;

	startend = 0;
	graph = *graphptr;
	j = 1;
	for (i = 0; i < no_nodes; i++)
	{
		if (map[j][0] == '#')
		{

			if (!ft_strcmp(map[j], "##start"))
				startend = 1;
			else if (!ft_strcmp(map[j], "##end"))
				startend = 2;
			i--;
			j++;
			continue;
		}
		graph[i] = (t_node*)malloc(sizeof(t_node));
		graph[i]->name = ft_strsplit(map[j++], ' ')[0];
		graph[i]->startend = startend;
		startend = 0;
	}
	for (i = 0; i < no_nodes; i++)
	{
		ft_putstr(graph[i]->name);
		ft_putstr(" -> ");
		ft_putnbr(graph[i]->startend);
		ft_putchar('\n');
	}
	return (graph);
}

t_node  **read_graph(char **map)
{
	t_node      **graph;
	int         no_nodes;
	int		is_start_finish;
	
	is_start_finish = 0;
	no_nodes = alloc_graph(map, &graph);
	graph = init_nodes(&graph, map, no_nodes);
	return NULL;
}

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
	//ants = create_ants(argv[1]);
	return (0);
}
    
