/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 13:29:37 by wfung             #+#    #+#             */
/*   Updated: 2017/06/27 20:04:47 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	int		fd;

	if (ac == 1)
		ft_putstr("Please include a .fdf file\n");
	if (ac == 2)
	{
	//	fd = open(av[1], O_RDONLY);
		if (parse_fdf(av[1], &av) == 1)
		{
			ft_putstr(".fdf filename pass!\n");
	/*		if (create_grid(av[1]) == 0)
				//free(grid?
			else
				if (store_pts(av[1]) == 0)
					//free stored_pts
				else
					draw_fdf();	//initialize mlx + loop
	*/	}
		else
			ft_putstr(".fdf file invalid\n");
	}
	close(fd);
	return (0);
}
