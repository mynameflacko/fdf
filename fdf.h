#ifndef FDF_H
# define FDF_H

# include "./lib/libft/libft.h"
# include "./lib/get_next_line/get_next_line.h"
# include "./lib/MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/**
 * @brief
 * @param
 *
 */
typedef struct matrix_t
{
	int*		xaxis;
	int*		yaxis;
	int*		altitude;
}	matrix_s;

typedef struct valid_map_t
{
	int		str_len;
	char	*valid;
	int		fd;
	
}	valid_map;

#endif
