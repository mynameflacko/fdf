/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:54:09 by fjenisch          #+#    #+#             */
/*   Updated: 2023/11/24 08:23:49 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
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
	char	*temp_line;
	char	**leftover;
	char	*line;
	char	*result;
}	t_gnl;

char	*get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_realloc(t_gnl *gnl);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *s1);

#endif
