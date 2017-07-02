/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 13:29:37 by wfung             #+#    #+#             */
/*   Updated: 2017/07/01 17:43:00 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_fdfstore	*store;
	if (ac == 1)
		ft_putstr("Please include a .fdf file\n");
	if (ac == 2)
	{
	//	fd = open(av[1], O_RDONLY);
		if (parse_fdf(av[1], av) == 1)
		{
			ft_putstr(".fdf parsing filename + file contents  pass!\n");
	/*		if (create_grid(av[1]) == 0)
				//free(grid?
			else
				if (store_pts(av[1]) == 0)
					//free stored_pts
				else
					draw_fdf();	//initialize mlx + loop
	*/	store = create_struct(av[1], av);
		}
		else
			ft_putstr(".fdf file invalid\n");
	}
	return (0);
}
