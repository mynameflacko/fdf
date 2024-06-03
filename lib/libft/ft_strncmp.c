/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:27:07 by fjenisch          #+#    #+#             */
/*   Updated: 2023/10/12 20:58:44 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_cst;
	unsigned char	*s2_cst;
	size_t			count;

	s1_cst = (unsigned char *)s1;
	s2_cst = (unsigned char *)s2;
	count = 0;
	while (count < n && (*s1_cst || *s2_cst))
	{
		if (*s1_cst > *s2_cst)
		{
			return (*s1_cst - *s2_cst);
		}
		else if (*s1_cst < *s2_cst)
		{
			return (*s1_cst - *s2_cst);
		}
		s1_cst++;
		s2_cst++;
		count++;
	}
	return (0);
}
/* int	main()
{
	char	str1[] = "test\0";
	char	str2[] = "test\200";
	size_t	len;

	len = 10;
	printf("%d\n", ft_strncmp(str1, str2, len));
	printf("%d", strncmp(str1, str2, len));
	return (0);
} */
