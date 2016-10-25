/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 18:21:25 by fschuber          #+#    #+#             */
/*   Updated: 2016/10/25 19:05:15 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		error(void)
{
	ft_putstr("ERROR\n");
	exit(1);
}

int			ft_arrlen(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int			ft_nodearrlen(t_node **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int			indexofnode(t_node **graph, char *name)
{
	int		i;

	i = 0;
	while (graph[i] && ft_strcmp(graph[i]->name, name))
	{
		i++;
	}
	if (!graph[i])
		return (-1);
	else
		return (i);
}

int			is_path(char *str)
{
	int		dashes;
	int		i;

	dashes = 0;
	i = 0;
	if (str[0] && str[0] == '#')
		return (1);
	if (ft_arrlen(ft_strsplit(str, '-')) != 2)
		return (0);
	while (str[i])
	{
		if (str[i] == '-')
			dashes++;
		i++;
	}
	if (dashes > 1)
		return (0);
	return (1);
}
