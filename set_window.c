/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 19:44:06 by wfung             #+#    #+#             */
/*   Updated: 2017/07/11 18:54:36 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pts	**ft_setpts(t_fdfstore *store)
{
	t_pts	**pts;
	int		i;
	int		j;

	i = 0;
	if (!(pts = (**t_pts)malloc(sizeof(*t_pts) * (store->row))))
		return (NULL);
	while (i < store->row)
	{
		j = 0;
		while (j < store->col)
		{
			if (!(pts[i][j] = (*t_pts)malloc(sizeof(t_pts) * (store->col))))
				return (NULL);
			pts[i][j]->x = i;
			pts[i][j]->y = j;
			pts[i][j]->z = store->array_int[i][j];
			j++;
		}
		i++;
	}
	return (pts);
}

t_env	*set_window(int n, t_fdfstore *store)
{
	t_env	*e;
	t_pts	**pts;

	if (!(e = (t_env*)malloc(sizeof(t_env) * (1))))
		return (NULL);
	if (n < 0)
		ft_putstr("edow size needs to be positive\n");
	if (n == 0)
		ft_putstr("edow size needs to be > 0\n");
	e->win_x = n;
	e->win_y = n;
	e->center_x = n / 2;
	e->center_y = n / 2;
	e->start_x = n / 10;	//10% start
	e->start_y = n / 10;
	e->end_x = n - (n / 10); //10% end 
	e->end_y = n - (n / 10);
	e->h_gap = (n - (e->start_x * 2) - 1) / (store->row - 1);
	e->w_gap = (n - (e->start_y * 2) - 1) / (store->col - 1);
	e->gap1 = (e->h_gap >= e->w_gap ? e->h_gap : e->w_gap);
	e->pts = ft_setpts(store);
//	e->mlx = mlx_init();
//	e->win = mlx_new_window(e->mlx, e->win_x, e->win_y, "42");
	return (e);
}
