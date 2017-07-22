/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 11:25:28 by wfung             #+#    #+#             */
/*   Updated: 2017/07/18 14:06:18 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
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
			gap = 0;
		//	sum_x = e->start_x + (e->h_gap * i);
		//	sum_y = e->start_y + (e->w_gap * j);
		//	printf("right s_x = %i s_y = %i w_gap = %i", sum_x, sum_y, e->w_gap);
			sum_x = e->start_x + (e->gap1 * i);
			sum_y = e->start_y + (e->gap1 * j);
			//while (gap < e->w_gap + 1 && sum_x + gap <= e->end_x)
			while (gap < e->gap1 && sum_x + gap <= e->pts[i][j].x_stop)
			{	
				mlx_pixel_put(mlx, win, sum_x + gap, sum_y, 0xff00);	//green
			//	printf("g[%i] g_x%i", gap, sum_x+gap);
				gap++;
			}
		//	printf("\ni = %i j = %i\n", i, j);
			j++;
		}
//		printf("right sum_x %i sum_y %i\n", sum_x, sum_y);
		i++;
	}
}
*/
/*	//copy of top
static void	draw_down(void *mlx, void *win, t_env *e, t_fdfstore *store)
{
	int		i;
	int		j;
	int		sum_x;
	int		sum_y;
	int		gap;

	i = 0;
	while (i < store->row) //&& sum_x < e->end_x)
	{
		j = 0;
		while (j < store->col) //&& sum_y < e->end_y)
		{
			gap = 0;
			sum_y = e->start_y + (e->gap1 * i);
			sum_x = e->start_x + (e->gap1 * j);
			while (gap < e->gap1 && sum_y + gap <= e->pts[i][j].y_stop)
			{	
				mlx_pixel_put(mlx, win, sum_x, sum_y + gap, 0xff0000);	//red
				gap++;
				printf("[%i][%i]sum_x[%i]sum_y[%i]gap[%i]y_stop[%f]\n",i, j, sum_x, sum_y, gap, e->pts[i][j].y_stop);
			}
			j++;
		}
		i++;
	}
}
*/
static void	draw_right(void *mlx, void *win, t_env *e, t_fdfstore *store)
{
	int		i;
	int		j;
	int		gap;

	i = 0;
	while (i < store->row) //&& sum_x < e->end_x)
	{
		j = 0;
		while (j < store->col) //&& sum_y < e->end_y)
		{
			gap = 0;
			while (gap < e->gap1)
			{
				if (e->pts[i][j].y_stop > e->end_y + 1 || e->pts[i][j].x_stop + gap > e->end_x + 1)
					break;
				mlx_pixel_put(mlx, win, e->pts[i][j].x_stop + gap, e->pts[i][j].y_stop, 0xff00);//green
				gap++;
			}
			j++;
		}
		i++;
	}
}
static void	draw_down(void *mlx, void *win, t_env *e, t_fdfstore *store)
{
	int		i;
	int		j;
	float	gap;

	i = 0;
	while (i < store->row) //&& sum_x < e->end_x)
	{
		j = 0;
		while (j < store->col) //&& sum_y < e->end_y)
		{
			gap = 0;
			printf("[i = %i][j = %i]x_stop = %fy_stop = %f\n", i, j, e->pts[i][j].x_stop, e->pts[i][j].y_stop);
			while (gap < e->gap1)
			{
				if (e->pts[i][j].x_stop > e->end_x + 1 || e->pts[i][j].y_stop + gap > e->end_y + 1)
					break;
				mlx_pixel_put(mlx, win, e->pts[i][j].x_stop, e->pts[i][j].y_stop + gap, 0xff0000);//red
				gap++;
			}
			printf("total = x %f y %f\n", e->pts[i][j].x_stop, e->pts[i][j].y_stop + gap);
			j++;
		}
		i++;
	}
}
void		draw(void *mlx, void *win, t_env *e, t_fdfstore *store)
{
	draw_right(mlx, win, e, store);	//doesnt draw a straight line
	draw_down(mlx, win, e, store);	//over draws
}
