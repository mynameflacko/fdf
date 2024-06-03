/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:31:06 by fjenisch          #+#    #+#             */
/*   Updated: 2023/10/12 13:26:31 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*mem_location;
	unsigned char	*null_setter;
	size_t			total_size;
	size_t			counter;

	total_size = (count * size);
	mem_location = malloc(total_size);
	null_setter = (unsigned char *)mem_location;
	if (mem_location == NULL)
		return (NULL);
	counter = 0;
	while (counter < total_size)
	{
		null_setter[counter] = 0;
		counter++;
	}
	return (mem_location);
}

/* int	main()
{
	size_t	count;
	size_t	size;
	int	arr;

	count = 5;
	size = sizeof(int);
	arr = ft_calloc(count, size);
	free(arr);
	return (0);
} */
