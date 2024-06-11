/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:01:23 by fjenisch          #+#    #+#             */
/*   Updated: 2024/06/11 20:33:37 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char **argv)
{
	if (argc != 2) // Implementiere noch die Logik, dass nur files mit .fdf valid sind
	{
		return (0);
	}
	else
	{
		int fd;

		fd = open(argv[1], O_RDONLY);
		printf("%s\n", get_next_line(fd));
	}
	return(0);
}
