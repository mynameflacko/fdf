/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:01:23 by fjenisch          #+#    #+#             */
/*   Updated: 2024/06/14 22:11:07 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <string.h>

void	ft_process_map(int fd)
{
	char	*end;

	while(true)
	{
		end = get_next_line(fd);
		if(end)
		{
			printf("%s", end);
		}
		else
			break;
	}
	close(fd);
}

int		ft_valid_input(int argc, char **argv)
{
	char	*valid;
	int		str_len;
	int		fd;
	valid = ".fdf";

	str_len = ft_strlen(valid);
	if (argc != 2)
	{
		write(1, "Error: Argumentcount is not correct", 36);
		exit(1);
	}
	if (ft_strncmp(ft_substr(argv[1], ft_strlen(ft_strtrim(argv[1], valid)), str_len), valid, str_len) != 0)
	{
		write(1, "Error: File type is not correct", 32);
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error: File can not be opened", 30);
		exit(1);
	}
	return (fd);
}

int	main(int argc, char **argv)
{
	int fd;

	fd = ft_valid_input(argc, argv);
	ft_process_map(fd);
	return(0);
}
