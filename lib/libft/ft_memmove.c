/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:29:39 by fjenisch          #+#    #+#             */
/*   Updated: 2023/10/13 00:17:34 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*src_cst;
	unsigned char		*dst_cst;

	if (!dst && !src)
		return (dst);
	src_cst = (const unsigned char *)src;
	dst_cst = (unsigned char *)dst;
	if (dst_cst <= src_cst)
	{
		while (0 < len)
		{
			*(dst_cst++) = *(src_cst++);
			len--;
		}
	}
	dst_cst += len;
	src_cst += len;
	while (0 < len)
	{
		*(--dst_cst) = *(--src_cst);
		len--;
	}
	return (dst);
}

/* int	main()
{
	char	src[] = "Learningisfun";
	char	dst[] = "1234578910111213";

	ft_memmove(dst, src, 5);
	// memmove(dst, src, sizeof(src));
	printf("%s", dst);
	return(0);
} */
