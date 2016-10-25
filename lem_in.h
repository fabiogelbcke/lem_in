/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 19:30:37 by fschuber          #+#    #+#             */
/*   Updated: 2016/10/25 19:34:45 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/Includes/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_node
{
	char			*name;
	int				*connections;
	int				distance;
	int				startend;
	int				weight;
	int				prev;
}					t_node;

typedef struct		s_ant
{
	int				number;
	int				position;
}					t_ant;

void				error();
int					ft_arrlen(char **arr);
int					ft_nodearrlen(t_node **arr);
int					indexofnode(t_node **graph, char *name);
t_ant				**create_ants(char *no_of_ants_str, int start);
int					alloc_graph(char **map, t_node ***graphptr);
t_node				**init_nodes(t_node ***graphptr, char **map, int no_nodes);
void				walk_anthill(t_ant **ants, t_node **graph);
int					get_startend(t_node **graph, int startend);
void				remove_from_queue(int **queueptr, int index);
int					dijkstra(t_node **graph, t_ant *ant, int start, int target);
int					are_ants_in_finish(t_ant **ants, int finish);
int					is_path(char *str);
void				add_connection(t_node **graph, char *node1, char *node2);
void				add_connections(t_node **graph, char **map);
t_node				**read_graph(char **map);
int					get_startend(t_node **graph, int startend);
void				remove_from_queue(int **queueptr, int index);
int					error_index(char *str);
void				set_up_graph(t_node **graph, int start, int end);

#endif
