#ifndef FT_LS_H
# define FT_LS_H

# include "libft/Includes/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct  s_node
{
	char	*name;
	int     *connections;
	int	distance_to_end;
	int	startend;
    
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
t_ant		**create_ants(char *no_of_ants_str);
int		alloc_graph(char **map, t_node ***graphptr);
t_node		**init_nodes(t_node ***graphptr, char **map, int no_nodes);
void		walk_anthill(t_ant *ants, t_node **graph)

#endif
