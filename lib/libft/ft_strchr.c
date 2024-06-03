/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:45:55 by fjenisch          #+#    #+#             */
/*   Updated: 2023/10/17 10:18:36 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

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

/* int	main()
{
	char	str[] = "/255";
	char	c;

	c = 'e';
	printf("%s\n", ft_strchr(str, c));
	printf("%p\n", ft_strchr(str, c));
	printf("%s\n", strchr(str, c));
	printf("%p\n", strchr(str, c));
	return (0);
} */
