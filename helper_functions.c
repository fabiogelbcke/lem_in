#include "lem_in.h"

void		error()
{
	ft_putstr("ERROR\n");
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

int		ft_nodearrlen(t_node **arr)
{
	int         i;
	
	i = 0;
	while (arr[i])
		i++;
	return(i);
}

int		indexofnode(t_node **graph, char *name)
{
	int i;

	i = 0;
	/*ft_putstr(graph[i]->name);
	ft_putstr("  ");
	ft_putstr(name);
	ft_putstr("\n");*/
	while (graph[i] && ft_strcmp(graph[i]->name, name))
	{
		/*ft_putstr(graph[i]->name);
		ft_putstr("  ");
		ft_putstr(name);
		ft_putstr("\n");*/
		i++;
	}
	if (!graph[i])
		return (-1);
	else
		return (i);
}
