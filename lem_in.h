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
#endif
