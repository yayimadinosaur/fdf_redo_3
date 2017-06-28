/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:46:05 by wfung             #+#    #+#             */
/*   Updated: 2017/06/27 20:05:06 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		count_chr(char *str)
{

}

static int		parse_file(char **av)
{
	int		row;
	int		col;
	int		fd;
	char	*buff;

	row = 0;
	col = 0;
	fd = 0;
	while (get_next_line(fd, &buff) == 1)
	{

	}
}

static int		parse_fn(char *str)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	if (i < 3)
		return (0);
	if (str[i] != 'f' && str[i - 1] != 'd' && str[i - 2] != 'f'
			&& str[i - 3] != '.')
		return (0);
	return (1);
}

int		parse_fdf(char *str, char **av)
{
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (parse_fn(str) != 1)
	{
		ft_putstr(".fdf filename invalid\n");
		return (0);
	}
	if (parse_file() != 1)
	{
		ft_putstr(".fdf file contents invalid\n");
		return (0);
	}
	return (1);
}
