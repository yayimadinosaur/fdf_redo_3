/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 15:13:44 by wfung             #+#    #+#             */
/*   Updated: 2017/07/05 15:28:41 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		save_values(char **av, t_fdfstore *store)
{
	int		i;
	int		fd;
	char	*line;
	char	**buff;
	int		**array;

	if (!(array = (int**)malloc(sizeof(int*) * (store->row))))
		return (0);
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		buff = ft_strsplit(line);
		while (i < store->col)
		{
			store->array_int[i] = ft_atoi(buff[i]);
			i++;
		}
		while (i > 0)
		{
			free(buff[i]);
			i--;
		}
		free(buff);
	}
	close(fd);
	return (1);
}