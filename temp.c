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
		if (ft_strlen(argv[i]) >= 2 && argv[i][0] == '#' && argv[i][1] == '#')
		{
			if (!ft_strcmp(ft_strsubfrom(argv[i], 2), "start") && start == 0)
				start = 1;
			else if (!ft_strcmp(ft_strsubfrom(argv[i], 2), "end") && end == 0)
				end = 1;
			else
			{
				ft_putstr("Invalid start or end policy");
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
	m}
	ft_putstr("valid");
	return nodes;
}
