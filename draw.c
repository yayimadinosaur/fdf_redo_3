/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 11:25:28 by wfung             #+#    #+#             */
/*   Updated: 2017/07/09 19:46:26 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_right(void *mlx, void *win, t_env *e, t_fdfstore *store)
{
	int		i;
	int		j;
	int		sum_x;
	int		sum_y;
	int		gap;

	i = 0;
//	sum_x = e->start_x + (e->h_gap * i);
//	sum_y = e->start_y + (e->w_gap * j);
//	printf("sum_x = %i sum_y = %i\n", sum_x, sum_y);
	while (i < store->row) //&& sum_x < e->end_x)
	{
		j = 0;
		while (j < store->col) //&& sum_y < e->end_y)
		{
			gap = e->w_gap;
			while (gap > -1)
			{
				sum_x = e->start_x + (e->h_gap * i);
				sum_y = e->start_y + (e->w_gap * j);
				if (sum_x + gap >= e->end_x - 1)
					break;
				mlx_pixel_put(mlx, win, sum_x + gap, sum_y, 0xff00);	//green
			//	printf("gap[%i]sum_x[%i]", gap, sum_x);
				gap--;
			}
			j++;
		}
		printf("right sum_x %i sum_y %i\n", sum_x, sum_y);
		i++;
	}
}


static void	draw_down(void *mlx, void *win, t_env *e, t_fdfstore *store)
{
	int		i;
	int		j;
	int		sum_x;
	int		sum_y;
	int		gap;

	i = 0;
//	sum_x = e->start_x + (e->h_gap * i);
//	sum_y = e->start_y + (e->w_gap * j);
//	printf("sum_x = %i sum_y = %i\n", sum_x, sum_y);
	while (i < store->row) //&& sum_x < e->end_x)
	{
		j = 0;
		while (j < store->col) //&& sum_y < e->end_y)
		{
			gap = e->h_gap;
			while (gap > -1)
			{
				sum_x = e->start_x + (e->h_gap * i);
				sum_y = e->start_y + (e->w_gap * j);
				if (sum_y + gap >= e->end_y - 1)
					break;
				mlx_pixel_put(mlx, win, sum_x, sum_y + gap, 0xff0000);	//red
			//	printf("gap[%i]sum_x[%i]", gap, sum_x);
				gap--;
			}
		printf("down sum_x %i sum_y %i\n", sum_x, sum_y);
			j++;
		}
		printf("down sum_x %i sum_y %i\n", sum_x, sum_y);
		i++;
	}
}

void		draw(void *mlx, void *win, t_env *e, t_fdfstore *store)
{
	draw_right(mlx, win, e, store);	//doesnt draw a straight line
	draw_down(mlx, win, e, store);	//over draws
}
