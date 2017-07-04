/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 17:16:42 by wfung             #+#    #+#             */
/*   Updated: 2017/07/03 20:03:38 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void array_int(char **result_str, int n, int *array)
{
	int		i;

	i = 0;
	while (i < n)
	{
		array[i] = ft_atoi(result_str[i]);
		printf("array[%i] = %i\n", i, array[i]);
		i++;
	}
	return ;
}

t_fdfstore	*create_struct(char **av)
{
	int			i;
	int			fd;
	char		*line;
	char		**result;
	t_fdfstore	*store;

	line = NULL;
	if (!(store = (t_fdfstore*)malloc(sizeof(t_fdfstore))))
		return (NULL);	//exit();	//learn how to use exit
	fd = open(av[1], O_RDONLY);
	if (!(store->store_split = (char**)malloc(sizeof(char*) * (store->col))))
		return (NULL);
	printf("start GNL create_struct\n");
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		result = ft_strsplit(line, ' ');
		array_int(result, store->col, store->array_int[i]);
		i++;
		//free(result);
		free(line);
	}
	close(fd);
	printf("end GNL create_struct\n");
	return (store);
}

//need to close(fd) if mallocs fail, and need to remove malloced stuff
