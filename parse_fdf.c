/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:46:05 by wfung             #+#    #+#             */
/*   Updated: 2017/06/30 14:25:09 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		count_num_str(char *str, int n, char stop)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i] != stop)
	{
		if (str[i] >= '0' && str[i] <= '9' &&
				(str[i + 1] == ' ' || str[i + 1] == n
				 || str[i + 1] == stop))
		{
			printf("str[i] count = %c %i\n", str[i], i);
			count++;
		}
		printf("[%c]", str[i]);
		i++;
	}
	printf("count == %i\n", count);
	return (count);
}

/*	not sure if needed if count_num_str is used instead
static int		count_chr_str(char *str, int n, char stop)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i] != stop)
	{
		if (str[i] == (char)n && str[i + 1] != (char)n)
			count++;
		i++;
	}
	return (count);
}
*/

static int		parse_file(char **av)
{
	int		row;
	int		col;
	int		fd;
	char	*buff;

	row = 0;
	col = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &buff) == 1)
	{
		if (row == 0)
			row = count_num_str(buff, '\n', '\0');
		else
		{
			if (row != count_num_str(buff, '\n', '\0'))
			{
				close(fd);
				free(buff);
				ft_putstr("Invalid file contents\n");
				return (0);
			}
		}
		free(buff);
		col++;
		printf("\n");
	}
	if (row < 2 || col < 2)
	{
		ft_putstr("Invalid file contents\n");
		return (-1);
	}
	printf("row = %i\n", row);
	printf("col = %i\n", col);
	close(fd);
	return (1);
}

static int		parse_filename(char *str)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	if (i < 4)
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
	if (parse_filename(str) != 1)
	{
		ft_putstr(".fdf filename invalid\n");
		return (0);
	}
	if (parse_file(av) != 1)
	{
		ft_putstr(".fdf file contents invalid\n");
		return (0);
	}
	printf("pass both\n");
	return (1);
}
