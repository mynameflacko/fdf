/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:50:14 by fjenisch          #+#    #+#             */
/*   Updated: 2023/10/12 19:52:39 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	result;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= (-1);
		write(fd, "-", 1);
	}
	if (n / 10)
		ft_putnbr_fd(n / 10, fd);
	result = n % 10 + 48;
	write(fd, &result, 1);
}
/* int main()
{
	int	nbr;
	int	fd;

	nbr = -57;
	fd = 1;
	ft_putnbr_fd(nbr, fd);
	return (0);
} */
