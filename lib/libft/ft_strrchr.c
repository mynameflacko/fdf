/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:45:55 by fjenisch          #+#    #+#             */
/*   Updated: 2023/10/17 10:23:25 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*location;

	location = (char *)s;
	while (*location)
		location++;
	if ((unsigned char)c == '\0')
		return (location);
	while (location >= s)
	{
		if (*location == (unsigned char)c)
			return (location);
		location--;
	}
	return (0);
}

/* int	main()
{
	char	str[] = "Hello";
	char	c;

	c = '\0';
	printf("%s", ft_strrchr(str, c));
	return (0);
} */
