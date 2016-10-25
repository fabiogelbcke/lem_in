/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 22:30:42 by fschuber          #+#    #+#             */
/*   Updated: 2016/10/25 22:31:17 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			*create_queue(int start, int target, t_node **graph)
{
	int		*queue;
	int		i;

	i = -1;
	queue = malloc(sizeof(int) * (ft_nodearrlen(graph) + 1));
	while (++i <= ft_nodearrlen(graph))
		queue[i] = (i == ft_nodearrlen(graph)) ? -1 : i;
	set_up_graph(graph, start, target);
	return (queue);
}
