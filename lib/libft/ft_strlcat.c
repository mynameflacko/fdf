/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:37:57 by fjenisch          #+#    #+#             */
/*   Updated: 2023/10/12 19:32:41 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		dst_len;
	size_t		src_len;
	size_t		i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	if (dst_len > dstsize)
		return (src_len + dstsize);
	i = dst_len;
	while (*src && i < dstsize - 1)
		dst[i++] = *(src++);
	dst[i] = '\0';
	return (dst_len + src_len);
}

/* int	main()
{
	char	dst[15] = "rrrrrrrrrrrrrrr";

	printf("%zu\n", ft_strlcat(dst, "lorem ipsum dolor sit amet", 5));
	printf("%s\n", dst);
	printf("%zu\n", strlcat(dst, "lorem ipsum dolor sit amet", 5));
	printf("%s", dst);
	return (0);
} */
