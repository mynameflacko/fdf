/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:54:09 by fjenisch          #+#    #+#             */
/*   Updated: 2024/06/11 20:07:02 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_gnl
{
	int		bytes_read;
	int		to_allocate;
	int		total_count;
	int		i;
	char	*line;
	char	*temp_line;
	char	**leftover;
	char	*result;
}	t_gnl;

char	*get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_realloc(t_gnl *gnl);
char	*ft_strchr(const char *s, int c);
char	*ft_strduplicate(char *s1);

#endif
