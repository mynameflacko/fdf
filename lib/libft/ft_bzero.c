/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:26:19 by fjenisch          #+#    #+#             */
/*   Updated: 2023/10/12 13:26:17 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			count;
	unsigned char	*str;

	str = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		str[count] = 0;
		count++;
	}
}

/* int	main()
{
	char	str[] = "Hello this is very nice";

	ft_bzero(str, 5);
	printf("%s", str);
	return (0);
} */
