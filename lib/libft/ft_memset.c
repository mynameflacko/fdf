/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:00:20 by fjenisch          #+#    #+#             */
/*   Updated: 2023/10/12 13:28:57 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			count;
	unsigned char	*str;

	str = (unsigned char *)b;
	count = 0;
	while (count < len)
	{
		str[count] = c;
		count++;
	}
	return (str);
}

/* int	main()
{
	char	str[] = "Hello this is very nice";

	printf("%s", ft_memset(str, '-', 5));
	return (0);
} */
