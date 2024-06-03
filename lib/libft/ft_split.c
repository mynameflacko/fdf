/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:23:34 by fjenisch          #+#    #+#             */
/*   Updated: 2023/10/17 10:26:55 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_freemem(char **result_arr, int j)
{
	int	count;

	count = 0;
	while (count < j)
	{
		free(result_arr[count]);
		count++;
	}
	free(result_arr);
	return (NULL);
}

static int	words_length(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**result_arr;
	int		len;
	int		j;

	result_arr = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result_arr)
		return (NULL);
	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = words_length(s, c);
			result_arr[j] = (char *)malloc(len + 1);
			if (!result_arr[j])
				return (ft_freemem(result_arr, j));
			ft_strlcpy(result_arr[j], s, len + 1);
			j++;
			s += len;
		}
		else
			s++;
	}
	result_arr[j] = NULL;
	return (result_arr);
}

/* int	main()
{
	char	str[] = "12-12-12-12";
	char	c;
	char	**result;
	int i;

	c = '-';
	result = ft_split(str, c);
	i = 0;
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	free(result);
	return (0);
} */
