/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 15:13:44 by wfung             #+#    #+#             */
/*   Updated: 2017/07/07 19:14:09 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//need to remove strsplit sections if malloc fails??
static t_fdfstore	*strsplit_store(char **av, t_fdfstore *store)
{
	int		i;
	int		j;
	int		fd;
	char	**buff;
	char	*line;

	fd = open(av[1], O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
	//	printf("line[%i] = [%s]\n", i, line);
		if (!(buff = ft_strsplit(line, ' ')))
			return (NULL);
		j = 0;
		while (j < store->col)
		{
			store->array_int[i][j] = ft_atoi(buff[j]);
		//	printf("buff[%i] = [%s] store->array_int[%i][%i] = [%i]\n", j, buff[j], i, j, store->array_int[i][j]);
		//	printf("j check = %i\n", j);
			free(buff[j]);
			buff[j] = NULL;
			j++;
		}
		free(buff);
		buff = NULL;
		free(line);
	//	printf("i = %i\n", i);
		i++;
	}
	close(fd);
	return (store);
}

int					save_values(char **av, t_fdfstore *store)
{
	int		i;

	i = 0;
	if (!(store->array_int = (int**)malloc(sizeof(int*) * (store->row))))
		return (0);
	while (i < store->col)
	{
		if (!(store->array_int[i] = (int*)malloc(sizeof(int) * (store->col))))
			//add free for this section
			return (0);
		i++;
	}
	if (!(strsplit_store(av, store)))
			return (0);
	return (1);
}
