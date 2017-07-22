/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 14:12:21 by wfung             #+#    #+#             */
/*   Updated: 2017/07/20 17:08:55 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
void		draw_down(void *mlx, void *win, t_env *e, t_fdfstore *store)
{
	int		i;
	int		j;
	float	gap;

	i = 0;
	printf("\n\n\nDstore->row = %istore->col = %i\n\n\n", store->row, store->col);

	while (i < store->row - 1)
	{
		j = 0;
		while (j < store->col - 1)
		{
			gap = 0;
			while (gap < e->gap1 + 1)
			{
				if (e->pts[i][j].y_stop + gap > e->pts[i][j+1].y_stop + 1)
				{
					printf("D chk stop %f next %f\n", e->pts[i][j].y_stop + gap, e->pts[i][j+1].y_stop);
					break;
				}
				mlx_pixel_put(mlx, win, e->pts[i][j].x_stop, e->pts[i][j].y_stop + gap, 0xff0000);//red
				//printf("x%fy%f\n", e->pts[i][j].x_stop, e->pts[i][j].y_stop + gap);
				gap++;
			}
			printf("gapD[%i][%i] total = %f\n", i,j,gap + e->pts[i][j].x_stop);
			j++;
		}
		i++;
	}
	printf("\n\n\nD row%icol%i\n\n\n", store->row, store->col);
}

void		draw_right(void *mlx, void *win, t_env *e, t_fdfstore *store)
{
	int		i;
	int		j;
	float	gap;

	i = 0;
	printf("\n\n\nRstore->row = %istore->col = %i\n\n\n", store->row, store->col);
	while (i < store->row)
	{
		j = 0;
		while (j < store->col)
		{
			gap = 0;
			while (gap < e->gap1 + 1)
			{
				if (e->pts[i][j].x_stop + gap > e->pts[i][j+1].x_stop + 1)
				{
					printf("D chk stop %f next %f\n", e->pts[i][j].x_stop + gap, e->pts[i][j+1].x_stop);
					break;
				}
				mlx_pixel_put(mlx, win, e->pts[i][j].x_stop + gap, e->pts[i][j].y_stop, 0xff00);//green
			//	printf("x%fy%f\n", e->pts[i][j].x_stop + gap, e->pts[i][j].y_stop);
				gap++;
			}
			printf("gapR[%i][%i] total = %f\n", i, j, gap + e->pts[i][j].x_stop);
			j++;
		}
		i++;
	}
	printf("\nR row%icol%i\nend i %i j %i", store->row, store->col, i, j);
}
*/

void		draw_right(void *mlx, void *win, t_env *e, t_fdfstore *store)
{
	int		i;
	int		j;
	float	gap;
	float	gap_lim;
	float	x;
	float	y;
	float	x0 = 0;
	float	x1 = 240;
	float	x2 = 480;
	float	y0 = 0;
	float	y1 = 240;
	float	y2 = 480;

	i = 0;
	printf("blah %f\n", e->pts[i][0].x_stop);
	printf("start draw right\n");
	while (i < store->row)
	{
		j = 0;
		if (i == 0)
		{
			y = y0;
		}
		else if (i == 1)
		{
			y = y1;
		}
		else if (i == 2)
		{
			y = y2;
		}
		while (j < store->col)
		{
			if (j == 0)
				x = x0;
			else if (j == 1)
				x = x1;
			else if (j == 2)
				x = x2;
			gap = x;
			gap_lim = x + 240;
			printf("gap_lim = %f y = %f\n", gap_lim, y);
			while (gap < gap_lim)
			{
				mlx_pixel_put(mlx, win, x + gap, y, 0xff00);//green 
				gap++;
			}
			printf("drawright j = %i\n", j);
			j++;
		}
		i++;
printf("drawright i = %i\n", i);
	}
}

void		draw1(void *mlx, void *win, t_env *e, t_fdfstore *store)
{
	draw_right(mlx, win, e, store);	//doesnt draw a straight line
//	draw_down(mlx, win, e, store);	//over draws
}

