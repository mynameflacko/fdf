/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:54:17 by fjenisch          #+#    #+#             */
/*   Updated: 2023/11/23 10:27:37 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*src_cst;
	unsigned char		*dst_cst;
	size_t				i;

	if (!dst && !src)
		return (dst);
	src_cst = (const unsigned char *)src;
	dst_cst = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		dst_cst[i] = src_cst[i];
		i++;
	}
	return (dst);
}

void	*ft_realloc(t_gnl *gnl)
{
	void	*new_ptr;
	size_t	size_of_copy;

	if (gnl->to_allocate == 0)
		return (NULL);
	new_ptr = malloc(sizeof(char) * gnl->to_allocate);
	if (!new_ptr)
		return (NULL);
	size_of_copy = 0;
	if (gnl->line != NULL)
	{
		if (gnl->to_allocate > gnl->total_count)
			size_of_copy = gnl->total_count;
		else
			size_of_copy = gnl->to_allocate - 1;
		ft_memcpy(new_ptr, gnl->line, size_of_copy + 1);
		free(gnl->line);
	}
	return (new_ptr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	char	*start;
	size_t	count;

	count = 0;
	while (s1[count] != '\0')
		count++;
	ptr = (char *)malloc((count + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	start = ptr;
	while (*s1 != '\0')
	{
		*ptr = *s1;
		ptr++;
		s1++;
	}
	*ptr = '\0';
	return (start);
}
