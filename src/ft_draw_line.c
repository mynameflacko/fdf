/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:22:01 by fjenisch          #+#    #+#             */
/*   Updated: 2024/06/11 20:42:09 by fjenisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_draw_line(int start[2], int end[2])
{
	int	d;
	int	dx;
	int	dy;

	d = 0;
	dx = 0;
	dy = 0;

	while (start[0] != end[0])
	{
		dx = end[0] - start[0];
		dy = end[1] - start[1];
		d = 2 * dy - dx;
		if (d < 0)
			start[0] = start[0] + 1;
		else
		{
			start[1] = start[1] + 1;
			start[0] = start[0] + 1;
		}
		d = d + 2 * (dy - dx);
		printf("%d", start[0]);
		printf("%d, %s", start[1], "\n");
	}
}



/* int	main(void)
{
	int start[] = {0, 0};
	int end[] = {5, 3};

	ft_draw_line(start, end);
	return (0);
} */
