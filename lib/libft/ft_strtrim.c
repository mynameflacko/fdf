/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:02:37 by fjenisch          #+#    #+#             */
/*   Updated: 2023/10/13 01:07:05 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	ft_isinset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_copy;
	char	*end;
	size_t	len;

	end = (char *)s1;
	while (*s1 && ft_isinset(*s1, set))
		s1++;
	while (*end)
		end++;
	end -= 1;
	while (end >= s1 && ft_isinset(*end, set))
		end--;
	len = end - s1 + 1;
	str_copy = (char *)malloc(len + 1);
	if (!str_copy)
		return (NULL);
	str_copy = ft_memcpy(str_copy, s1, len);
	str_copy[len] = '\0';
	return (str_copy);
}

/* int	main()
{
	char	str[] = "         ";
	char	set[] = " ";
	char	*ptr;

	ft_strtrim(str, set);
	printf("%s\n", ptr);
	return (0);
} */
