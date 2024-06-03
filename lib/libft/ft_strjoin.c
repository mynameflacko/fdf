/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:30:36 by fjenisch          #+#    #+#             */
/*   Updated: 2023/10/12 13:44:14 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat_str;
	size_t	s1_length;
	size_t	s2_length;
	size_t	counter;
	size_t	counter2;

	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	concat_str = (char *)malloc(s1_length + s2_length + 1);
	if (!concat_str)
		return (NULL);
	counter = 0;
	while (counter < s1_length)
	{
		concat_str[counter] = s1[counter];
		counter++;
	}
	counter2 = 0;
	while (counter < s1_length + s2_length)
	{
		concat_str[counter++] = s2[counter2++];
	}
	concat_str[counter] = '\0';
	return (concat_str);
}

/* int main()
{
    char    str1[] = "Hello";
    char    str2[] = "12345";
    char    *joined_str = ft_strjoin(str1, str2);

    printf("%s\n", joined_str);
    free(joined_str);
    return (0);
} */
