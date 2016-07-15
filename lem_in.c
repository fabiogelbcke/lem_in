# include "lem_in.h"

t_ant		*create_ants(char *no_of_ants_str)
{
	int		i;
	t_ant		*ants;
	int		no_of_ants;
	
	if (no_of_ants_str && ft_isnbr(no_of_ants_str))
	{
		no_of_ants = ft_atoi(no_of_ants_str);
		ants = (t_ant*)malloc(sizeof(t_ant) * (no_of_ants + 1));
		for (i = 0; i < no_of_ants; i++)
		{
			ants[i].number = i;
			ants[i].position = 0;
		}
		return (ants);
	}
	perror("Number of ants is not valid or nonexistant");
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

t_node          **alloc_graph(char **argv)
{
	char        *no_of_nodes;
	t_node      **graph;
	int         i;
	
	i = 0;
	while (1)
	{
		if (argv[i][0] != '#' &&
		    ft_arrlen(ft_strsplit(argv[i], ' ')) != 3) //check if are numbers
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
	int		is_start_finish;
	
	is_start_finish = 0;
	//graph = alloc_graph(argc, argv);
	for (i = 2; i < argc; i++)
	{
		if (argv[i][0] != '#' &&
		    ft_arrlen(ft_strsplit(argv[i], ' ')) != 3) 
			break;
		
	}
}

int is_path(char *str)
{
	char **split;

	split = ft_strsplit(str, '-');
	if (ft_arrlen(split) != 2)
		return (0);
	else if (!ft_isnbr(split[0]) || !ft_isnbr(split[1]))
		return (0);
	else
		return (1);
}

int	check_input(int argc, char **argv)
{
	int	nodes;
	int	i;
	int	start;
	int	end;
	
	nodes = 0;
	start = 0;
	end = 0;
	if (!ft_isnbr(argv[0]))
	{
		perror("invalid number of ants");
		exit(1);
	}
	for (i = 1; i < ft_arrlen(argv); i++)
	{
		ft_putnbr(i);
		ft_putstr("A");
		if (ft_strlen(argv[i]) >= 2 && argv[i][0] == '#' && argv[i][1] == '#')
		{
			ft_putstr("B");
			if (!ft_strcmp(ft_strsubfrom(argv[i], 2), "start") && start == 0)
				start = 1;
			else if (!ft_strcmp(ft_strsubfrom(argv[i], 2), "end") && end == 0)
				end = 1;
			else
			{
				ft_putstr(&argv[0][2]);//)"Invalid start or end policy");
				ft_putstr("op");
				exit(0);
			}
		}
		else if (ft_isnbrspaces(argv[i]))// && ft_arrlen(ft_strsplit(argv[i], ' ')) == 3)
		{ //TODO: VERIFICAR SE SAO 3 NUMEROS
			ft_putstr("C");
			nodes++;
		}
		else if (argv[i][0] != '#' && !is_path(argv[i]))
		{
			ft_putstr("D");
			perror("invalid input");
			exit(1);
		}
		ft_putstr("\n");
	}
	ft_putstr("valid");
	return nodes;
}

int     main(int argc, char **argv)
{
	t_node **graph;
	t_ant *ants;
	int no_of_nodes;
	char *str;
	char **map;
	
	str = malloc(sizeof(char) * 10001);
	read(0, str, 10000);
	map = ft_strsplit(str, '\n');
	no_of_nodes = check_input(argc, map);
	//graph = read_graph(argc, argv);
	//ants = create_ants(argv[1]);
	return (0);
}
    
