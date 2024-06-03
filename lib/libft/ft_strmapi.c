/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:25:12 by fjenisch          #+#    #+#             */
/*   Updated: 2023/10/12 13:45:05 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* char	f(unsigned int i, char c)
{
	c -= 32;
	return (c);
} */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result_str;
	unsigned int	index;
	unsigned int	len;

	len = (unsigned int)ft_strlen(s);
	result_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!result_str)
		return (NULL);
	index = 0;
	while (s[index])
	{
		result_str[index] = f(index, s[index]);
		index++;
	}
	result_str[index] = '\0';
	return (result_str);
}
/* int	main()
{
	char	str[] = "hello";

	printf("%s", ft_strmapi(str, f));
	return (0);
} */
