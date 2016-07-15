# include "lem_in.h"

int             ft_arrlen(void *arr)
{
	int         i;
	
	i = 0;
	while (arr[i] != NULL)
		i++;
	return(i);
}

t_node          **alloc_graph(char **argv)
{
	char        *no_of_nodes;
	t_node      **graph;
	int         i;
    
	i = 0;
	while (true)
	{
		if (!argv[i][0] == '#' &&
			!ft_arrlen(ft_strsplit(argv[i], ' ')) == 3) //check if are numbers
			break;
		i++;
	}
	graph = (t_node**)malloc(sizeof(t_node*) * (i + 1));
	graph[i] = NULL;
	return (graph);
}

t_node  **read_graph(int argc, char **argv)
{
	t_node      **graph;
	int         i;
    
	graph = alloc_graph(argc, argv);
	for (i = 2; i < argc; i++)
	{
		if (!argv[i][0] == '#' &&
			!ft_arrlen(ft_strsplit(argv[i], ' ')) == 3) //check if are numbers
			
			}
}

int     main(int argc, char **argv)
{
	t_node **graph;
    
	graph = read_graph(argc, argv);
	return (0);
}
    
