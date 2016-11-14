/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 18:21:25 by fschuber          #+#    #+#             */
/*   Updated: 2016/11/14 18:53:21 by fschuber         ###   ########.fr       */
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

int			is_path(char *str, char **nodes)
{
	int		i;
	int		j;

	i = 0;
	while (nodes[i])
	{
		j = 0;
		if (ft_strstr(str, nodes[i]))
		{
			if (str == ft_strstr(str, nodes[i]))
			{
				if (str[ft_strlen(nodes[i])] == '-')
					while (nodes[j])
					{
						if (!ft_strcmp(&str[ft_strlen(nodes[i]) + 1], nodes[j])
							&& ft_strcmp(nodes[j], nodes[i]))
							return (1);
						j++;
					}
			}
		}
		i++;
	}
	return (0);
}
