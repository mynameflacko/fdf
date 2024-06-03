/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:30:33 by fjenisch          #+#    #+#             */
/*   Updated: 2023/10/17 11:56:24 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_mem_save;
	size_t	sub_length;
	size_t	count;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	sub_length = ft_strlen(&s[start]);
	if (sub_length < len)
		len = sub_length;
	sub_mem_save = (char *)malloc((len + 1) * sizeof(*s));
	if (!sub_mem_save)
		return (NULL);
	count = 0;
	while (count < len)
	{
		sub_mem_save[count] = s[start + count];
		count++;
	}
	sub_mem_save[count] = '\0';
	return (sub_mem_save);
}

/* int	main()
{
	char	str[] = "hola";
	char	*sub_str;

	sub_str = ft_substr(str, 0, );
	printf("%s", sub_str);
	free(sub_str);
	return (0);
} */
