/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 07:44:09 by fjenisch          #+#    #+#             */
/*   Updated: 2023/10/12 22:12:09 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count_haystack;
	size_t	count_needle;

	if (*needle == '\0')
		return ((char *)haystack);
	count_haystack = 0;
	while (haystack[count_haystack] != '\0' && count_haystack < len)
	{
		count_needle = 0;
		while ((count_needle + count_haystack) < len
			&& haystack[count_haystack + count_needle]
			&& needle[count_needle] == haystack[count_haystack + count_needle])
		{
			count_needle++;
		}
		if (!needle[count_needle])
			return ((char *)&haystack[count_haystack]);
		count_haystack++;
	}
	return (NULL);
}

/* int	main ()
{
	char	haystack[] = "Hello, my name is Felix";
	char	needle[] = "Felix";

	printf("%s", ft_strnstr(haystack, needle, sizeof(haystack)));
	return (0);
}
 */
