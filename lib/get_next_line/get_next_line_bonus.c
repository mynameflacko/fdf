/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:59:00 by fjenisch          #+#    #+#             */
/*   Updated: 2023/11/24 12:25:26 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_check_leftover(t_gnl *gnl, int fd)
{
	char		*temp_leftover;
	char		*new_leftover;

	temp_leftover = ft_strchr(gnl->leftover[fd], '\n');
	if (temp_leftover)
	{
		while (gnl->leftover[fd][gnl->total_count] != '\n'
		&& gnl->leftover[fd][gnl->total_count] != '\0')
			(gnl->line)[(gnl->total_count)++]
				= gnl->leftover[fd][gnl->total_count];
		if (gnl->leftover[fd][gnl->total_count] == '\n')
			gnl->line[(gnl->total_count)++] = '\n';
		gnl->line[gnl->total_count] = '\0';
		new_leftover = ft_strdup(temp_leftover + 1);
		free(gnl->leftover[fd]);
		gnl->leftover[fd] = new_leftover;
		return (0);
	}
	while (gnl->leftover[fd][gnl->total_count] != '\0')
		(gnl->line)[(gnl->total_count)++] = gnl->leftover[fd][gnl->total_count];
	(gnl->line)[gnl->total_count] = '\0';
	free(gnl->leftover[fd]);
	gnl->leftover[fd] = NULL;
	return (1);
}

static char	*ft_process_line(t_gnl *gnl, char *buf, int fd)
{
	gnl->i = 0;
	while (gnl->i < gnl->bytes_read)
	{
		if (gnl->total_count >= gnl->to_allocate - 1)
		{
			gnl->to_allocate *= 2;
			gnl->temp_line = ft_realloc(gnl);
			if (!gnl->temp_line)
			{
				free(gnl->line);
				return (NULL);
			}
			gnl->line = gnl->temp_line;
		}
		gnl->line[gnl->total_count] = buf[(gnl->i)++];
		if (gnl->line[gnl->total_count] == '\n')
		{
			gnl->leftover[fd] = ft_strdup(&buf[gnl->i]);
			if (gnl->total_count + 1 < gnl->to_allocate)
				gnl->line[gnl->total_count + 1] = '\0';
			return (gnl->line);
		}
		gnl->total_count++;
	}
	return (NULL);
}

static char	*ft_return_line(t_gnl *gnl, char *buf, int fd)
{
	char	*result;

	while (gnl->bytes_read > 0)
	{
		gnl->bytes_read = read(fd, buf, BUFFER_SIZE);
		if ((gnl->bytes_read == 0 && gnl->total_count == 0)
			|| gnl->bytes_read < 0)
		{
			free(gnl->line);
			if (gnl->leftover[fd])
			{
				free(gnl->leftover[fd]);
				gnl->leftover[fd] = NULL;
			}
			return (NULL);
		}
		buf[gnl->bytes_read] = '\0';
		result = ft_process_line(gnl, buf, fd);
		if (result || gnl->bytes_read == 0)
			return (result);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	t_gnl		gnl;
	char		buf[BUFFER_SIZE + 1];
	static char	*leftover[1024];

	gnl.leftover = leftover;
	gnl.total_count = 0;
	gnl.to_allocate = BUFFER_SIZE + 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	gnl.line = malloc(sizeof(char) * gnl.to_allocate);
	if (!gnl.line)
		return (NULL);
	if (gnl.leftover[fd])
		if (!ft_check_leftover(&gnl, fd))
			return (gnl.line);
	gnl.bytes_read = 1;
	gnl.result = ft_return_line(&gnl, buf, fd);
	if (gnl.result)
		return (gnl.result);
	if (gnl.total_count > 0 && gnl.bytes_read == 0)
	{
		gnl.line[gnl.total_count] = '\0';
		return (gnl.line);
	}
	return (NULL);
}

/* int main()
{
	int fd;
	int fd1;

	fd = open("test.txt", O_RDONLY);
	fd1 = open("test_copy.txt", O_RDONLY);

	printf("%s\n", get_next_line(fd1));
 	printf("%s\n", get_next_line(fd));
 	printf("%s\n", get_next_line(fd1));
	printf("%s\n", get_next_line(fd));
 	printf("%s\n", get_next_line(fd1));
	printf("%s\n", get_next_line(fd));
	return (0);
} */
