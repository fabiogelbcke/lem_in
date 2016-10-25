/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 18:21:08 by fschuber          #+#    #+#             */
/*   Updated: 2016/10/25 22:11:41 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant		**create_ants(char *no_of_ants_str, int start)
{
	int		i;
	t_ant	**ants;
	int		no_of_ants;

	if (no_of_ants_str && ft_isnbr(no_of_ants_str))
	{
		no_of_ants = ft_atoi(no_of_ants_str);
		if (no_of_ants <= 0)
			error();
		ants = (t_ant**)malloc(sizeof(t_ant*) * (no_of_ants + 1));
		i = 0;
		while (i < no_of_ants)
		{
			ants[i] = malloc(sizeof(t_ant));
			ants[i]->number = i;
			ants[i]->position = start;
			i++;
		}
		ants[i] = NULL;
		return (ants);
	}
	error();
	return (NULL);
}

int			alloc_graph(char **map, t_node ***graphptr)
{
	char	*no_of_nodes;
	t_node	**graph;
	int		i;
	int		j;

	i = 1;
	j = 0;
	graph = *graphptr;
	while (map[i])
	{
		if (map[i][0] != '#' &&
			ft_arrlen(ft_strsplit(map[i], ' ')) != 3)
			break ;
		if (map[i][0] != '#')
			j++;
		i++;
	}
	graph = (t_node**)malloc(sizeof(t_node*) * (j + 1));
	graph[j] = NULL;
	return (j);
}

void		update_node_info(t_node **node, char *nodestr,
							int *startend, int no_nodes)
{
	int		k;

	k = -1;
	node[0] = (t_node*)malloc(sizeof(t_node));
	node[0]->name = ft_strsplit(nodestr, ' ')[0];
	node[0]->connections = (int*)malloc(sizeof(int) * (no_nodes));
	while (++k < no_nodes)
		node[0]->connections[k] = -1;
	node[0]->startend = *startend;
	node[0]->weight = 1;
	*startend = 0;
}

t_node		**init_nodes(t_node ***graphptr, char **map, int no_nodes)
{
	t_node	**graph;
	int		i;
	int		j;
	int		startend;
	int		k;

	startend = 0;
	graph = *graphptr;
	j = 1;
	i = 0;
	while (i < no_nodes)
		if (map[j][0] == '#')
		{
			if (!ft_strcmp(map[j++], "##start"))
				startend = 1;
			else if (!ft_strcmp(map[j - 1], "##end"))
				startend = 2;
		}
		else
			update_node_info(&graph[i++], map[j++], &startend, no_nodes);
	graph[i] = NULL;
	return (graph);
}

int			are_ants_in_finish(t_ant **ants, int finish)
{
	int		i;

	i = 0;
	while (ants[i])
	{
		if (ants[i]->position != finish)
			return (0);
		i++;
	}
	return (1);
}
