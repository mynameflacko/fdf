/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:57:13 by fjenisch          #+#    #+#             */
/*   Updated: 2023/10/13 00:17:43 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*src_cst;
	unsigned char		*dst_cst;
	size_t				i;

	if (!dst && !src)
		return (dst);
	src_cst = (const unsigned char *)src;
	dst_cst = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		dst_cst[i] = src_cst[i];
		i++;
	}
	return (dst);
}
/* int	main()
{
	char	src[10] = "12345";
	char	dest[10] = {0};

	memcpy(dest, src, 5);
	printf("%s\n", dest);

	ft_memcpy(dest, src, 5);
	printf("%s\n", dest);

	memcpy(((void *)0), ((void *)0), 0);
	printf("%s\n", dest);

	memcpy(NULL, NULL, 3);
	printf("%s\n", dest);

	ft_memcpy(NULL, NULL, 0);
	printf("%s\n", dest);

	return(0);
} */
