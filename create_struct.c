/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 17:16:42 by wfung             #+#    #+#             */
/*   Updated: 2017/07/01 19:46:06 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdfstore	*create_struct(char **av)
{
	int			i;
	int			j;
	int			fd;
	char		*line;
	t_fdfstore	*store;

	i = 0;
	line = NULL;
	if (!(store = (t_fdfstore*)malloc(sizeof(t_fdfstore))))
		return (NULL);	//exit();	//learn how to use exit
	if (!(store->array_int = (int**)malloc(sizeof(int*) * (store->row))))
		return (NULL);	//exit();		//is this correct?
	fd = open(av[1], O_RDONLY);
	printf("start GNL create_struct\n");
	while (get_next_line(fd, &line) == 1)
	{
		j = 0;
		printf("inside GNL %i\n", j);
		if (!(store->array_int[i] = (int*)malloc(sizeof(int) * (1))))
			return (NULL);
		while (j < store->col)
		{
			store->array_int[i][j] = ft_atoi(line);		//not sure if can use atoi this way
			printf("array_int[%i] [%i]\n", i, store->array_int[i][j]);
			j++;
		}
		i++;
		free(line);
	}
	close(fd);
	printf("end GNL create_struct\n");
	return (store);
}

//need to close(fd) if mallocs fail, and need to remove malloced stuff
