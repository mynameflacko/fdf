/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:56:59 by fjenisch          #+#    #+#             */
/*   Updated: 2023/10/12 23:39:58 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
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

/* int	main()
{
	char	str[] = "Hello";
	char	*dup_str;

	dup_str = ft_strdup(str);
	printf("%s", dup_str);
	free(dup_str);
	return (0);
} */
