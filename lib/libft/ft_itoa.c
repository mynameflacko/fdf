/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:46:50 by fjenisch          #+#    #+#             */
/*   Updated: 2023/10/12 17:56:38 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_negative(long *temp_n)
{
	int	is_negative;

	is_negative = 0;
	if (*temp_n < 0)
	{
		*temp_n *= (-1);
		is_negative = 1;
	}
	return (is_negative);
}

static int	count_length(long temp_n)
{
	int	len;

	len = 0;
	if (temp_n == 0)
	{
		len = 1;
		return (len);
	}
	while (temp_n)
	{
		temp_n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		negative_count;
	long	temp_n;
	char	*result;
	int		total_len;

	temp_n = (long)n;
	negative_count = is_negative(&temp_n);
	len = count_length(temp_n);
	if (negative_count != 0)
		len += negative_count;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	total_len = len - 1;
	while (total_len >= 0)
	{
		result[total_len--] = (temp_n % 10) + 48;
		temp_n /= 10;
	}
	result[len] = '\0';
	if (negative_count != 0)
		result[0] = '-';
	return (result);
}

/* int	main()
{
	int	n;

	n = 0;
	printf("%s", ft_itoa(n));
	return (0);
} */
