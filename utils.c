# include "lem_in.h"

t_ant		**create_ants(char *no_of_ants_str)
{
	int		i;
	t_ant		**ants;
	int		no_of_ants;
	
	if (no_of_ants_str && ft_isnbr(no_of_ants_str))
	{
		no_of_ants = ft_atoi(no_of_ants_str);
		ants = (t_ant**)malloc(sizeof(t_ant*) * (no_of_ants + 1));
		for (i = 0; i < no_of_ants; i++)
		{
			ants[i] = malloc(sizeof(t_ant));
			ants[i]->number = i;
			ants[i]->position = 0;
		}
		ants[i] = NULL;
		return (ants);
	}
	error();
}



int		alloc_graph(char **map, t_node ***graphptr)
{
	char        *no_of_nodes;
	t_node      **graph;
	int         i;
	int	    j;
	
	i = 1;
	j = 0;
	graph = *graphptr;
	while (map[i])
	{
		if (map[i][0] != '#' &&
		    ft_arrlen(ft_strsplit(map[i], ' ')) != 3) // check if coords are numbers 
			break;
		if (map[i][0] != '#')
			j++;
		i++;
	}
	graph = (t_node**)malloc(sizeof(t_node*) * (j + 1));
	graph[j] = NULL;
	return (j);
}

t_node **init_nodes(t_node ***graphptr, char **map, int no_nodes)
{
	t_node	**graph;
	int	i;
	int	j;
	int	startend;
	int	k;

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
		}
		else
		{
			graph[i] = (t_node*)malloc(sizeof(t_node));
			graph[i]->name = ft_strsplit(map[j++], ' ')[0];
			graph[i]->connections = (int*)malloc(sizeof(int) * (no_nodes - 1));
			for (k = 0; k < no_nodes - 2; k++)
				graph[i]->connections[k] = -1;
			graph[i]->startend = startend;
			startend = 0;
		}
	}
	return (graph);
}
