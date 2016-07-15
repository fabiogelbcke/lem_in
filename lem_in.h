#ifndef FT_LS_H
# define FT_LS_H

# include "libft/Includes/libft.h"
# include <stdlib.h>

typedef struct  s_node
{
    int         number;
    int         *connections;
    int         distance_to_end;
}               t_node;

typedef struct  s_ant
{
    int         number;
    int         position;
}               t_ant;
#endif
