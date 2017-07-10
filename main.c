/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 13:29:37 by wfung             #+#    #+#             */
/*   Updated: 2017/07/09 19:34:30 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_fdfstore	*store;
	t_env		*e;

	store = NULL;
	if (ac == 1)
		ft_putstr("Please include a .fdf file\n");
	if (ac == 2)
	{
		if (!(store = create_struct1()))//not sure if [if] is needed
			return (0);				//should display malloc fail msg?
		if (parse_fdf(av[1], av, store) == 1)
		{
			ft_putstr(".fdf parsing filename + file contents  pass!\n");
			if (save_values(av, store) != 1)
				ft_putstr("save_values malloc failed\n");
			print_array_int(store->array_int, store);	//testing array_int
			if (!(e = set_window(600, store)))
				return (-1);	//notsure if proper return 
			e->mlx = mlx_init();
			e->win = mlx_new_window(e->mlx, e->win_x, e->win_y, "42");
			printf("win_x %i win_y %i cent_x %i cent_y %i start_x %i start_y %i end_x %i end_y %i h_gap %i w_gap %i\n", e->win_x, e->win_y, e->center_x, e->center_y, e->start_x, e->start_y, e->end_x, e->end_y, e->h_gap, e->w_gap);
			printf("mlx looping\n");
			draw(e->mlx, e->win, e, store);
			mlx_loop(e->mlx);
		}
		else
		{
			free(store);
			ft_putstr(".fdf file invalid\n");
		}
	}
	return (0);
}

	/*	fdf flow?
	 *
	 * if (create_grid(av[1]) == 0)
				//free(grid?
			else
				if (store_pts(av[1]) == 0)
					//free stored_pts
				else
					draw_fdf();	//initialize mlx + loop
	*/
