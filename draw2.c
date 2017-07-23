/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 14:12:21 by wfung             #+#    #+#             */
/*   Updated: 2017/07/22 18:57:35 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_right(void *mlx, void *win, t_env *e, t_fdfstore *store)	//right
{
	int		i;
	int		j;
	float	gap;

	i = 0;
	while (i < store->row)
	{
		j = 0;
		while (j < store->col)
		{
			gap = 0;
			while (gap <= e->gap1 && e->pts[i][j].x_stop + gap <= e->max_x)
			{
				mlx_pixel_put(mlx, win, e->pts[i][j].x_stop + gap, e->pts[i][j].y_stop, 0xff00);	//green
				gap++;
			}
			j++;
		}
		i++;
	}
	printf("draw right chk %f\n", e->max_x);
}

void		draw_down(void *mlx, void *win, t_env *e, t_fdfstore *store)	//down
{
	int		i;
	int		j;
	float	gap;

	i = 0;
	while (i < store->row)
	{
		j = 0;
		while (j < store->col)
		{
			gap = 0;
			while (gap <= e->gap1 && e->pts[i][j].y_stop + gap <= e->max_y + 1)
			{
				mlx_pixel_put(mlx, win, e->pts[i][j].x_stop, e->pts[i][j].y_stop + gap, 0xff0000);	//red
				gap++;
			}
			printf("i %i j %i gap %f\n", i, j, gap);
			j++;
		}
		i++;
	}
}
void		draw2(void *mlx, void *win, t_env *e, t_fdfstore *store)
{
	draw_right(mlx, win, e, store);
	draw_down(mlx, win, e, store);
}

