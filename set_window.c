/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 19:44:06 by wfung             #+#    #+#             */
/*   Updated: 2017/07/07 19:55:22 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env	*set_window(int n, t_fdfstore *store)
{
	t_env	*e;

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
	e->draw_x_max = n - (n / 10); //10% end 
	e->draw_y_max = n - (n / 10);
	e->h_gap = (n - (e->start_x * 2)) / (store->col - 1);
	e->w_gap = (n - (e->start_y * 2)) / (store->col - 1);
//	e->mlx = mlx_init();
//	e->win = mlx_new_window(e->mlx, e->win_x, e->win_y, "42");
	return (e);
}
