#ifndef FT_LS_H
# define FT_LS_H

# include "libft/Includes/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct  s_node
{
	char	*name;
	int     *connections;
	int	distance;
	int	startend;
	int	weight;
	int	prev;    
}               t_node;

typedef struct  s_ant
{
    int         number;
    int         position;
}               t_ant;

void		error();
int             ft_arrlen(char **arr);
int             ft_nodearrlen(t_node **arr);
int		indexofnode(t_node **graph, char *name);
t_ant		**create_ants(char *no_of_ants_str, int start);
int		alloc_graph(char **map, t_node ***graphptr);
t_node		**init_nodes(t_node ***graphptr, char **map, int no_nodes);
void		walk_anthill(t_ant **ants, t_node **graph);
int		get_startend(t_node **graph, int startend);
void		remove_from_queue(int **queueptr, int index);
void	dijkstra(t_node **graph, t_ant *ant, int start, int target);

#endif
